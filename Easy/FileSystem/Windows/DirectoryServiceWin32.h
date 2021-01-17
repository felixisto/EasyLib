#pragma once

#include "WindowsFileSystem.h"

#ifdef _WIN32

namespace easy {
	namespace fs {
#define FS_WIN_32_AVAILABLE

		struct DirectoryServiceWin32: DirectoryServiceReader {
			virtual CString fileSystemSeparator() const;

			virtual Path applicationDirectory() const;
			virtual Path temporaryPathDirectory() const;
			virtual Path temporaryPathFile(const CString& prefix) const;

			virtual CString absolutePathFrom(const CString& path) const;

			virtual DataSize parentDiskFreeSize(const Path& directoryPath) const;
			virtual DataSize parentDiskTotalSize(const Path& directoryPath) const;

			virtual List<Path> directoryContents(const Path& directoryPath, const DirectoryScanFilter& filter) const;
		};
	};
};

#endif
