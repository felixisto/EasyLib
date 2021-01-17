#pragma once

#include "../Foundation/CString.h"
#include "../Concurrency/Atomic.h"

namespace easy {
	typedef void (*LoggingOutput)(cstring);

	class LogOptions {
	public:
		static LogOptions standard() {
			return LogOptions();
		}

		static LogOptions minimal() {
			auto options = LogOptions();
			options.printTag = false;
			options.printTimestamp = false;
			return options;
		}

		static LogOptions rawString() {
			auto options = LogOptions();
			options.printTag = false;
			options.printTimestamp = false;
			options.printAppName = false;
			options.printThread = false;
			return options;
		}

		static LogOptions rawStringNoNewLine() {
			auto options = rawString();
			options.newLine = false;
			return options;
		}

		bool newLine = true;
		bool printTag = false;
		bool printTimestamp = true;
		bool printAppName = true;
		bool printThread = false;
	};

	/*
	 * Writes string messages to the specified logging function (by default, the function is just a printf command).
	 *
	 * Thread safe: yes
	 */
	class Logging {
	private:
		Atomic<LogOptions> options;

		Atomic<CString> separator = Atomic<CString>("|");
		Atomic<CString> appName = Atomic<CString>("");

		Atomic<CString> TAG_INFO = Atomic<CString>("INFO");
		Atomic<CString> TAG_WARNING = Atomic<CString>("WARNING");
		Atomic<CString> TAG_ERROR = Atomic<CString>("ERROR");

		Atomic<LoggingOutput> logFunc;

		void writeToOutput(cstring string) const;
	public:
		static Logging& standard();

		Logging();

		// # Print

		void print(const LogOptions& options, cstring tag, cstring format, ...) const;
		void print(cstring tag, cstring format, ...) const;
		void printInfo(const LogOptions& options, cstring format, ...) const;
		void printInfo(cstring format, ...) const;
		void printWarning(const LogOptions& options, cstring format, ...) const;
		void printWarning(cstring format, ...) const;
		void printError(const LogOptions& options, cstring format, ...) const;
		void printError(cstring format, ...) const;

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

		void setWriteToOutputFunc(LoggingOutput func);
	};
}
