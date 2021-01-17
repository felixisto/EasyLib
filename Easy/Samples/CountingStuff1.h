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
        struct CountingStuff1: SampleTest {
            bool performAll() {
                countingInts1();
                countingIntegers1();
                return true;
            }

            void countingInts1() {
                printLine("countingInts1()");

                auto numbers = SimpleNumbersSample();

                Vector<int> testList1;
                testList1.addAll(numbers.tenIntegers, 10);

                printLine("testList1: %s", testList1.toString().buffer());

                auto counting1 = Counting::count(testList1);

                printLine("average: %.3f; median: %.3f; sum: %.3f", counting1.average(), counting1.median(), counting1.sum());
                printLine("min: %.3f; max: %.3f; distance: %.3f", counting1.minimum(), counting1.maximum(), counting1.distance());
            }

            void countingIntegers1() {
                printLine("countingIntegers1()");

                SimpleSet<int> testSet1;
                testSet1.insert(10005);
                testSet1.insert(-5);
                testSet1.insert(70);
                testSet1.insert(3);
                testSet1.insert(666);

                printLine("testSet1: %s", testSet1.toString().buffer());

                auto counting1 = Counting::count(testSet1);

                printLine("average: %.3f; median: %.3f; sum: %.3f", counting1.average(), counting1.median(), counting1.sum());
                printLine("min: %.3f; max: %.3f; distance: %.3f", counting1.minimum(), counting1.maximum(), counting1.distance());
            }
        };
    }
};
