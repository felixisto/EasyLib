#pragma once

#include "Path.h"
#include "Error.h"
#include "../Collections/Array/List.h"

namespace easy {
	namespace fs {
		struct DirectoryScanFilter {
			bool includeFiles = true;
			bool includeDirectories = true;
			bool includeNonHidden = true;
			bool includeHidden = true;
			bool includeReadonly = true;
			bool includeWritable = true;
			bool includeNonSystem = true;
			bool includeSystem = false;

			static DirectoryScanFilter standard() {
				return DirectoryScanFilter();
			}

			static DirectoryScanFilter filesOnly() {
				DirectoryScanFilter f;
				f.includeDirectories = false;
				return f;
			}

			static DirectoryScanFilter directoriesOnly() {
				DirectoryScanFilter f;
				f.includeFiles = false;
				return f;
			}
		};

		struct DirectoryServiceReader {
			virtual ~DirectoryServiceReader() {}

			virtual CString fileSystemSeparator() const = 0;

			// The directory of the executable.
			virtual Path applicationDirectory() const = 0;

			// The applications temp directory. Platform dependant.
			virtual Path temporaryPathDirectory() const = 0;

			// The applications temp file. Platform dependant.
			virtual Path temporaryPathFile(const CString& prefix) const = 0;

			virtual CString absolutePathFrom(const CString& path) const = 0;

			virtual DataSize parentDiskFreeSize(const Path& directoryPath) const = 0;
			virtual DataSize parentDiskTotalSize(const Path& directoryPath) const = 0;

			virtual List<Path> directoryContents(const Path& directoryPath, const DirectoryScanFilter& filter) const = 0;
		};

		struct DirectoryService: DirectoryServiceReader {
			static const DirectoryService& standard();

			// Directory service is implemented differently, depending on the platform.
			// It may not be available on some platforms.
			// Use this method to determine that.
			bool isAvailable() const;

			// # DirectoryServiceReader

			virtual CString fileSystemSeparator() const;

			virtual Path applicationDirectory() const;

			virtual Path temporaryPathDirectory() const;
			virtual Path temporaryPathFile(const CString& prefix) const;

			virtual CString absolutePathFrom(const CString& path) const;

			virtual DataSize parentDiskFreeSize(const Path& directoryPath) const;
			virtual DataSize parentDiskTotalSize(const Path& directoryPath) const;

			virtual List<Path> directoryContents(const Path& directoryPath, const DirectoryScanFilter& filter) const;

		private:

			DirectoryServiceReader* _readerImpl;

			DirectoryService();

			virtual ~DirectoryService();
		};
	};
};
