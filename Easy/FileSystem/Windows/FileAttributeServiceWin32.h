#pragma once

#include "WindowsFileSystem.h"
#include "DirectoryServiceWin32.h"

#ifdef FS_WIN_32_AVAILABLE

namespace easy {
	namespace fs {
		struct FileAttributeServiceWin32: FileAttributeServiceReader {
			virtual Dictionary<Path, FileAttributes> readInfos(const List<Path>& paths);
		};
	};
};

#endif
