
#include "../DirectoryServiceWin32.h"
#include "../FileTimeWin32.h"
#include "../../../Formatters/DateFormatter.h"
#include "../../../Collections/Set/Set.h"
#include <Windows.h>

using namespace easy;
using namespace fs;

void getDiskInfo(const Path& directoryPath, DataSize& freeSize, DataSize& totalSize) {
	auto str = directoryPath.absolute().asWString();

	ubig freeBytes;
	ubig totalBytes;
	ubig totalFreeBytes;

	auto result = GetDiskFreeSpaceExW(str.c_str(), (ULARGE_INTEGER*)&freeBytes, (ULARGE_INTEGER*)&totalBytes, (ULARGE_INTEGER*)&totalFreeBytes);

	freeSize = DataSize::fromBytes(freeBytes);
	totalSize = DataSize::fromBytes(totalBytes);
}

CString DirectoryServiceWin32::fileSystemSeparator() const {
	return CString("\\");
}

Path DirectoryServiceWin32::applicationDirectory() const {
	TCHAR path[MAX_PATH];
	memset(path, 0, sizeof(TCHAR) * MAX_PATH);

	GetModuleFileName(NULL, path, MAX_PATH);

	std::wstring str = std::wstring(path);

	Path exePath = Path::directoryFromAbsolutePath(str);
	
	return exePath.parentPath();
}

Path DirectoryServiceWin32::temporaryPathDirectory() const {
	CHAR path[MAX_PATH];
	memset(path, 0, sizeof(CHAR) * MAX_PATH);

	GetTempPathA(MAX_PATH, path);

	std::string str = std::string(path);

	return Path::directoryFromAbsolutePath(str);
}

Path DirectoryServiceWin32::temporaryPathFile(const CString& prefix) const {
	Path tempDir = temporaryPathDirectory();
	std::wstring tempDirStr = tempDir.absolute().asWString();
	std::wstring prefixStr = prefix.asWString();

	TCHAR newTempFileName[MAX_PATH];
	memset(newTempFileName, 0, sizeof(TCHAR) * MAX_PATH);

	auto result = GetTempFileNameW(tempDirStr.c_str(), prefixStr.c_str(), 0, newTempFileName);

	std::wstring resultStr = std::wstring(newTempFileName);

	return Path::fileFromAbsolutePath(resultStr);
}

CString DirectoryServiceWin32::absolutePathFrom(const CString& path) const {
	std::wstring fileNameStr = path.asWString();

	TCHAR szFileName[MAX_PATH];
	memset(szFileName, 0, sizeof(TCHAR) * MAX_PATH);

	auto length = GetLongPathNameW(fileNameStr.c_str(), szFileName, MAX_PATH);

	if (length <= 0) {
		return path;
	}

	std::wstring resultStr = std::wstring(szFileName);

	return CString(resultStr);
}

DataSize DirectoryServiceWin32::parentDiskFreeSize(const Path& directoryPath) const {
	DataSize result = DataSize::zero();
	DataSize dummy = DataSize::zero();

	getDiskInfo(directoryPath, result, dummy);

	return result;
}

DataSize DirectoryServiceWin32::parentDiskTotalSize(const Path& directoryPath) const {
	DataSize result = DataSize::zero();
	DataSize dummy = DataSize::zero();

	getDiskInfo(directoryPath, dummy, result);

	return result;
}

bool isFilteredOut(WIN32_FIND_DATA& data, const DirectoryScanFilter& filter) {
	std::wstring str = std::wstring(data.cFileName);
	bool isDirectory = data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
	bool isFile = !isDirectory;
	bool isHidden = data.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN;
	bool isSystem = data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM;
	bool isReadonly = data.dwFileAttributes & FILE_ATTRIBUTE_READONLY;
	bool isBullshit = str == L"." || str == L"..";

	if (isBullshit) {
		return true;
	}

	if (!filter.includeDirectories && isDirectory) {
		return true;
	}

	if (!filter.includeFiles && isFile) {
		return true;
	}

	if (!filter.includeReadonly && isReadonly) {
		return true;
	}

	if (!filter.includeWritable && !isReadonly) {
		return true;
	}

	if (!filter.includeHidden && isHidden) {
		return true;
	}

	if (!filter.includeNonHidden && !isHidden) {
		return true;
	}

	if (!filter.includeSystem && isSystem) {
		return true;
	}

	if (!filter.includeNonSystem && !isSystem) {
		return true;
	}

	return false;
}

List<Path> DirectoryServiceWin32::directoryContents(const Path& directoryPath, const DirectoryScanFilter& filter) const {
	List<Path> paths;

	WIN32_FIND_DATA ffd;

	CString dirPathValue = directoryPath.absolute();
	
	if (!dirPathValue.endsWith(directoryPath.separator())) {
		dirPathValue += directoryPath.separator();
	}

	std::wstring dirPathBase = dirPathValue.asWString();
	
	std::wstring searchQuery = dirPathValue.asWString();
	searchQuery += L"*"; // Search all contents

	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;

	if (searchQuery.length() >= MAX_PATH) {
		return paths;
	}

	hFind = FindFirstFile(searchQuery.c_str(), &ffd);

	if (hFind == INVALID_HANDLE_VALUE) {
		return paths;
	}

	do {
		if (isFilteredOut(ffd, filter)) {
			continue;
		}

		std::wstring str = std::wstring(ffd.cFileName);
		bool isDirectory = ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;

		if (isDirectory) {
			Path path = Path::directoryFromAbsolutePath(dirPathBase + str);
			paths.add(path);
		} else {
			Path path = Path::fileFromAbsolutePath(dirPathBase + str);
			paths.add(path);
		}
	} while (FindNextFile(hFind, &ffd) != 0);

	FindClose(hFind);

	paths.removeDuplicates();

	return paths;
}
