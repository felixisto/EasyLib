
#include "FileAttributeServiceWin32.h"
#include "FileTimeWin32.h"
#include "../../Formatters/DateFormatter.h"
#include <Windows.h>

using namespace easy;
using namespace fs;

HANDLE openFile(const Path& path) {
	auto str = path.absolute().asWString();

	return CreateFileW(str.c_str(), FILE_READ_ATTRIBUTES, 0, NULL, OPEN_EXISTING, 0, NULL);
}

void closeFile(HANDLE fileHandle) {
	CloseHandle(fileHandle);
}

DataSize getFileSize(HANDLE handle) {
	LPDWORD size = nullptr;

	auto result = GetFileSize(handle, size);

	if (result == INVALID_FILE_SIZE && GetLastError() != NO_ERROR) {
		return DataSize::zero();
	}

	return DataSize::fromBytes(result);
}

CString getFullFilePath(HANDLE handle) {
	WCHAR buffer[MAX_PATH];
	memset(buffer, 0, sizeof(WCHAR) * MAX_PATH);

	auto result = GetFinalPathNameByHandleW(handle, buffer, MAX_PATH, 0);

	if (result == 0) {
		return CString();
	}

	std::wstring str = std::wstring(buffer);

	return CString(str);
}

void getAttributes(HANDLE handle, FileAttributes& attributes) {
	const int BUFFER_SIZE = 4086;
	FILE_BASIC_INFO blob = {};

	auto result = GetFileInformationByHandleEx(handle, FileBasicInfo, &blob, sizeof(blob));

	if (!result) {
		attributes.isDirectory = true;
		return;
	}

	auto attrs = blob.FileAttributes;
	bool isDirectory = attrs & FILE_ATTRIBUTE_DIRECTORY;
	bool isReadonly = attrs & FILE_ATTRIBUTE_READONLY;
	bool isHidden = attrs & FILE_ATTRIBUTE_HIDDEN;
	bool isSystem = attrs & FILE_ATTRIBUTE_SYSTEM;

	attributes.isDirectory = isDirectory;
	attributes.isReadonly = isReadonly;
	attributes.isHidden = isHidden;
	attributes.isSystem = isSystem;
}

FileAttributesTime getDateProperties(const Path& path) {
	auto str = path.absolute().asWString();

	WIN32_FILE_ATTRIBUTE_DATA data;

	auto result = GetFileAttributesEx(str.c_str(), GetFileExInfoStandard, &data);

	FileAttributesTime time;

	time.createDate = Date(WinFileTime::timeReferenceFromFileTime(data.ftCreationTime));
	time.lastAccessDate = Date(WinFileTime::timeReferenceFromFileTime(data.ftLastAccessTime));
	time.lastWriteDate = Date(WinFileTime::timeReferenceFromFileTime(data.ftLastWriteTime));

	return time;
}

bool readInfoOfFilePath(const Path& path, FileAttributes& attributes) {
	auto handle = openFile(path);

	if (handle == INVALID_HANDLE_VALUE) {
		return false;
	}

	DataSize size = getFileSize(handle);
	FileAttributesTime time = getDateProperties(path);
	getAttributes(handle, attributes);

	attributes.size = size;
	attributes.time = time;

	closeFile(handle);

	return true;
}

bool readInfoOfDirectoryPath(const Path& path, FileAttributes& attributes) {
	std::wstring fullName = path.absolute().asWString();

	WIN32_FILE_ATTRIBUTE_DATA data = {};

	auto result = GetFileAttributesExW(fullName.c_str(), GetFileExInfoStandard, &data);

	if (!result) {
		return false;
	}

	attributes.isDirectory = true;
	attributes.size = DataSize::fromBytes(0);

	attributes.time.createDate = Date(WinFileTime::timeReferenceFromFileTime(data.ftCreationTime));
	attributes.time.lastAccessDate = Date(WinFileTime::timeReferenceFromFileTime(data.ftLastAccessTime));
	attributes.time.lastWriteDate = Date(WinFileTime::timeReferenceFromFileTime(data.ftLastWriteTime));

	return true;
}

bool readInfoOfPath(const Path& path, FileAttributes& attributes) {
	// Try file first
	if (readInfoOfFilePath(path, attributes)) {
		return true;
	}

	return readInfoOfDirectoryPath(path, attributes);
}

Dictionary<Path, FileAttributes> FileAttributeServiceWin32::readInfos(const List<Path>& paths) {
	Dictionary<Path, FileAttributes> infos;

	for (int e = 0; e < paths.size(); e++) {
		auto path = paths[e];

		FileAttributes data;

		if (readInfoOfPath(path, data)) {
			infos.insert(path, data);
		}
	}

	return infos;
}


