
#include "FileStream.h"

using namespace easy;

// # FileInputStream

FileInputStream::FileInputStream(const FileInputStream& other) : _handle(other._handle) {

}

FileInputStream::FileInputStream(FILE* handle) : _handle(handle) {

}

FileInputStream::~FileInputStream() {
	close();
}

const StreamError* FileInputStream::close() {
	if (_handle == NULL) {
		return &StreamErrors::ALREADY_CLOSED();
	}

	fclose(_handle);
	_handle = NULL;

	return NULL;
}

bool FileInputStream::hasAvailableBytes() {
	return true;
}

const StreamError* FileInputStream::read(BytesBuffer& buffer, size_t& length) {
	if (_handle == NULL) {
		return &StreamErrors::CLOSED();
	}

	buffer.setLength(length);

	size_t count = fread_s(buffer.getBuffer(), length, buffer.elementSize(), length, _handle);

	if (feof(_handle)) {
		return &StreamErrors::END_OF_FILE();
	}

	auto err = ferror(_handle);

	if (err != 0) {
		length = 0;
		return &StreamErrors::UNKNOWN();
	}

	length = count;

	return NULL;
}

const StreamError* FileInputStream::readAll(BytesBuffer& buffer, size_t maxSize) {
	const size_t DEFAULT_READ_COUNT = 100;
	size_t readCount = 100;

	if (readCount > maxSize) {
		readCount = maxSize;
	}

	while (true) {
		auto error = read(buffer, readCount);

		if (maxSize < readCount) {
			integer diff = readCount - maxSize;
			integer newLength = buffer.length() - diff;

			if (newLength > 0) {
				buffer.setSizeInBytes(newLength);
			}

			break;
		} else {
			maxSize -= readCount;
		}

		if (error != NULL) {
			if (error == &StreamErrors::END_OF_FILE()) {
				break;
			}

			return error;
		}

		readCount = DEFAULT_READ_COUNT;
	}

	return NULL;
}

// # OwnedFileInputStream

OwnedFileInputStream::OwnedFileInputStream(FILE* handle) : FileInputStream(handle) {

}

OwnedFileInputStream::~OwnedFileInputStream() {

}

const StreamError* OwnedFileInputStream::close() {
	return &StreamErrors::CLOSE_FILE_INSTEAD_OF_STREAM();
}

// # 

FileOutputStream::FileOutputStream(FILE* handle) : _handle(handle) {

}

FileOutputStream::~FileOutputStream() {
	close();
}

// # FileOutputStream

const StreamError* FileOutputStream::close() {
	if (_handle == NULL) {
		return &StreamErrors::ALREADY_CLOSED();
	}

	flush();

	fclose(_handle);
	_handle = NULL;

	return NULL;
}

const StreamError* FileOutputStream::write(BytesBuffer& buffer) {
	return write(buffer.getBuffer(), buffer.elementSize(), buffer.sizeInBytes());
}

const StreamError* FileOutputStream::write(const byte* buffer, size_t elementSize, size_t length) {
	if (_handle == NULL) {
		return &StreamErrors::CLOSED();
	}

	int writtenCount = fwrite(buffer, length, elementSize, _handle);

	auto err = ferror(_handle);

	if (err != 0 || writtenCount == 0) {
		return &StreamErrors::UNKNOWN();
	}

	return NULL;
}

const StreamError* FileOutputStream::flush() {
	if (_handle == NULL) {
		return &StreamErrors::CLOSED();
	}

	int flushedCount = fflush(_handle);

	auto err = ferror(_handle);

	if (err != 0) {
		return &StreamErrors::UNKNOWN();
	}

	return NULL;
}

// # OwnedFileOutputStream

OwnedFileOutputStream::OwnedFileOutputStream(FILE* handle) : FileOutputStream(handle) {

}

OwnedFileOutputStream::~OwnedFileOutputStream() {

}

const StreamError* OwnedFileOutputStream::close() {
	return &StreamErrors::CLOSE_FILE_INSTEAD_OF_STREAM();
}
