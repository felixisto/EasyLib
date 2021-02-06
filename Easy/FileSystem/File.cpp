
#include "File.h"

using namespace easy;
using namespace fs;

FileOpenFlags FileOpenFlags::standard() {
	return readonly();
}

FileOpenFlags FileOpenFlags::readonly() {
	FileOpenFlags flags;
	flags.write = false;
	flags.append = false;
	return flags;
}

FileOpenFlags FileOpenFlags::writeOverride() {
	FileOpenFlags flags;
	flags.write = true;
	flags.append = false;
	return flags;
}

FileOpenFlags FileOpenFlags::writeAppend() {
	FileOpenFlags flags;
	flags.write = true;
	flags.append = true;
	return flags;
}

CString FileOpenFlags::modeForOpen() const {
	if (append) {
		return "a+";
	}

	if (write) {
		return "w+";
	}

	return "r";
}

File File::fromPath(const Path& path) {
	return File(path, false);
}

File File::createFromPath(const Path& path) {
	return File(path, true);
}

File::File() {
	_handle = NULL;
	_createIfNecessary = false;
	_inputStream = NULL;
	_outputStream = NULL;
}

File::File(const File& other) : _path(other._path), _createIfNecessary(other._createIfNecessary) {
	_handle = NULL;
	_inputStream = NULL;
	_outputStream = NULL;
}

File::File(const Path& path, bool createIfNecessary) : _path(path), _createIfNecessary(createIfNecessary) {
	_handle = NULL;
	_inputStream = NULL;
	_outputStream = NULL;
}

File::~File() {
	close();
}

File& File::operator=(const File& other) {
	return *this;
}

bool File::operator==(const File& other) const {
	return _path == other._path;
}

// # Properties

const Path& File::getPath() const {
	return _path;
}

bool File::isDirectory() const {
	auto info = FileAttributeService::standard().readInfo(_path);
	return info.isDirectory;
}

CString File::name() const {
	return _path.lastComponent();
}

DataSize File::size() const {
	auto info = FileAttributeService::standard().readInfo(_path);
	return info.size;
}

bool File::isReadonly() const {
	auto info = FileAttributeService::standard().readInfo(_path);
	return info.isReadonly;
}

FileAttributes File::attributes() const {
	return FileAttributeService::standard().readInfo(_path);
}

Directory File::parentDirectory() const {
	if (_path.isRoot()) {
		return Directory::fromPath(_path);
	}

	Path parent = _path.parentPath();
	return Directory::fromPath(parent);
}

// # Flow

bool File::isOpen() const {
	return _handle != nullptr;
}

const Error* File::create() {
	return create(false);
}

const Error* File::create(bool replace) {
	cstring openFormat = replace ? "w+" : "a+";

	FILE* tempHandle = nullptr;

	errno = 0;
	fopen_s(&tempHandle, _path.absolute().buffer(), openFormat);

	if (tempHandle == NULL) {
		bool recovered = false;
		const Error* error = Errors::errorForFileErrorErrno(errno);

		if (error == &Errors::ENITY_DOES_NOT_EXIST()) {
			// Try to create the parent directory
			Directory parent = parentDirectory();
			
			auto parentError = parent.create();

			if (parentError == nullptr) {
				errno = 0;
				fopen_s(&tempHandle, _path.absolute().buffer(), openFormat);

				recovered = tempHandle != nullptr;
			}
		}

		if (!recovered) {
			return error;
		}
	}

	fclose(tempHandle);

	return NULL;
}

const Error* File::open() {
	return open(FileOpenFlags::standard());
}

const Error* File::openForWriting() {
	return open(FileOpenFlags::writeOverride());
}

const Error* File::open(const FileOpenFlags& flags) {
	if (isOpen()) {
		return &Errors::ALREADY_OPEN();
	}

	if (_createIfNecessary) {
		create();
	}

	auto mode = flags.modeForOpen();

	errno = 0;
	fopen_s(&_handle, _path.absolute().buffer(), mode.buffer());

	if (_handle == NULL) {
		return Errors::errorForFileErrorErrno(errno);
	}

	_inputStream = new OwnedFileInputStream(_handle);
	_outputStream = new OwnedFileOutputStream(_handle);

	return NULL;
}

const Error* File::close() {
	if (!isOpen()) {
		return &Errors::ALREADY_CLOSED();
	}

	fclose(_handle);

	_handle = NULL;
	delete _inputStream;
	_inputStream = NULL;
	delete _outputStream;
	_outputStream = NULL;

	return NULL;
}

const Error* File::erase() {
	close();

	remove(_path.absolute().buffer());

	return nullptr;
}

// # Disk storage properties

DataSize File::parentDiskFreeSize() const {
	return DirectoryService::standard().parentDiskFreeSize(_path);
}

DataSize File::parentDiskTotalSize() const {
	return DirectoryService::standard().parentDiskTotalSize(_path);
}

// # Streams

FileInputStream* File::inputStream() {
	return _inputStream;
}

FileOutputStream* File::outputStream() {
	return _outputStream;
}

// # StringRepresentable

CString File::toString() const {
	return _path.absolute();
}

// # Hashable

ubig File::hashValue() const {
	return _path.hashValue();
}
