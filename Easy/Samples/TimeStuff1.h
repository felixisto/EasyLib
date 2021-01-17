#pragma once

#include "../Easy.h"
#include "../Basic/Utilities.h"
#include "../Foundation/CString.h"
#include "Helpers/SampleTest.h"
#include "Data/SimpleNumbersSample.h"

namespace easy {
    namespace samples {
        struct TimeStuff1: SampleTest {
            time::TimeUnit unitYoctosec = time::TimeUnit::YOCTOSECOND();
            time::TimeUnit unitZeptosec = time::TimeUnit::ZEPTOSECOND();
            time::TimeUnit unitAttosec = time::TimeUnit::ATTOSECOND();
            time::TimeUnit unitFemsec = time::TimeUnit::FEMTOSECOND();

            time::TimeUnit unitPicosec = time::TimeUnit::PICOSECOND();
            time::TimeUnit unitNanosec = time::TimeUnit::NANOSECOND();
            time::TimeUnit unitMicrosec= time::TimeUnit::MICROSECOND();

            time::TimeUnit unitMS = time::TimeUnit::MILLISECOND();
            time::TimeUnit unitSecond = time::TimeUnit::SECOND();
            time::TimeUnit unitMin = time::TimeUnit::MINUTE();
            time::TimeUnit unitHR = time::TimeUnit::HOUR();
            time::TimeUnit unitDay = time::TimeUnit::DAY();

            time::TimeUnit unitCY = time::TimeUnit::COMMON_YEAR();

            bool performAll() {
                displayUnitTypes();
                displayFixedConversions();
                testTimeValue();
                testSmallTimeValue();
                testPunyTimeValue();
                return true;
            }

            void displayUnitTypes() {
                printLine("displayUnitTypes()");

                auto allTimeUnits = time::TimeUnit::ALL_VALUES();
                List<CString> values;

                for (int e = 0; e < (int)allTimeUnits.size(); e++) {
                    values.add(allTimeUnits[e].toString());
                }

                printLine("time units: %s", values.toString().buffer());
            }

            void displayFixedConversions() {
                printLine("displayFixedConversions()");

                printLine("1 Planck time unit = 0.000000000000000000000053912 sec");
                printLine("1 yoctosecond = 0.000000000000000000000001 sec");
                printLine("1 picosecond = 0.000000000001 sec");
                printLine("1 nanosecond = 0.000000001 sec");
                printLine("1 microsecond = 0.000001 sec");
                printLine("1 millisecond = 0.001 sec");
                printLine("1 minute = 60 sec");
                printLine("1 hour = 3600 sec");
                printLine("1 day = 86,400 sec");
                printLine("1 common year = 31,536,000 sec"); // 31536000
                printLine("1 century = 3,153,600,000 sec"); // 3153600000
                printLine("1 millennium = 31,536,000,000 sec"); // 31536000000
            }

            void testTimeValue() {
                printLine("testTimeValue()");

                TimeValue someTimeValue = TimeValue::fromSeconds(50000);

                auto sec = someTimeValue.inSeconds();
                auto unitName = unitSecond.pluralName();
                auto secName = unitName.c_str();
                
                printLine("%.1f %s is %llu %s", sec, secName, someTimeValue.inMilliseconds(), unitMS.pluralName().c_str());
                printLine("%.1f %s is %.1f %s", sec, secName, someTimeValue.inMinutes(), unitMin.pluralName().c_str());
                printLine("%.1f %s is %.1f %s", sec, secName, someTimeValue.inHours(), unitHR.pluralName().c_str());
                printLine("%.1f %s is %.3f %s", sec, secName, someTimeValue.inDays(), unitDay.pluralName().c_str());

                // Max limit test
                someTimeValue = TimeValue::fromCommonYears(100000);
                sec = someTimeValue.inSeconds();

                printLine("%f %s is %f %s", sec, secName, someTimeValue.inCommonYears(), unitCY.pluralName().c_str());
            }

            void testSmallTimeValue() {
                printLine("testSmallTimeValue()");

                SmallTimeValue someTimeValue = SmallTimeValue::fromMilliseconds(50000);

                auto ms = someTimeValue.inMilliseconds();
                auto unitName = unitMS.pluralName();
                auto msName = unitName.c_str();

                printLine("base unit is milliseconds");
                printLine("%llu %s is %llu %s", ms, msName, someTimeValue.inMicroseconds(), unitMicrosec.pluralName().c_str());
                printLine("%llu %s is %llu %s", ms, msName, someTimeValue.inNanoseconds(), unitNanosec.pluralName().c_str());
                printLine("%llu %s is %llu %s", ms, msName, someTimeValue.inPicoseconds(), unitPicosec.pluralName().c_str());

                // Max limit test
                someTimeValue = SmallTimeValue::fromSeconds(10000000);
                printLine("%llu %s is %llu %s", someTimeValue.inPicoseconds(), unitPicosec.pluralName().c_str(), someTimeValue.inSeconds(), unitSecond.pluralName().c_str());
            }

            void testPunyTimeValue() {
                printLine("testPunyTimeValue()");

                PunyTimeValue someTimeValue = PunyTimeValue::fromZeptoseconds(40000000000);

                auto zs = someTimeValue.inZeptoseconds();
                auto unitName = unitZeptosec.pluralName();
                auto zsName = unitName.c_str();

                printLine("base unit is yoctoseconds");
                printLine("%llu %s is %llu %s", zs, zsName, someTimeValue.inYoctoseconds(), unitYoctosec.pluralName().c_str());
                printLine("%llu %s is %llu %s", zs, zsName, someTimeValue.inAttoseconds(), unitAttosec.pluralName().c_str());
                printLine("%llu %s is %llu %s", zs, zsName, someTimeValue.inFemtoseconds(), unitFemsec.pluralName().c_str());
                printLine("%llu %s is %llu %s", zs, zsName, someTimeValue.inPicoseconds(), unitPicosec.pluralName().c_str());

                // Max limit test
                someTimeValue = PunyTimeValue::fromPicoseconds(10000000);
                printLine("%llu %s is %llu %s", someTimeValue.inYoctoseconds(), unitYoctosec.pluralName().c_str(), someTimeValue.inPicoseconds(), unitPicosec.pluralName().c_str());
            }
        };
    }
};
