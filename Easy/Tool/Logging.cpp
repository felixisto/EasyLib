
#include "Logging.h"
#include "../Basic/Utilities.h"
#include "../Foundation/Date.h"
#include "../Concurrency/Thread.h"

using namespace easy;

void LoggingDefaultWriteOutput(cstring message) {
    printf("%s", message);
}

Logging::Logging() {
    logFunc.set(LoggingDefaultWriteOutput);
}

Logging& Logging::standard() {
    static Logging log;
    return log;
}

void Logging::print(const LogOptions& options, cstring tag, cstring format, ...) const {
    auto separator = getSeparator();

    std::string string;
    STDSTRING_FORMAT(string, format);

    CString prefix;

    if (options.printAppName) {
        auto appName = getAppName();

        if (appName.length() > 0) {
            prefix += appName;
            prefix += separator;
        }
    }

    if (options.printThread) {
        auto name = CurrentThread::info().name;
        prefix += CString::format("%s", name.buffer());
        prefix += separator;
    }

    if (options.printTimestamp) {
        Date date = Date::now();
        auto formatter = DateFormatter(date);
        formatter.format = formatter.timestampFormat();
        auto timestamp = formatter.toString();

        prefix += timestamp;
        prefix += separator;
    }

    if (options.printTag && strlen(tag) > 0) {
        prefix += std::string(tag);
        prefix += separator.asSTDString();
    }

    if (separator.length() > 0 && !prefix.isEmpty()) {
        prefix += CString::WHITE_SPACE;
    }

    if (options.newLine) {
        string += '\n';
    }

    string.insert(0, prefix.asSTDString());

    writeToOutput(string.c_str());
}

void Logging::print(cstring tag, cstring format, ...) const {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(getOptions(), tag, string.c_str());
}

void Logging::printInfo(const LogOptions& options, cstring format, ...) const {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(options, getTagInfo().buffer(), string.c_str());
}

void Logging::printInfo(cstring format, ...) const {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(getOptions(), getTagInfo().buffer(), string.c_str());
}

void Logging::printWarning(const LogOptions& options, cstring format, ...) const {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(options, getTagWarning().buffer(), string.c_str());
}

void Logging::printWarning(cstring format, ...) const {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(getOptions(), getTagWarning().buffer(), string.c_str());
}

void Logging::printError(const LogOptions& options, cstring format, ...) const {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(options, getTagError().buffer(), string.c_str());
}

void Logging::printError(cstring format, ...) const {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(getOptions(), getTagError().buffer(), string.c_str());
}

void Logging::writeToOutput(cstring string) const {
    logFunc.get()(string);
}

// # Modify functionality

LogOptions Logging::getOptions() const {
    return options.get();
}

void Logging::setOptions(const LogOptions& options) {
    this->options.set(options);
}

CString Logging::getSeparator() const {
    return separator.get();
}

void Logging::setSeparator(const CString& value) {
    separator.set(value);
}

CString Logging::getAppName() const {
    return appName.get();
}

void Logging::setAppName(const CString& value) {
    appName.set(value);
}

CString Logging::getTagInfo() const {
    return TAG_INFO.get();
}

void Logging::setTagInfo(const CString& value) {
    TAG_INFO.set(value);
}

CString Logging::getTagWarning() const {
    return TAG_WARNING.get();
}

void Logging::setTagWarning(const CString& value) {
    TAG_WARNING.set(value);
}

CString Logging::getTagError() const {
    return TAG_ERROR.get();
}

void Logging::setTagError(const CString& value) {
    TAG_ERROR.set(value);
}

void Logging::setWriteToOutputFunc(LoggingOutput func) {
    logFunc = func;
}

