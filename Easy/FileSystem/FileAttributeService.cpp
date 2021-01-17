
#include "FileAttributeService.h"
#include "Windows/FileAttributeServiceWin32.h"

using namespace easy;
using namespace fs;

const FileAttributeService& FileAttributeService::standard() {
	static FileAttributeService service;
	return service;
}

FileAttributeService::FileAttributeService() {
#ifdef FS_WIN_32_AVAILABLE
	_readerImpl = new FileAttributeServiceWin32();
#endif
}

FileAttributeService::FileAttributeService(const FileAttributeService& other) {
	_readerImpl = nullptr;
}

FileAttributeService::~FileAttributeService() {
	delete _readerImpl;
}

bool FileAttributeService::isAvailable() const {
	return _readerImpl != nullptr;
}

Dictionary<Path, FileAttributes> FileAttributeService::readInfos(const List<Path>& paths) const {
	if (!isAvailable()) {
		return Dictionary<Path, FileAttributes>();
	}

	return _readerImpl->readInfos(paths);
}

FileAttributes FileAttributeService::readInfo(const Path& path) const {
	List<Path> paths;
	paths.add(path);

	auto infos = readInfos(paths);

	if (infos.size() == 0) {
		return FileAttributes();
	}

	return infos[path];
}
