#pragma once

#include "../Easy.h"
#include "../Basic/Utilities.h"
#include "../Foundation/CString.h"
#include "../Collections/Collections.h"
#include "../Foundation/Number.h"
#include "Helpers/SampleTest.h"

namespace easy {
    namespace samples {
        struct BasicStructs1: SampleTest {
            bool performAll() {
                rangeTests1();
                return true;
            }

            void rangeTests1() {
                printLine("rangeTests1()");

                Range a = Range(1, 5);
                Range b = Range(6, 7);
                Range c = Range(3, 9);

                printLine("a.overlaps(b): %d", a.overlaps(b)); // f
                printLine("b.overlaps(c): %d", b.overlaps(c)); // t
                printLine("c.overlaps(a): %d", c.overlaps(a)); // t
                printLine("c.overlaps(c): %d", c.overlaps(c)); // t
                printLine("b.overlaps(a): %d", b.overlaps(a)); // f
            }
        };
    }
};
