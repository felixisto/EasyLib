#pragma once

#include "../Easy.h"
#include "../Formatters/TimeFormatter.h"
#include "Helpers/SampleTest.h"
#include "Data/SimpleNumbersSample.h"

namespace easy {
    namespace samples {
        struct TimeFormatterStuff1 : SampleTest {
            bool performAll() {
                formatSmallTimeValues1();
                formatBigTimeValues1();
                return true;
            }

            void formatSmallTimeValues1() {
                printLine("formatSmallTimeValues1()");

                TimeFormatter formatter = TimeFormatter();
                formatter.printTimeUnitName = true;
                CString result;

                result = formatter.mostAppropriateStringFor(TimeValue::fromMinutes(5));
                printLine("5 minutes formatted: %s", result.buffer());

                result = formatter.mostAppropriateStringFor(TimeValue::fromSeconds(33));
                printLine("33 sec formatted: %s", result.buffer());

                result = formatter.mostAppropriateStringFor(TimeValue::fromHours(2.5));
                printLine("2.5 hours formatted: %s", result.buffer());
            }

            void formatBigTimeValues1() {
                printLine("formatBigTimeValues1()");

                TimeFormatter formatter = TimeFormatter();
                formatter.printTimeUnitName = true;
                CString result;

                result = formatter.mostAppropriateStringFor(TimeValue::fromDays(7));
                printLine("7 days formatted: %s", result.buffer());

                result = formatter.mostAppropriateStringFor(TimeValue::fromCommonYears(1));
                printLine("1 common year formatted: %s", result.buffer());

                result = formatter.mostAppropriateStringFor(TimeValue::fromCommonYears(500));
                printLine("500 common years formatted: %s", result.buffer());
            }
        };
    }
};
