#pragma once

#include "../../Easy.h"
#include "../../Basic/Utilities.h"
#include "../../Foundation/CString.h"
#include "../../Collections/Collections.h"
#include "../../Foundation/Number.h"
#include "../Helpers/SampleTest.h"

namespace easy {
    namespace samples {
        struct CollectionsStuff1: SampleTest {
            bool performAll() {
                removeElements1();
                iteratorList1();
                iteratorSet1();
                iteratorVector1();
                dict1();
                iteratorDict1();
                return true;
            }

            void removeElements1() {
                printLine("removeElements1()");

                List<Integer> testList1;
                testList1.add(77);
                testList1.add(0);
                testList1.add(23);
                testList1.add(77);
                testList1.add(5);
                testList1.add(8);
                testList1.add(77);

                printLine("testList1: %s", testList1.toString().buffer());

                printLine("testList remove at indexOf(77, 1)");
                printLine("testList1: %s", testList1.toString().buffer());

                testList1.removeAt(testList1.indexOf(77, 1));


                printLine("testList1 removeLast(77)");
                printLine("testList1: %s", testList1.toString().buffer());

                testList1.removeLast(77);

                printLine("testList1: %s", testList1.toString().buffer());

                SimpleSet<int> set2;
                set2.insert(35);
                set2.insert(100);
                set2.insert(-6);
                set2.insert(245);

                printLine("set2: %s", set2.toString().buffer());
            }

            void iteratorList1() {
                printLine("iteratorList1()");

                auto numbers = SimpleNumbersSample();

                Vector<int> testVector1;
                testVector1.addAll(numbers.tenIntegers, 10);

                auto iterator1 = testVector1.beginEnumeration();

                printLine("enumerate testVector1");
                while (iterator1.hasNext()) {
                    printLine("next = %d", iterator1.get());

                    iterator1++;
                }

                List<Integer> testList1;
                testList1.add(4);
                testList1.add(8);
                testList1.add(14);

                auto iterator2 = testList1.beginEnumeration();

                printLine("enumerate testList1");
                while (iterator2.hasNext()) {
                    printLine("next = %d", iterator2.get().value);

                    iterator2++;
                }
            }

            void iteratorSet1() {
                printLine("iteratorSet1()");

                auto numbers = SimpleNumbersSample();

                Set<Integer> testSet1;
                testSet1.insert(4);
                testSet1.insert(8);
                testSet1.insert(14);
                testSet1.insert(99);
                testSet1.insert(125);

                auto iterator1 = testSet1.beginEnumeration();

                printLine("enumerate testSet1");
                while (iterator1.hasNext()) {
                    printLine("next = %d", iterator1.get().value);

                    iterator1++;
                }
            }

            void iteratorVector1() {
                printLine("iteratorVector1()");

                auto numbers = SimpleNumbersSample();

                Vector<int> testV1;
                testV1.add(4);
                testV1.add(8);
                testV1.add(14);
                testV1.add(99);
                testV1.add(125);

                auto iterator1 = testV1.beginEnumeration();

                printLine("enumerate testV1");
                while (iterator1.hasNext()) {
                    printLine("next = %d", iterator1.get());

                    iterator1++;
                }

                auto iterator2 = testV1.beginEnumeration().reverse();

                printLine("enumerate reversed testV1");
                while (iterator2.hasNext()) {
                    printLine("next = %d", iterator2.get());

                    iterator2++;
                }

                auto iterator3 = testV1.beginEnumeration().reverse().reverse();

                printLine("enumerate testV1");
                while (iterator3.hasNext()) {
                    printLine("next = %d", iterator3.get());

                    iterator3++;
                }

                auto iterator4 = testV1.beginEnumeration().reverse().reverse().reverse();

                printLine("enumerate reversed testV1");
                while (iterator4.hasNext()) {
                    printLine("next = %d", iterator4.get());

                    iterator4++;
                }
            }

            void dict1() {
                printLine("dict1()");

                Dictionary<CString, Integer> testDict1;
                testDict1.insert("n", 4);
                testDict1.insert("z", 8);
                testDict1.insert("10", 14);
                testDict1.insert("xxx", 99);
                testDict1.insert("bla", 125);

                printLine("testDict1: %s", testDict1.toString().buffer());
                printLine("testDict1 hash: %llu", testDict1.hashValue());

                Dictionary<CString, Integer> testDict2;
                testDict2.insert("n", 4);
                testDict2.insert("z", 8);
                testDict2.insert("10", 14);
                testDict2.insert("xxx", 99);

                printLine("testDict2: %s", testDict2.toString().buffer());
                printLine("testDict2 hash: %llu", testDict2.hashValue());

                printLine("(testDict1 == testDict2) = %d", testDict1 == testDict2);

                testDict2.insert("bla", 125);

                printLine("add new entry, testDict2: %s", testDict2.toString().buffer());
                printLine("testDict2 hash: %llu", testDict2.hashValue());

                printLine("(testDict1 == testDict2) = %d", testDict1 == testDict2);
            }

            void iteratorDict1() {
                printLine("iteratorDict1()");

                Dictionary<CString, Integer> testDict1;
                testDict1.insert("n", 4);
                testDict1.insert("z", 8);
                testDict1.insert("10", 14);
                testDict1.insert("xxx", 99);
                testDict1.insert("bla", 125);

                auto iterator1 = testDict1.beginEnumeration();

                printLine("enumerate testDict1");
                while (iterator1.hasNext()) {
                    auto entry = iterator1.get();

                    printLine("next = '%s' = %s", entry.first.toString().buffer(), entry.second.toString().buffer());

                    iterator1++;
                }

                printLine("enumerate keys testDict1");
                auto keys = testDict1.keys();
                auto iterator2 = keys.beginEnumeration();

                while (iterator2.hasNext()) {
                    printLine("next = %s", iterator2.get().toString().buffer());

                    iterator2++;
                }

                printLine("enumerate values testDict1");
                auto values = testDict1.values();
                auto iterator3 = values.beginEnumeration();

                while (iterator3.hasNext()) {
                    printLine("next = %s", iterator3.get().toString().buffer());

                    iterator3++;
                }
            }
        };
    }
};
