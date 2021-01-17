#pragma once

#include "../Collections/Array/List.h"
#include "DirectoryService.h"
#include "FileAttributes.h"

namespace easy {
	namespace fs {
		struct File;

		/*
		 * Directory reference.
		 *
		 * Try to pass by reference only. Copying a directory, only copies the path.
		 *
		 * Thread safe: no
		 */
		struct Directory: StringRepresentable, Hashable {
		private:
			Path _path;

			Directory();
			Directory(const Path& path);

			Directory& operator=(const Directory& other);

		public:
			static Directory fromPath(const Path& path);

			Directory(const Directory& other);

			virtual ~Directory();

			bool operator==(const Directory& other) const;

			// # Flow

			const Error* create();
			const Error* create(bool createParentIfNecessary);
			const Error* remove();

			// # Properties

			const Path& getPath() const;
			bool isRoot() const;
			FileAttributes attributes() const;

			Directory parent() const;

			List<Path> contents() const;
			List<File> fileContents() const;
			List<Directory> directoryContents() const;

			// # StringRepresentable

			virtual CString toString() const;

			// # Hashable

			virtual ubig hashValue() const;
		};
	};
};

