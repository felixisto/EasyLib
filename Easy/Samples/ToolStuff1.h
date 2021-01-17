#pragma once

#include "Samples.h"
#include "Helpers/SampleTest.h"
#include "../Tool/Stack.h"

namespace easy {
    namespace samples {
        struct ToolStuff1: SampleTest {
            bool performAll() {
                testStackCurrentLine();
                testStackTraceInfo();
                return true;
            }

            void testStackCurrentLine() {
                printLine("testStackCurrentLine()");

                CString line;
                stackTraceCurrentLine(line, "");
                printLine("stack tace: %s", line.buffer());
            }

            void testStackTraceInfo() {
                printLine("testStackTraceInfo()");

                testStackTraceInfoStep1();
            }

            void testStackTraceInfoStep1() {
                testStackTraceInfoStep2();
            }

            void testStackTraceInfoStep2() {
                testStackTraceInfoStep3();
            }

            void testStackTraceInfoStep3() {
                printLine("stack tace: %s", Stack::stackTrace().c_str());
            }
        };
    }
};
