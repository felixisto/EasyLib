#pragma once

#include "../Easy.h"
#include "../Basic/Utilities.h"
#include "../Foundation/CString.h"
#include "../Collections/Collections.h"
#include "../Foundation/Number.h"
#include "Helpers/SampleTest.h"
#include "Data/SimpleNumbersSample.h"

namespace easy {
    namespace samples {
        struct Limits1: SampleTest {
            bool performAll() {
                showIntLimits1();
                showRealLimits1();
                return true;
            }

            void showIntLimits1() {
                printLine("showIntLimits1()");

                printLine("min signed int: %d", Integer::MINIMUM().value);
                printLine("max signed int: %d", Integer::MAXIMUM().value);
                printLine("min unsgined int: %lu", UInteger::MINIMUM().value);
                printLine("max unsgined int: %lu", UInteger::MAXIMUM().value);
                printLine("min signed big: %lld", Big::MINIMUM().value);
                printLine("max signed big: %lld", Big::MAXIMUM().value);
                printLine("min unsgined big: %llu", UBig::MINIMUM().value);
                printLine("max unsgined big: %llu", UBig::MAXIMUM().value);
            }

            void showRealLimits1() {
                printLine("showRealLimits1()");

                printLine("min float: %f", Float::MINIMUM().value);
                printLine("max float: %f", Float::MAXIMUM().value);
                printLine("min real: %f", Real::MINIMUM().value);
                printLine("max real: %f", Real::MAXIMUM().value);
            }
        };
    }
};
