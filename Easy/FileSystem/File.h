#pragma once

#include "FileAttributes.h"
#include "../Collections/Array/List.h"
#include "../Foundation/FileStream.h"
#include "FileAttributeService.h"
#include "Directory.h"

namespace easy {
	namespace fs {
		struct FileOpenFlags {
			bool write = false;
			bool append = false;

			static FileOpenFlags standard();
			static FileOpenFlags readonly();
			static FileOpenFlags writeOverride();
			static FileOpenFlags writeAppend();

			CString modeForOpen() const;
		};

		/*
		 * Handle to a file. 
		 * 
		 * Try to pass by reference only. Copying a file, only copies the path.
		 * 
		 * Thread safe: no
		 */
		struct File: StringRepresentable, Hashable {
		private:
			Path _path;
			bool _createIfNecessary;

			FILE* _handle;

			FileInputStream* _inputStream;
			FileOutputStream* _outputStream;

			File();
			File(const Path& path, bool createIfNecessary);

			File& operator=(const File& other);

		public:
			static File fromPath(const Path& path);

			// When opening the file, it will be created, along with its directories, if necessary.
			static File createFromPath(const Path& path);

			File(const File& other);

			virtual ~File();

			bool operator==(const File& other) const;

			// # Properties

			const Path& getPath() const;
			bool isDirectory() const;
			CString name() const;
			DataSize size() const;
			bool isReadonly() const;
			FileAttributes attributes() const;

			Directory parentDirectory() const;

			// # Flow

			bool isOpen() const;

			const Error* create();
			const Error* create(bool replace);

			const Error* open();
			const Error* open(const FileOpenFlags& flags);
			const Error* close();

			// # Disk storage properties

			// The free size remaining on the disk, on which the file is located on.
			DataSize parentDiskFreeSize() const;
			DataSize parentDiskTotalSize() const;

			// # Streams

			// Provides the input stream to the file.
			// Returns NULL if the file is not open.
			// Do NOT close the stream after being done. Its automatically closed by the file.
			FileInputStream* inputStream();
			FileOutputStream* outputStream();

			// # StringRepresentable

			virtual CString toString() const;

			// # Hashable

			virtual ubig hashValue() const;
		};
	};
};
