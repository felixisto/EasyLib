#pragma once

#include "Samples.h"
#include "Helpers/SampleTest.h"

namespace easy {
    namespace samples {
        struct ToString1: SampleTest {
            bool performAll() {
                listNumbersTests1();
                listPointersTests1();
                return true;
            }

            void listNumbersTests1() {
                printLine("listNumbersTests1()");

                Vector<int> testList1;
                testList1.add(3);
                testList1.add(8);
                testList1.add(12321);

                List<Integer> testList2;
                testList2.add(77);
                testList2.add(0);
                testList2.add(23);
                testList2.add(77);
                testList2.add(5);
                testList2.add(8);
                testList2.add(77);

                printLine("testList1: %s", testList1.toString().buffer());
                printLine("testList2: %s", testList2.toString().buffer());
            }

            void listPointersTests1() {
                printLine("listPointersTests1()");

                auto numbers = SimpleNumbersSample();

                Vector<int*> testList1;
                testList1.add(&numbers.tenIntegers[0]);
                testList1.add(&numbers.tenIntegers[1]);
                testList1.add(&numbers.tenIntegers[2]);

                printLine("testList1: %s", testList1.toString().buffer());
            }
        };
    }
};
