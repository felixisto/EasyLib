#pragma once

#include "../../Foundation/CString.h"
#include "../../Concurrency/Atomic.h"
#include "../../FileSystem/File.h"

namespace easy {
	struct FileOutputStream;

	typedef void (*LoggingOutput)(cstring);

	struct LogOptions {
		static LogOptions standard();
		static LogOptions minimal();
		static LogOptions rawString();
		static LogOptions rawStringNoNewLine();

		bool newLine = true;
		bool printTag = false;
		bool printTimestamp = true;
		bool printAppName = true;
		bool printThread = false;
	};

	struct LogFileWriteOptions {
		bool enabled = false;

		// Base path for the files and folder.
		fs::Path basePath;

		// The folder in which the logs will be created and kept.
		CString logsFolderName;

		CString logFileNamePrefix;
		bool insertDateInLogFileName = true;
		CString logFileFormat;

		// Max number of files that will be kept in the logs folder.
		// If logsFolderName is empty, this does nothing.
		int maxLogFiles = 0;

		// @basePath = application directory
		// @logsFolderName = "logs"
		// @insertDateInLogFileName = true
		// @maxLogFiles = 10
		// @logFileFormat = "log"
		static LogFileWriteOptions standard();
	};

	// Helper, for creating and maintaining the log files.
	struct LogFileWriter {
		Atomic<LogFileWriteOptions> options = Atomic<LogFileWriteOptions>();

	private:
		SimpleLock lock;

		fs::File* _file;
		FileOutputStream* _outputStream;

	public:

		LogFileWriter();
		~LogFileWriter();

		CString getCurrentLogName() const;
		fs::Path getCurrentLogPath() const;
		fs::Path getCurrentLogDirectory() const;

		void createLogFileIfNeeded();
		void eraseLogFilesOverCapacity();

		void write(cstring message);
	};

	/*
	 * Writes string messages to the specified logging function (by default, the function is just a printf command).
	 * 
	 * Write to file is disabled by default.
	 *
	 * Thread safe: yes
	 */
	struct Logging {
	private:
		Atomic<LogOptions> options;

		Atomic<CString> separator = Atomic<CString>("|");
		Atomic<CString> appName = Atomic<CString>("");

		Atomic<CString> TAG_INFO = Atomic<CString>("INFO");
		Atomic<CString> TAG_WARNING = Atomic<CString>("WARNING");
		Atomic<CString> TAG_ERROR = Atomic<CString>("ERROR");
		
		LogFileWriter fileWriter;

		Atomic<LoggingOutput> logFunc;

		void writeToOutput(cstring string);
	public:
		static Logging& standard();

		Logging();

		// # Print

		void print(const LogOptions& options, cstring tag, cstring format, ...);
		void print(cstring tag, cstring format, ...);
		void printInfo(const LogOptions& options, cstring format, ...);
		void printInfo(cstring format, ...);
		void printWarning(const LogOptions& options, cstring format, ...);
		void printWarning(cstring format, ...);
		void printError(const LogOptions& options, cstring format, ...);
		void printError(cstring format, ...);

		// # Modify functionality

		LogOptions getOptions() const;
		void setOptions(const LogOptions& options);

		CString getSeparator() const;
		void setSeparator(const CString& value);
		CString getAppName() const;
		void setAppName(const CString& value);
		CString getTagInfo() const;
		void setTagInfo(const CString& value);
		CString getTagWarning() const;
		void setTagWarning(const CString& value);
		CString getTagError() const;
		void setTagError(const CString& value);

		LogFileWriteOptions getWriteToFileOptions() const;
		void setWriteToFileOptions(const LogFileWriteOptions& options);

		void setWriteToOutputFunc(LoggingOutput func);
	};
}
