#pragma once

#include "../Samples.h"
#include "../Helpers/SampleTest.h"
#include "../../Tool/Stack.h"
#include "../../Basic/Parser.h"
#include "../../Collections/Utilities/Transformers.h"
#include "../../Collections/Filter/Filters.h"

namespace easy {
    namespace samples {
        struct MappingStuff1 : SampleTest {
            bool performAll() {
                convertTypes1();
                mapNumbers1();
                transformNumbers1();
                filterNumbers1();
                return true;
            }

            void convertTypes1() {
                printLine("convertTypes1()");

                int a = 150;
                double a_ = 0;
                SimpleParser<int, double> testList1Parser;
                a_ = testList1Parser.parse(a);

                printLine("convert int %d to double %f", a, a_);
            }

            void mapNumbers1() {
                printLine("mapNumbers1()");

                auto numbers = SimpleNumbersSample();

                Vector<int> testInts1;
                testInts1.addAll(numbers.tenIntegers, 10);
                Vector<real> testInts1AsReals;
                testInts1AsReals.mapTo(testInts1);

                printLine("convert vector<int> %s...", testInts1.toString().c());
                printLine("to vector<real> %s", testInts1AsReals.toString().c());

                SimpleSet<int> testReals1;
                testReals1.insert(10005);
                testReals1.insert(-5);
                testReals1.insert(70);
                testReals1.insert(3);
                testReals1.insert(666);

                SimpleSet<real> testReals1AsReals;
                testReals1AsReals.mapTo(testReals1);
                printLine("convert set<int> %s...", testReals1.toString().c());
                printLine("to set<real> %s", testReals1AsReals.toString().c());

                Dictionary<CString, Integer> testIntDict;
                testIntDict.insert("a", 105);
                testIntDict.insert("b", 777);
                testIntDict.insert("c", -55);

                Dictionary<CString, Real> testIntDictAsReals;
                testIntDictAsReals.mapTo(testIntDict);

                printLine("convert dict<int> %s...", testIntDict.toString().c());
                printLine("to dict<real> %s", testIntDictAsReals.toString().c());

                Dictionary<CString, Integer> testIntDictBack;
                testIntDictBack.mapTo(testIntDictAsReals);

                printLine("and back to dict<int> %s", testIntDictBack.toString().c());
            }

            void transformNumbers1() {
                printLine("transformNumbers1()");

                auto numbers = SimpleNumbersSample();

                Vector<int> testInts1;
                testInts1.addAll(numbers.tenIntegers, 10);
                printLine("transform vector<int> by adding 1 to %s...", testInts1.toString().c());
                testInts1.transform(TransformerAddition<int>(1));
                printLine("result: %s", testInts1.toString().c());

                List<Real> testReals1;
                testReals1.add(10005);
                testReals1.add(-5);
                testReals1.add(70);
                testReals1.add(3);
                testReals1.add(666);

                printLine("transform list<Real> by adding 1.25 to %s...", testReals1.toString().c());
                testReals1.transform(TransformerAddition<Real>(1.25));
                printLine("result: %s", testReals1.toString().c());

                Dictionary<CString, Integer> testIntDict;
                testIntDict.insert("a", 105);
                testIntDict.insert("b", 777);
                testIntDict.insert("c", -55);

                printLine("transform dict<cstring, Integer> by adding 1.25 to %s...", testIntDict.toString().c());
                testIntDict.transform(TransformerAddition<Integer>(1));
                printLine("result: %s", testIntDict.toString().c());
            }

            void filterNumbers1() {
                printLine("filterNumbers1()");

                List<Real> testReals1;
                testReals1.add(0);
                testReals1.add(-5);
                testReals1.add(0);
                testReals1.add(3);
                testReals1.add(4);

                printLine("filter by whichever equals 0, %s", testReals1.toString().c());
                auto filter1 = FilterEquality<Real>(0);
                testReals1 = testReals1.filterBy(filter1);
                printLine("result: %s", testReals1.toString().c());

                List<Real> testReals2;
                testReals2.add(0);
                testReals2.add(-5);
                testReals2.add(0);
                testReals2.add(3);
                testReals2.add(4);

                printLine("filter by whichever does not equal 0, %s", testReals2.toString().c());
                auto filter2 = FilterInequality<Real>(0);
                testReals2 = testReals2.filterBy(filter2);
                printLine("result: %s", testReals2.toString().c());

                List<Real> testReals3;
                testReals3.add(0);
                testReals3.add(-5);
                testReals3.add(0);
                testReals3.add(3);
                testReals3.add(4);
                testReals3.add(3);
                testReals3.add(88);

                printLine("filter by unique values, %s", testReals3.toString().c());
                auto filter3 = FilterByUnique<Real>();
                testReals3 = testReals3.filterBy(filter3);
                printLine("result: %s", testReals3.toString().c());
            }
        };
    }
};
