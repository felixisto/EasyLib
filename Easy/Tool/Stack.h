#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace easy {
	class Stack {
	public:
        // Shows the stack trace and some additional info.
        static std::string stackTrace();

        // Shows the stack trace and some additional info.
        // @showModules Display list of modules/images loaded by the app.
        static std::string stackTrace(bool showBaseInfo, bool showModules, bool showCallStack);
	};

    // # Current line

    class StackSelfThrow : public std::runtime_error {
        std::string msg;
    public:
        StackSelfThrow(const std::string& arg, const char* file, int line) : std::runtime_error(arg) {
            std::ostringstream o;
           
            if (arg.length() > 0) {
                o << file << ":" << line << ": " << arg;
            } else {
                o << file << ":" << line;
            }

            msg = o.str();
        }
        ~StackSelfThrow() noexcept {}

        const char* what() const throw() {
            return msg.c_str();
        }
    };

    // Prints the file line in the source code to the given CString @_str_.
    // @_message_ is a cstring, representing the message displayed at the end of the line.
    #define stackTraceCurrentLine(_str_, _message_) \
            try { \
                throw StackSelfThrow(_message_, __FILE__, __LINE__); \
            } \
            catch (const std::runtime_error& ex) { \
                _str_ = std::string(ex.what()); \
            }
};
