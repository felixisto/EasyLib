#pragma once

// General stuff
#include "../Easy.h"
#include "../Basic/Utilities.h"
#include "../Foundation/CString.h"
#include "../Collections/Collections.h"
#include "../Foundation/Number.h"

// Data
#include "Data/SimpleNumbersSample.h"

// Samples
#include "Stuff/ToString1.h"
#include "Stuff/CountingStuff1.h"
#include "Stuff/CollectionsStuff1.h"
#include "Stuff/Buffer1.h"
#include "Stuff/SortingStuff1.h"
#include "Stuff/SortingPerformance1.h"
#include "Stuff/OverflowStuff1.h"
#include "Stuff/SmallCharsetStuff1.h"
#include "Stuff/StringTests1.h"
#include "Stuff/ToolStuff1.h"
#include "Stuff/FileSystemStuff1.h"
#include "Stuff/Limits1.h"
#include "Stuff/TimeStuff1.h"
#include "Stuff/TimeFormatterStuff1.h"
#include "Stuff/MappingStuff1.h"

namespace easy {
	namespace samples {
		struct AllBasicSamples: SampleTest {
			bool performAll() {
				bool result = true;
				result &= samples::Buffer1().performAll();
				result &= samples::OverflowStuff1().performAll();
				result &= samples::Limits1().performAll();
				return result;
			}
		};

		struct AllFoundationSamples: SampleTest {
			bool performAll() {
				bool result = true;
				result &= samples::SmallCharsetStuff1().performAll();
				result &= samples::StringTests1().performAll();
				return result;
			}
		};

		struct AllFormattersSamples: SampleTest {
			bool performAll() {
				bool result = true;
				result &= samples::ToString1().performAll();
				return result;
			}
		};

		struct AllCollectionsSamples: SampleTest {
			bool performAll() {
				bool result = true;
				result &= samples::CountingStuff1().performAll();
				result &= samples::CollectionsStuff1().performAll();
				return result;
			}
		};

		struct AllConcurrencySamples: SampleTest {
		public:
			bool performAll() {
				bool result = true;

				return result;
			}
		};

		struct AllFileSystemSamples: SampleTest {
		public:
			bool performAll() {
				bool result = true;
				result &= samples::FileSystemStuff1().performAll();
				return result;
			}
		};

		struct AllSortingSamples: SampleTest {
		public:
			bool performAll() {
				bool result = true;
				result &= samples::SortingStuff1().performAll();
				result &= samples::SortingPerformance1().performAll();
				return result;
			}
		};

		struct AllToolsPerformanceSamples: SampleTest {
			bool performAll() {
				bool result = true;
				result &= samples::ToolStuff1().performAll();
				return result;
			}
		};

		struct AllTimeSamples: SampleTest {
			bool performAll() {
				bool result = true;
				result &= samples::TimeStuff1().performAll();
				result &= samples::TimeFormatterStuff1().performAll();
				return result;
			}
		};

		struct ConvertSamples : SampleTest {
			bool performAll() {
				bool result = true;
				result &= samples::MappingStuff1().performAll();
				return result;
			}
		};

		struct AllSamples: SampleTest {
			bool performAll() {
				bool result = true;
				result &= performBasic();
				return result;
			}

			bool performBasic() {
				bool result = true;
				auto basicSamples = AllBasicSamples();
				auto foundSamples = AllFoundationSamples();
				auto formattersSamples = AllFormattersSamples();
				auto collSamples = AllCollectionsSamples();
				auto concSamples = AllConcurrencySamples();
				auto fsSamples = AllFileSystemSamples();
				auto sortingSamples = AllSortingSamples();
				auto toolSamples = AllToolsPerformanceSamples();
				auto timeSamples = AllTimeSamples();
				auto convertSamples = ConvertSamples();

				result &= basicSamples.performAll();
				result &= foundSamples.performAll();
				result &= formattersSamples.performAll();
				result &= collSamples.performAll();
				result &= concSamples.performAll();
				result &= fsSamples.performAll();
				result &= sortingSamples.performAll();
				result &= toolSamples.performAll();
				result &= timeSamples.performAll();
				result &= convertSamples.performAll();

				return result;
			}
		};
	}
};
