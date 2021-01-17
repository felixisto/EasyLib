#pragma once

#include "../Easy.h"
#include "../Basic/Utilities.h"
#include "../Foundation/CString.h"
#include "../Foundation/CharacterSet.h"
#include "Helpers/SampleTest.h"

namespace easy {
	namespace samples {
        struct SmallCharsetStuff1: SampleTest {
            CharacterSetASCII set = CharacterSetASCII::standard();

            bool performAll() {
                printAll();
                printAlpha();
                printNumerical();
                printSymbols();
                return true;
            }

            void printAll() {
                printLine("printAll()");

                SimpleSet<character> values = set.enumerateHumanReadable();

                printLine("ascii total size: %d", set.count());
                printLine("ascii human readable: %s", values.toString().buffer());
            }

            void printAlpha() {
                printLine("printAlpha()");

                SimpleSet<character> values = set.enumerateAlphabetical();

                printLine("ascii alpha: %s", values.toString().buffer());

                values = set.enumerateAlphabeticalLowercase();

                printLine("ascii alpha lower: %s", values.toString().buffer());

                values = set.enumerateAlphabeticalUppercase();

                printLine("ascii alpha upper: %s", values.toString().buffer());
            }

            void printNumerical() {
                printLine("printNumerical()");

                SimpleSet<character> values = set.enumerateNumerical();

                printLine("ascii numerical: %s", values.toString().buffer());
            }

            void printSymbols() {
                printLine("printSymbols()");

                SimpleSet<character> values = set.enumerateSymbols();

                printLine("ascii symbols: %s", values.toString().buffer());
            }
        };
	};
};
