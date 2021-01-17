#pragma once

#include "../../Tool/Logging.h"

namespace easy {
    namespace samples {
        static void printLine(const char* format, ...) {
            std::string string;
            STDSTRING_FORMAT(string, format);

            LogOptions options = LogOptions::minimal();
            Logging::standard().printInfo(options, string.c_str());
        }

        static void printLineWithTime(const char* format, ...) {
            std::string string;
            STDSTRING_FORMAT(string, format);

            LogOptions options = LogOptions::standard();
            options.printThread = true;
            Logging::standard().printInfo(options, string.c_str());
        }
    };
};
