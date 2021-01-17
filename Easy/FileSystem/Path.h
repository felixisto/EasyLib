#pragma once

#include "../Basic/Basic.h"
#include "../Foundation/CString.h"

namespace easy {
	namespace fs {
		/*
		 * File system path to a file or folder.
		 */
		struct Path: StringRepresentable, Hashable, Copyable<Path> {
		private:
			CString _value;

			Path(const CString& value);
		public:
			// The application directory will be inserted, before the given file path.
			static Path fileFromLocalPath(const CString& path);
			static Path fileFromAbsolutePath(const CString& path);

			static Path directoryFromLocalPath(const CString& path);
			static Path directoryFromAbsolutePath(const CString& path);

			// Platform temporary directory path.
			static Path temporaryPathDirectory();

			// Platform temporary file path.
			static Path temporaryFilePath();
			static Path temporaryFilePath(const CString& prefix);

			static CString fileSystemSeparator();

			Path();
			Path(const Path& other);

			bool operator==(const Path& other) const;
			bool operator<(const Path& other) const;

			// # Build

			Path pathByAppendingComponent(const CString& component) const;
			Path parentPath() const;

			// # Values

			// The exact value, of the path.
			// May or may not be equal to the absolute value.
			CString rawValue() const;

			// The exact path, of the file system item.
			// Use this to perform file/directory operations.
			CString absolute() const;

			CString separator() const;

			// Usually the name.
			CString lastComponent() const;

			// # Validators

			bool isRoot() const;
			bool isValidFilePath() const;

			// # StringRepresentable

			virtual CString toString() const;

			// # Hashable

			virtual ubig hashValue() const;

			// # Copyable

			virtual Path copy() const;
		};
	};
};
