#pragma once

#include "../Easy.h"
#include "../Basic/Utilities.h"
#include "../Foundation/CString.h"
#include "../Collections/Collections.h"
#include "../Foundation/Number.h"
#include "Helpers/SampleTest.h"

namespace easy {
    namespace samples {
        struct StringTests1: SampleTest {
            bool performAll() {
                format1();
                addition1();
                replace1();
                split1();
                return true;
            }

            void format1() {
                printLine("format1()");

                auto result = stringFromFormat("%s", "testtest");

                printLine("stringFromFormat result = '%s'", result.c_str());
            }

            void addition1() {
                printLine("addition1()");

                CString a = "test one two three";

                printLine("string: '%s'", a.buffer());

                printLine("+= ' '");
                a += " ";

                printLine("string: '%s'", a.buffer());

                printLine("+= 'Pog'");
                a += "Pog";

                printLine("string: '%s'", a.buffer());

                printLine("+= 'Champ'");
                a += "Champ";

                printLine("string: '%s'", a.buffer());
            }

            void replace1() {
                printLine("replace1()");

                CString a = "test one two three";

                printLine("string: '%s'", a.buffer());

                printLine("replace all 'one' with 'three'");
                a.replaceAll("one", "three");

                printLine("string: '%s'", a.buffer());

                printLine("replace last 'three' with 'one'");
                a.replaceLast("three", "one");

                printLine("string: '%s'", a.buffer());

                printLine("replace first 'three' with 'one'");
                a.replaceFirst("three", "one");

                printLine("string: '%s'", a.buffer());

                printLine("replace all 'one' with 'two'");
                a.replaceAll("one", "two");

                printLine("string: '%s'", a.buffer());
            }

            void split1() {
                printLine("split1()");

                CString a = "test one two three";

                printLine("split string into words: '%s'", a.buffer());
                printLine("%s", a.split(" ").toString().buffer());

                printLine("split string with 't': '%s'", a.buffer());
                printLine("%s", a.split("t").toString().buffer());
            }
        };
    }
};
