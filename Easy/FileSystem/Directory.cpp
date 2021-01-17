
#include "Directory.h"
#include <direct.h>
#include "File.h"

using namespace easy;
using namespace fs;

Directory Directory::fromPath(const Path& path) {
	return Directory(path);
}

Directory::Directory() {

}

Directory::Directory(const Path& path) : _path(path) {

}

Directory::Directory(const Directory& other) : _path(other._path) {

}

Directory::~Directory() {

}

Directory& Directory::operator=(const Directory& other) {
	return *this;
}

bool Directory::operator==(const Directory& other) const {
	return _path == other._path;
}

// # Flow

int makeDir(const Path& path) {
	CString pathStr = path.absolute();

	if (!pathStr.endsWith(path.separator())) {
		pathStr += path.separator();
	}

	errno = 0;
	return _mkdir(pathStr.buffer());
}

const Error* Directory::create() {
	return create(true);
}

const Error* Directory::create(bool createParentIfNecessary) {
	errno = 0;

	auto result = makeDir(_path);

	if (result == 0) {
		return NULL;
	}

	const Error* error = Errors::errorForMKDIRErrorErrno(errno);

	if (error == &Errors::ENITY_ALREADY_EXISTS()) {
		return NULL;
	}

	// Parent directory does not exist. Create it.
	if (error == &Errors::ENITY_DOES_NOT_EXIST() && createParentIfNecessary) {
		Directory p = parent();

		auto pError = p.create();

		return create(false);
	}

	return error;
}

const Error* Directory::remove() {
	auto result = _rmdir(_path.absolute().buffer());

	if (result == 0) {
		return NULL;
	}

	return Errors::errorForRMDIRErrorErrno(errno);
}

// # Properties

const Path& Directory::getPath() const {
	return _path;
}

bool Directory::isRoot() const {
	return _path.isRoot();
}

FileAttributes Directory::attributes() const {
	return FileAttributeService::standard().readInfo(_path);
}

Directory Directory::parent() const {
	return Directory::fromPath(_path.parentPath());
}

List<Path> Directory::contents() const {
	return DirectoryService::standard().directoryContents(_path, DirectoryScanFilter::standard());
}

List<File> Directory::fileContents() const {
	List<Path> paths = DirectoryService::standard().directoryContents(_path, DirectoryScanFilter::filesOnly());
	List<File> files;

	for (int e = 0; e < paths.size(); e++) {
		files.add(File::fromPath(paths[e]));
	}

	return files;
}

List<Directory> Directory::directoryContents() const {
	List<Path> paths = DirectoryService::standard().directoryContents(_path, DirectoryScanFilter::directoriesOnly());
	List<Directory> directories;

	for (int e = 0; e < paths.size(); e++) {
		directories.add(Directory::fromPath(paths[e]));
	}

	return directories;
}

// # StringRepresentable

CString Directory::toString() const {
	return _path.absolute();
}

// # Hashable

ubig Directory::hashValue() const {
	return _path.hashValue();
}
