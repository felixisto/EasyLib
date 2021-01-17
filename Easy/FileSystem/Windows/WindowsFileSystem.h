#pragma once

#include "../../Basic/Basic.h"
#include "../DirectoryService.h"
#include "../FileAttributeService.h"

#ifdef _WIN32

namespace easy {
	namespace fs {
		#define FS_WIN_32_AVAILABLE
	};
};

#endif
