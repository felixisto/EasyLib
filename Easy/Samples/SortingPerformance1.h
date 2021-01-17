#pragma once

#include "../Easy.h"
#include "../Foundation/CString.h"
#include "../Collections/Collections.h"
#include "../Foundation/Number.h"
#include "Helpers/SampleTest.h"
#include "Data/SimpleNumbersSample.h"
#include "../Math/Sorting/CheckSort.h"
#include "../Math/Sorting/ReverseSort.h"
#include "../Math/Sorting/BubbleSort.h"
#include "../Math/Sorting/InsertionSort.h"
#include "../Math/Sorting/SelectionSort.h"
#include "../Math/Sorting/MergeSort.h"
#include "../Math/Sorting/QuickSort.h"
#include "../Math/Sorting/HeapSort.h"

namespace easy {
    namespace samples {
        struct SortingPerformance1: SampleTest {
        private:
            math::Random random;

            integer randomInt(integer min, integer max) {
                return random.integerValue(min, max);
            }

            integer randomInt() {
                return randomInt(0, 5000);
            }

            real randomReal(real min, real max) {
                return random.realValue(min, max);
            }

            real randomReal() {
                return randomReal(0, 5000);
            }
        public:
            bool performAll() {
                runSortingRace1000Random();
                runSortingRace10000Random();
                runSortingRace50000Random();
                return true;
            }

            void runSortingRace1000Random() {
                printLine("runSortingRace1000Random()");
                runSortingRaceWithRandomValues(1000);
            }

            void runSortingRace10000Random() {
                printLine("runSortingRace10000Random()");
                runSortingRaceWithRandomValues(10000);
            }

            void runSortingRace50000Random() {
                printLine("runSortingRace50000Random()");
                runSortingRaceWithRandomValues(50000);
            }

            void runSortingRaceWithRandomValues(int count) {
                Vector<int> data;

                for (int e = 0; e < count; e++) {
                    data.add(randomInt());
                }

                bool runSlowOnes = count < 5000 ? true : false;

                runSortingRace(data, runSlowOnes, runSlowOnes);
            }

            void runSortingRace(const Vector<int>& data, bool bubbleSort, bool insertionSort) {
                printLine("runSortingRace()");

                Vector<int> dataCopy = data;

                if (bubbleSort) {
                    printLineWithTime("BubbleSort begin");
                    BubbleSorting::sortIterator(dataCopy.beginMutableEnumeration());
                    printLineWithTime("BubbleSort end");

                    if (!CheckSorting::isIteratorSorted(dataCopy.beginEnumeration())) {
                        printLineWithTime("Error! Sorting failed!");
                    }

                    dataCopy = data;
                }

                printLineWithTime("SelectionSort begin");
                SelectionSorting::sortIterator(dataCopy.beginMutableEnumeration());
                printLineWithTime("SelectionSort end");

                if (!CheckSorting::isIteratorSorted(dataCopy.beginEnumeration())) {
                    printLineWithTime("Error! Sorting failed!");
                }

                dataCopy = data;

                printLineWithTime("QuickSort begin");
                QuickSorting::sortIterator(dataCopy.beginMutableEnumeration());
                printLineWithTime("QuickSort end");

                if (!CheckSorting::isIteratorSorted(dataCopy.beginEnumeration())) {
                    printLineWithTime("Error! Sorting failed!");
                }

                dataCopy = data;

                printLineWithTime("MergeSort begin");
                MergeSorting::sortIterator(dataCopy.beginMutableEnumeration());
                printLineWithTime("MergeSort end");

                if (!CheckSorting::isIteratorSorted(dataCopy.beginEnumeration())) {
                    printLineWithTime("Error! Sorting failed!");
                }

                dataCopy = data;

                if (insertionSort) {
                    printLineWithTime("InsertionSort begin");
                    InsertionSorting::sortIterator(dataCopy.beginMutableEnumeration());
                    printLineWithTime("InsertionSort end");

                    if (!CheckSorting::isIteratorSorted(dataCopy.beginEnumeration())) {
                        printLineWithTime("Error! Sorting failed!");
                    }

                    dataCopy = data;
                }

                printLineWithTime("HeapSort begin");
                HeapSorting::sortIterator(dataCopy.beginMutableEnumeration());
                printLineWithTime("HeapSort end");

                if (!CheckSorting::isIteratorSorted(dataCopy.beginEnumeration())) {
                    printLineWithTime("Error! Sorting failed!");
                }
            }
        };
    }
};
