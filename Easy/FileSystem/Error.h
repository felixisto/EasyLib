#pragma once

#include "Path.h"

namespace easy {
	namespace fs {
		struct Error {
			const int code;
			const CString message;

			Error(int code, const CString& message) : code(code), message(message) {

			}

			Error(const Error& other) : code(other.code), message(other.message) {

			}
		};

		struct Errors {
			static const Error& UNKNOWN() {
				static Error err = Error(0, "Unknown Error");
				return err;
			}

			static const Error& INVALID_PATH() {
				static Error err = Error(1, "Invalid path");
				return err;
			}

			static const Error& ACCESS_DENIED() {
				static Error err = Error(2, "Access Denied");
				return err;
			}

			static const Error& UNSUPPORTED_OPERATION() {
				static Error err = Error(3, "Unsupported operation");
				return err;
			}

			static const Error& ALREADY_OPEN() {
				static Error err = Error(4, "Already open");
				return err;
			}

			static const Error& ALREADY_CLOSED() {
				static Error err = Error(5, "Already closed");
				return err;
			}

			static const Error& ENITY_DOES_NOT_EXIST() {
				static Error err = Error(6, "Does not exist");
				return err;
			}

			static const Error& ENITY_ALREADY_EXISTS() {
				static Error err = Error(7, "Already exists");
				return err;
			}

			static const Error& BAD_PATH() {
				static Error err = Error(8, "Bad path");
				return err;
			}

			static const Error* errorForFileErrorErrno(int code) {
				if (code == 0) {
					return NULL;
				}

				if (code == ENOENT) {
					return &ENITY_DOES_NOT_EXIST();
				}

				return &UNKNOWN();
			}

			static const Error* errorForMKDIRErrorErrno(int code) {
				if (code == 0) {
					return NULL;
				}

				if (code == EEXIST) {
					return &ENITY_ALREADY_EXISTS();
				}

				if (code == ENAMETOOLONG) {
					return &BAD_PATH();
				}

				if (code == ENOENT) {
					return &ENITY_DOES_NOT_EXIST();
				}

				return &UNKNOWN();
			}

			static const Error* errorForRMDIRErrorErrno(int code) {
				if (code == 0) {
					return NULL;
				}

				return &UNKNOWN();
			}
		};
	};
};
