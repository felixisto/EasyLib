#pragma once

#include "../../Easy.h"
#include "../../Foundation/CString.h"
#include "../../Collections/Collections.h"
#include "../../Foundation/Number.h"
#include "../Helpers/SampleTest.h"
#include "../Data/SimpleNumbersSample.h"

namespace easy {
    namespace samples {
        struct SortingStuff1: SampleTest {
            bool performAll() {
                sortingInts1();
                sortingIntegers1();
                return true;
            }

            void sortingInts1() {
                printLine("sortingInts1()");

                auto numbers = SimpleNumbersSample();

                Vector<int> testList1;
                testList1.add(10005);
                testList1.add(-5);
                testList1.add(70);
                testList1.add(3);
                testList1.add(666);
                testList1.add(9);
                testList1.add(-77);
                testList1.add(0);
                testList1.add(100);

                printLine("testList1 unsorted: %s", testList1.toString().buffer());

                auto sorting1 = Sorting::sort(testList1);

                sorting1.sortByAscending();

                printLine("testList1 sorted (Asc): %s", testList1.toString().buffer());

                sorting1.sortByDescending();

                printLine("testList1 sorted (Desc): %s", testList1.toString().buffer());

                Vector<int> testList2;
                testList2.add(10005);
                testList2.add(-5);
                testList2.add(70);
                testList2.add(3);
                testList2.add(666);
                testList2.add(9);
                testList2.add(-77);
                testList2.add(0);
                testList2.add(100);

                printLine("testList2 unsorted: %s", testList2.toString().buffer());

                testList2.sortByAscending();

                printLine("testList2 sorted (Asc): %s", testList2.toString().buffer());

                testList2.sortByDescending();

                printLine("testList2 sorted (Desc): %s", testList2.toString().buffer());
            }

            void sortingIntegers1() {
                printLine("sortingIntegers1()");

                List<Integer> testList1;
                testList1.add(10005);
                testList1.add(-5);
                testList1.add(70);
                testList1.add(3);
                testList1.add(666);
                testList1.add(9);
                testList1.add(-77);
                testList1.add(0);
                testList1.add(100);

                printLine("testList1: %s", testList1.toString().buffer());

                printLine("testList1 unsorted: %s", testList1.toString().buffer());

                auto sorting1 = Sorting::sort(testList1);

                printLine("isSorted testList1? %d", sorting1.isSorted());

                sorting1.sortByAscending();

                printLine("testList1 sorted (Asc): %s", testList1.toString().buffer());
                printLine("isSorted testList1? %d", sorting1.isSorted());

                sorting1.sortByDescending();

                printLine("testList1 sorted (Desc): %s", testList1.toString().buffer());
                printLine("isSorted testList1? %d", sorting1.isSorted());
            }
        };
    }
};
