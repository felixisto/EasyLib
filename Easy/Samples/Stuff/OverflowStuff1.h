#pragma once

#include "../../Easy.h"
#include "../../Basic/Utilities.h"
#include "../../Foundation/CString.h"
#include "../../Collections/Collections.h"
#include "../../Foundation/Number.h"
#include "../Helpers/SampleTest.h"
#include "../Data/SimpleNumbersSample.h"

namespace easy {
    namespace samples {
        struct OverflowStuff1: SampleTest {
            bool performAll() {
                overflowInt1();
                return true;
            }

            void overflowInt1() {
                printLine("overflowInt1()");

                uinteger xx = UInteger::MAXIMUM().value;
                UInteger a = UInteger::MAXIMUM();
                UInteger b = UInteger::MAXIMUM();
                a -= 9;
                b -= 1;

                printLine("a = %s", a.toString().buffer());
                printLine("b = %s", b.toString().buffer());

                //a.addOverflowSafe(5);
                //a.addOverflowSafe(1);

                printLine("a + 5 (safe) = %s", a.toString().buffer());
                printLine("b + 1 (safe) = %s", b.toString().buffer());

                //a.addOverflowSafe(5);
                //a.addOverflowSafe(1);

                printLine("a + 5 (safe) = %s", a.toString().buffer());
                printLine("b + 1 (safe) = %s", b.toString().buffer());
            }
        };
    }
};
