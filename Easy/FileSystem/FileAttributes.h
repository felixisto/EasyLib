#pragma once

#include "Path.h"
#include "Error.h"
#include "../Foundation/Date.h"

namespace easy {
	namespace fs {
		struct FileAttributesTime {
			// Dates are always in UTC time.
			Date createDate;
			Date lastAccessDate;
			Date lastWriteDate;

			bool operator==(const FileAttributesTime& other) const {
				return createDate == other.createDate &&
					lastAccessDate == other.lastAccessDate &&
					lastWriteDate == other.lastWriteDate;
			}
		};

		struct FileAttributes : StringRepresentable, Hashable {
			bool isDirectory = false;
			bool isReadonly = false;
			bool isHidden = false;
			bool isSystem = false;
			FileAttributesTime time;
			DataSize size = DataSize::zero();

			FileAttributes() {}

			bool operator==(const FileAttributes& other) const {
				return isDirectory == other.isDirectory &&
					isReadonly == other.isReadonly &&
					isHidden == other.isHidden &&
					isSystem == other.isSystem &&
					time == other.time &&
					size == other.size;
			}

			virtual CString toString() const {
				return CString::format("directory = %s; size = %.1f MB", isDirectory ? "yes" : "no", size.inMB());
			}

			virtual ubig hashValue() const {
				return 0;
			}
		};
	};
};
