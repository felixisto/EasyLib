#pragma once

#include "../Samples.h"
#include "../Helpers/SampleTest.h"
#include "../../Tool/Stack.h"
#include "../../Basic/Parser.h"

namespace easy {
    namespace samples {
        struct MappingStuff1 : SampleTest {
            bool performAll() {
                convertTypes1();
                mapNumbers1();
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
        };
    }
};
