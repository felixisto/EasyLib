#pragma once

#include "../Basic/Defines.h"
#include "../Basic/Basic.h"
#include "../Foundation/CString.h"

namespace easy {
	struct StreamError {
		const int code;
		const CString message;

		StreamError(int code, const CString& message) : code(code), message(message) {

		}

		StreamError(const StreamError& other) : code(other.code), message(other.message) {

		}
	};

	struct Stream {
		virtual ~Stream() {}

		virtual const StreamError* close() = 0;
	};

	struct InputStream: Stream {
		virtual ~InputStream() {}

		// Returns true if stream has bytes to read; false otherwise.
		// A bit unreliable, depending on stream type and other things.
		virtual bool hasAvailableBytes() = 0;

		// Reads the next byte(s) in the stream.
		// @param buffer The result is saved in this buffer.
		// @param length On input, how many bytes to read. On out, how many bytes were read.
		virtual const StreamError* read(BytesBuffer& buffer, size_t& length) = 0;
	};

	struct OutputStream: Stream {
		virtual ~OutputStream() {}

		// Reads the next byte(s) in the stream.
		// @param buffer The result is saved in this buffer.
		// @param length How many bytes to read.
		virtual const StreamError* write(BytesBuffer& buffer) = 0;

		// Flushes written data through the stream.
		virtual const StreamError* flush() = 0;
	};

	struct StreamErrors {
		static const StreamError& UNKNOWN() {
			static StreamError err = StreamError(0, "Unknown Error");
			return err;
		}

		static const StreamError& CLOSED() {
			static StreamError err = StreamError(1, "Stream closed");
			return err;
		}

		static const StreamError& ALREADY_CLOSED() {
			static StreamError err = StreamError(2, "Stream already closed");
			return err;
		}

		static const StreamError& READ_TIMEOUT() {
			static StreamError err = StreamError(3, "Read timeout");
			return err;
		}

		static const StreamError& UNSUPPORTED_OPERATION() {
			static StreamError err = StreamError(4, "Unsupported operation");
			return err;
		}

		static const StreamError& CLOSE_FILE_INSTEAD_OF_STREAM() {
			static StreamError err = StreamError(5, "Close the file instead of the stream");
			return err;
		}

		static const StreamError& END_OF_FILE() {
			static StreamError err = StreamError(6, "End of file");
			return err;
		}
	};
};
