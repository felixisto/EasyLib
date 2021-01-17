
#include "Stack.h"
#include "../Basic/Utilities.h"

using namespace easy;

// # Full stack trace

#ifdef __unix__
#define STACK_PLATFORM_AVAILABLE

#include "TeuchosStackTrace/TeuchosStackTrace.hpp"

CString Stack::stackTrace() {
    auto string = Teuchos::get_stacktrace(10);
    return string;
}

#endif

#ifdef _WIN32
#define STACK_PLATFORM_AVAILABLE

#include "StackWalker/StackWalker.h"

struct EasyStackWalker: StackWalker {
    bool showBaseInfo = false;
    bool showModules = false;
    bool showCallStack = true;

    std::string result;
    
    int callStackSize = 0;

    EasyStackWalker() : StackWalker() {
        
    }

    void reset() {
        result.clear();
        callStackSize = 0;
    }

    virtual void OnOutput(LPCSTR szText) {
        result += stringFromFormat("%s", std::string(szText).c_str());
    }

    virtual void OnSymInit(LPCSTR szSearchPath, DWORD symOptions, LPCSTR szUserName) {
        if (showBaseInfo) {
            StackWalker::OnSymInit(szSearchPath, symOptions, szUserName);
        }
    }

    virtual void OnLoadModule(LPCSTR    img,
        LPCSTR    mod,
        DWORD64   baseAddr,
        DWORD     size,
        DWORD     result,
        LPCSTR    symType,
        LPCSTR    pdbName,
        ULONGLONG fileVersion) {
        if (showModules) {
            StackWalker::OnLoadModule(img, mod, baseAddr, size, result, symType, pdbName, fileVersion);
        }
    }

    virtual void OnCallstackEntry(CallstackEntryType eType, CallstackEntry& entry) {
        // To make things look nicer
        if (callStackSize == 0) {
            if (result.length() > 0) {
                result += "\n";
            }

            result += "Call stack:\n";
        }

        callStackSize += 1;

        if (showCallStack) {
            StackWalker::OnCallstackEntry(eType, entry);
        }
    }

    // Call this, and then retrieve the result from the field.
    // ShowCallstack();
};

std::string Stack::stackTrace(bool showBaseInfo, bool showModules, bool showCallStack) {
    EasyStackWalker sw;
    sw.showBaseInfo = showBaseInfo;
    sw.showModules = showModules;
    sw.showCallStack = showCallStack;
    sw.ShowCallstack();
    return sw.result;
}

std::string Stack::stackTrace() {
    EasyStackWalker sw;
    sw.ShowCallstack();
    return sw.result;
}

#endif

#ifndef STACK_PLATFORM_AVAILABLE

CString Stack::stackTrace() {
    return CString("<stack trace unavailable>");
}

#endif