/*
namespace easy {
    void Log(cstring format, ...)
    {
        FILE* logFile = GetLogFile();
        std::string& ouput = LogOutput();

        std::string string;

        // Variadic arguments
        uinteger ____length = 0;
        char ____str[1000];
        va_list vl;
        va_start(vl, format);
        ____length = vsnprintf(____str, sizeof(____str), format, vl);
        va_end(vl);
        char* ____string = (char*)malloc((____length + 1));
        va_start(vl, format);
        vsnprintf(____string, (____length + 1), format, vl);
        va_end(vl);
        if (____string != nullptr) {
            string = std::string(____string);
        }
        free(____string);

        // String
        cstring str = string.c_str();

        easy::Time time = easy::Time::systemTime();

        str = easy::CString("|%02d:%02d:%02d| %s", time.hour, time.minute, time.second, str);

        // Standart output
        auto log = getLogFunction();
        log(str);

        // Log file
        if (logFile)
        {
            fprintf(logFile, "%s\n", str);
            fflush(logFile);

            ouput += std::string(str);
        }

        delete str;
    }

    void LogNoTimestamp(cstring format, ...)
    {
        FILE* logFile = GetLogFile();
        std::string& ouput = LogOutput();

        std::string string;

        // Variadic arguments
        uinteger ____length = 0;
        char ____str[1000];
        va_list vl;
        va_start(vl, format);
        ____length = vsnprintf(____str, sizeof(____str), format, vl);
        va_end(vl);
        char* ____string = (char*)malloc((____length + 1));
        va_start(vl, format);
        vsnprintf(____string, (____length + 1), format, vl);
        va_end(vl);
        if (____string != nullptr) {
            string = std::string(____string);
        }
        free(____string);

        // Standart output
        cstring str = string.c_str();
        auto log = getLogFunction();
        log(str);

        // Log file
        if (logFile)
        {
            fprintf(logFile, "%s\n", str);
            fflush(logFile);

            ouput += string;
        }
    }

    void Assert(bool expression, cstring error, ...) {
        if (expression)
        {
            return;
        }

        std::string string;

        // Variadic arguments
        uinteger ____length = 0;
        char ____str[1000];
        va_list vl;
        va_start(vl, error);
        ____length = vsnprintf(____str, sizeof(____str), error, vl);
        va_end(vl);
        char* ____string = (char*)malloc((____length + 1));
        va_start(vl, error);
        vsnprintf(____string, (____length + 1), error, vl);
        va_end(vl);
        if (____string != nullptr) {
            string = std::string(____string);
        }
        free(____string);

        // Assert
        cstring str = easy::CString("|ASSERT| %s", string.c_str());
        Log(str);
        delete str;
        PrintStackTrace();
        assert(expression);
    }

    void Warning(bool expression, cstring warning, ...) {
        if (expression)
        {
            return;
        }

        std::string string;

        // Variadic arguments
        uinteger ____length = 0;
        char ____str[1000];
        va_list vl;
        va_start(vl, warning);
        ____length = vsnprintf(____str, sizeof(____str), warning, vl);
        va_end(vl);
        char* ____string = (char*)malloc((____length + 1));
        va_start(vl, warning);
        vsnprintf(____string, (____length + 1), warning, vl);
        va_end(vl);
        if (____string != nullptr) {
            string = std::string(____string);
        }
        free(____string);

        // Warn
        cstring str = easy::CString("|WARNING| %s", string.c_str());
        Log(str);
        delete str;
        PrintStackTrace();
        assert(expression);
    }

    UTPrintFunction& getLogFunction() {
        static UTPrintFunction function = &defaultPrintFunction;

        return function;
    }

    void setLogFunction(UTPrintFunction function) {
        getLogFunction() = function;
    }

    void defaultPrintFunction(cstring string) {
        printf(string);
        printf("\n");
    }

    FILE* GetLogFile(cstring name)
    {
        static FILE* logFile = nullptr;

        if (!logFile)
        {
            if (name)
            {
                auto openSuccess = fopen_s(&logFile, name, "r");

                if (openSuccess != 0) {
                    return nullptr;
                }

                if (logFile)
                {
                    cstring oldLogFileName = easy::CString("%s (old)", name);
                    FILE* oldLogFile = nullptr;

                    openSuccess = fopen_s(&oldLogFile, oldLogFileName, "w");

                    delete oldLogFileName;

                    if (openSuccess != 0 && oldLogFile != nullptr)
                    {
                        character* contents = nullptr;
                        ubig size = 0;

                        fseek(logFile, 0, SEEK_END);
                        size = ftell(logFile);
                        fseek(logFile, 0, SEEK_SET);
                        contents = new character[size];
                        fread(contents, (size_t)sizeof(character), size, logFile);

                        fwrite(contents, 1, size, oldLogFile);

                        delete[] contents;

                        fclose(oldLogFile);
                    }

                    fclose(logFile);
                }

                // Open and immediately close, just to erase the contents, so we can start a new log session.
                openSuccess = fopen_s(&logFile, name, "w");

                if (openSuccess == 0) {
                    fclose(logFile);
                }

                fopen_s(&logFile, name, "a");
            }
        }

        return logFile;
    }

    FILE* GetLogFile()
    {
        return GetLogFile(nullptr);
    }

    std::string& LogOutput()
    {
        static std::string output;

        return output;
    }

    void PrintStackTrace()
    {

    }

    cstring PrintStackTrace_(byte count)
    {
        return "";
    }

}
*/