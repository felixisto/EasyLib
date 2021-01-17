#pragma once

#include "Stream.h"

namespace easy {
	/*
	 * An input stream from a file.
	 * 
	 * Thread safe: no 
	 */
	struct FileInputStream: InputStream {
	private:
		FILE* _handle;

		FileInputStream(const FileInputStream& other);
	public:
		FileInputStream(FILE* handle);

		virtual ~FileInputStream();

		// # InputStream

		virtual const StreamError* close();

		virtual bool hasAvailableBytes();

		virtual const StreamError* read(BytesBuffer& buffer, size_t& length);

		virtual const StreamError* readAll(BytesBuffer& buffer, size_t maxSize);
	};

	/*
	 * An input stream from a file.
	 * 
	 * Do not close the stream, instead close the file that provided the stream.
	 *
	 * Thread safe: no
	 */
	struct OwnedFileInputStream: FileInputStream {
		OwnedFileInputStream(FILE* handle);

		virtual ~OwnedFileInputStream();

		virtual const StreamError* close();
	};

	/*
	 * An output stream to a file.
	 * 
	 * The behaviour of when the data is actually written varies depending on the platform.
	 * For example on Windows 10, when flushing, the contents are changed for the running source app,
	 * but not for other apps. The actual changes are made universal when closing the file.
	 *
	 * Thread safe: no
	 */
	struct FileOutputStream: OutputStream {
	private:
		FILE* _handle;

		FileOutputStream(const FileInputStream& other);
	public:
		FileOutputStream(FILE* handle);

		virtual ~FileOutputStream();

		// # OutputStream

		virtual const StreamError* close();

		virtual const StreamError* write(BytesBuffer& buffer);

		virtual const StreamError* flush();
	};

	/*
	 * An output stream to a file.
	 *
	 * Do not close the stream, instead close the file that provided the stream.
	 *
	 * Thread safe: no
	 */
	struct OwnedFileOutputStream: FileOutputStream {
	public:
		OwnedFileOutputStream(FILE* handle);

		virtual ~OwnedFileOutputStream();

		virtual const StreamError* close();
	};
};
