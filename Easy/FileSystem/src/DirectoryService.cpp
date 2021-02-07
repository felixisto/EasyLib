
#include "../DirectoryService.h"
#include "../Windows/DirectoryServiceWin32.h"

using namespace easy;
using namespace fs;

const DirectoryService& DirectoryService::standard() {
	static DirectoryService service;
	return service;
}

DirectoryService::DirectoryService() {
#ifdef FS_WIN_32_AVAILABLE
	_readerImpl = new DirectoryServiceWin32();
#endif
}

DirectoryService::~DirectoryService() {
	delete _readerImpl;
}

bool DirectoryService::isAvailable() const {
	return _readerImpl != nullptr;
}

CString DirectoryService::fileSystemSeparator() const {
	if (!isAvailable()) {
		return CString("/");
	}

	return _readerImpl->fileSystemSeparator();
}

Path DirectoryService::applicationDirectory() const {
	if (!isAvailable()) {
		return Path();
	}

	return _readerImpl->applicationDirectory();
}

Path DirectoryService::temporaryPathDirectory() const {
	if (!isAvailable()) {
		return Path();
	}

	return _readerImpl->temporaryPathDirectory();
}

Path DirectoryService::temporaryPathFile(const CString& prefix) const {
	if (!isAvailable()) {
		return Path();
	}

	return _readerImpl->temporaryPathFile(prefix);
}

CString DirectoryService::absolutePathFrom(const CString& path) const {
	if (!isAvailable()) {
		return CString();
	}

	return _readerImpl->absolutePathFrom(path);
}

DataSize DirectoryService::parentDiskFreeSize(const Path& directoryPath) const {
	if (!isAvailable()) {
		return DataSize::zero();
	}

	return _readerImpl->parentDiskFreeSize(directoryPath);
}

DataSize DirectoryService::parentDiskTotalSize(const Path& directoryPath) const {
	if (!isAvailable()) {
		return DataSize::zero();
	}

	return _readerImpl->parentDiskTotalSize(directoryPath);
}

List<Path> DirectoryService::directoryContents(const Path& directoryPath, const DirectoryScanFilter& filter) const {
	if (!isAvailable()) {
		return List<Path>();
	}

	return _readerImpl->directoryContents(directoryPath, filter);
}
