
#include "Logging.h"
#include "../../Basic/Utilities.h"
#include "../../Foundation/Date.h"
#include "../../Collections/Array/Vector.h"
#include "../../Concurrency/Thread.h"
#include "../../FileSystem/DirectoryService.h"

using namespace easy;

// # LogOptions

LogOptions LogOptions::standard() {
    return LogOptions();
}

LogOptions LogOptions::minimal() {
    auto options = LogOptions();
    options.printTag = false;
    options.printTimestamp = false;
    return options;
}

LogOptions LogOptions::rawString() {
    auto options = LogOptions();
    options.printTag = false;
    options.printTimestamp = false;
    options.printAppName = false;
    options.printThread = false;
    return options;
}

LogOptions LogOptions::rawStringNoNewLine() {
    auto options = rawString();
    options.newLine = false;
    return options;
}

// # LogFileWriteOptions

LogFileWriteOptions LogFileWriteOptions::standard() {
    LogFileWriteOptions options;
    options.enabled = false;
    options.basePath = fs::Path::appDirectory();
    options.logsFolderName = "logs";
    options.insertDateInLogFileName = true;
    options.maxLogFiles = 10;
    options.logFileFormat = "log";
    return options;
}

// # LogFileWriter

struct LogFileFilter: Filter<fs::Path> {
    CString fileFormat;

    LogFileFilter(const CString& fileFormat) : fileFormat(fileFormat) {

    }

    virtual bool filter(const fs::Path& arg) {
        CString suffix = CString(".") + fileFormat;
        return arg.absolute().endsWith(suffix);
    }
};

LogFileWriter::LogFileWriter() {
    _file = nullptr;
    _outputStream = nullptr;
    options.set(LogFileWriteOptions::standard());
}

LogFileWriter::~LogFileWriter() {
    if (_outputStream != nullptr) {
        _outputStream->close();
    }

    delete _file;
}

CString LogFileWriter::getCurrentLogName() const {
    auto options = this->options.get();

    CString name = options.logFileNamePrefix;

    if (options.insertDateInLogFileName) {
        auto formatter = DateFormatter(Date());
        formatter.format = DateFormatter::timestampFileFriendlyFormat();
        name += formatter.toString();
    }

    name += ".";
    name += options.logFileFormat;

    return name;
}

fs::Path LogFileWriter::getCurrentLogPath() const {
    fs::Path base = getCurrentLogDirectory();
    base = base.pathByAppendingComponent(getCurrentLogName());
    return base;
}

fs::Path LogFileWriter::getCurrentLogDirectory() const {
    auto options = this->options.get();
    fs::Path base = options.basePath;

    if (!options.logsFolderName.isEmpty()) {
        base = base.pathByAppendingComponent(options.logsFolderName);
    }
    return base;
}

void LogFileWriter::createLogFileIfNeeded() {
    if (_file != nullptr) {
        return;
    }

    bool isCurrentInLogsFolder = !options.get().logsFolderName.isEmpty();

    if (isCurrentInLogsFolder) {
        eraseLogFilesOverCapacity();
    }

    fs::Path logPath = getCurrentLogPath();

    _file = new fs::File(fs::File::createFromPath(logPath));

    auto openError = _file->openForWriting();

    if (openError != nullptr) {
        return;
    }

    _outputStream = _file->outputStream();
}

void LogFileWriter::eraseLogFilesOverCapacity() {
    auto& directoryService = fs::DirectoryService::standard();

    auto options = this->options.get();

    if (options.maxLogFiles == 0) {
        return;
    }

    fs::DirectoryScanFilter filesFilter;
    fs::Path logsDirectory = getCurrentLogDirectory();
    auto contents = directoryService.directoryContents(logsDirectory, filesFilter);
    LogFileFilter filter = LogFileFilter(options.logFileFormat);
    contents = contents.filterBy(filter);

    if (contents.isEmpty()) {
        return;
    }

    int filesToKeep = options.maxLogFiles;

    if (contents.size() < filesToKeep) {
        return;
    }

    struct {
        bool operator()(const fs::Path& a, const fs::Path& b) const {
            auto fileA = fs::File::createFromPath(a);
            auto fileB = fs::File::createFromPath(b);
            return fileA.attributes().time.createDate < fileB.attributes().time.createDate;
        }
    } sortByOldestAsc;

    contents.sortBy(sortByOldestAsc);

    // Keep the oldest ones.
    filesToKeep--;

    while (filesToKeep > 0) {
        contents.removeLast();

        filesToKeep--;
    }

    for (int e = 0; e < contents.size(); e++) {
        fs::File::createFromPath(contents.get(e)).erase();
    }
}

void LogFileWriter::write(cstring message) {
    if (!options.get().enabled) {
        return;
    }

    ScopeLock l(lock);

    createLogFileIfNeeded();

    if (_outputStream == nullptr) {
        return;
    }

    size_t elSize = sizeof(char);
    size_t length = strlen(message);

    _outputStream->write((byte*)message, elSize, length);
    _outputStream->flush();
}

// # Logging

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

void Logging::print(const LogOptions& options, cstring tag, cstring format, ...) {
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
        formatter.format = formatter.shortTimestampFormat();
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

void Logging::print(cstring tag, cstring format, ...) {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(getOptions(), tag, string.c_str());
}

void Logging::printInfo(const LogOptions& options, cstring format, ...) {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(options, getTagInfo().buffer(), string.c_str());
}

void Logging::printInfo(cstring format, ...) {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(getOptions(), getTagInfo().buffer(), string.c_str());
}

void Logging::printWarning(const LogOptions& options, cstring format, ...) {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(options, getTagWarning().buffer(), string.c_str());
}

void Logging::printWarning(cstring format, ...) {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(getOptions(), getTagWarning().buffer(), string.c_str());
}

void Logging::printError(const LogOptions& options, cstring format, ...) {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(options, getTagError().buffer(), string.c_str());
}

void Logging::printError(cstring format, ...) {
    std::string string;
    STDSTRING_FORMAT(string, format);
    print(getOptions(), getTagError().buffer(), string.c_str());
}

void Logging::writeToOutput(cstring string) {
    logFunc.get()(string);

    fileWriter.write(string);
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

LogFileWriteOptions Logging::getWriteToFileOptions() const {
    return fileWriter.options.get();
}

void Logging::setWriteToFileOptions(const LogFileWriteOptions& options) {
    fileWriter.options.set(options);
}

void Logging::setWriteToOutputFunc(LoggingOutput func) {
    logFunc = func;
}
