#pragma once

#include "../Foundation/Date.h"
#include "../Collections/Dictionary/Dictionary.h"
#include "FileAttributes.h"
#include "DirectoryService.h"

namespace easy {
	namespace fs {
		struct FileAttributeServiceReader {
			virtual ~FileAttributeServiceReader() {}

			virtual Dictionary<Path, FileAttributes> readInfos(const List<Path>& paths) = 0;
		};

		/*
		 * Reads the attributes of both files and directories.
		 *
		 * Note that the size of directories is usually not fetched.
		 */
		struct FileAttributeService {
			static const FileAttributeService& standard();

			// File attribute service is implemented differently, depending on the platform.
			// It may not be available on some platforms.
			// Use this method to determine that.
			bool isAvailable() const;

			virtual FileAttributes readInfo(const Path& path) const;
			virtual Dictionary<Path, FileAttributes> readInfos(const List<Path>& paths) const;

		private:
			FileAttributeServiceReader* _readerImpl;

			FileAttributeService();
			FileAttributeService(const FileAttributeService& other);
			virtual ~FileAttributeService();
		};
	};
};
