
#include "../Path.h"
#include "../../Foundation/Date.h"
#include "../../Collections/Array/List.h"
#include "../DirectoryService.h"

using namespace easy;
using namespace fs;

Path Path::fileFromLocalPath(const CString& path) {
	CString pathStr = path;

	// Remove separator, if its at the end
	if (pathStr.endsWith(Path::fileSystemSeparator())) {
		pathStr.removeLast(Path::fileSystemSeparator());
	}

	auto basePath = appDirectory();
	return basePath.pathByAppendingComponent(pathStr);
}

Path Path::fileFromAbsolutePath(const CString& path) {
	CString pathStr = path;

	// Remove separator, if its at the end
	if (pathStr.endsWith(Path::fileSystemSeparator())) {
		pathStr.removeLast(Path::fileSystemSeparator());
	}

	return Path(pathStr);
}

Path Path::appDirectory() {
	return DirectoryService::standard().applicationDirectory();
}

Path Path::directoryFromLocalPath(const CString& path) {
	CString pathStr = path;

	// Add separator, if its missing at the end
	if (!pathStr.endsWith(Path::fileSystemSeparator())) {
		pathStr += Path::fileSystemSeparator();
	}

	auto basePath = appDirectory();
	return basePath.pathByAppendingComponent(pathStr);
}

Path Path::directoryFromAbsolutePath(const CString& path) {
	CString pathStr = path;

	// Add separator, if its missing at the end
	if (!pathStr.endsWith(Path::fileSystemSeparator())) {
		pathStr += Path::fileSystemSeparator();
	}

	return Path(pathStr);
}

Path Path::temporaryPathDirectory() {
	return DirectoryService::standard().temporaryPathDirectory();
}

Path Path::temporaryFilePath() {
	return DirectoryService::standard().temporaryPathFile("");
}

Path Path::temporaryFilePath(const CString& prefix) {
	return DirectoryService::standard().temporaryPathFile(prefix);
}

CString Path::fileSystemSeparator() {
	return DirectoryService::standard().fileSystemSeparator();
}

Path::Path() {

}

Path::Path(const Path& other) : _value(other._value) {

}

Path::Path(const CString& value) : _value(value) {

}

bool Path::operator==(const Path& other) const {
	return _value == other._value;
}

bool Path::operator<(const Path& other) const {
	return _value < other._value;
}

// # Build

Path Path::pathByAppendingComponent(const CString& component) const {
	CString newPath = _value;
	CString sep = separator();
	CString comp = component;
	
	if (newPath.endsWith(sep)) {
		newPath.removeLast(sep);
	}

	if (comp.beginsWith(sep)) {
		comp.removeFirst(sep);
	}

	newPath += sep;
	newPath += comp;

	return Path(newPath);
}

Path Path::parentPath() const {
	if (_value.length() <= 1) {
		return Path("");
	}

	CString url = _value;
	CString sep = separator();

	// The path ends with the separator. Ignore it.
	bool endsWithSeparator = url.endsWith(sep);

	if (endsWithSeparator) {
		url.removeLast(sep);
	}

	integer lastIndex = url.lastIndexOf(sep);

	if (lastIndex == kInvalidIndex) {
		return *this;
	}

	CString newStr = url.substring(0, lastIndex);

	if (endsWithSeparator) {
		newStr += sep;
	}

	return Path(newStr);
}

// # Values

CString Path::separator() const {
	return Path::fileSystemSeparator();
}

CString Path::rawValue() const {
	return _value;
}

CString Path::absolute() const {
	return _value;
}

CString Path::lastComponent() const {
	auto components = _value.split(separator());

	if (components.isEmpty()) {
		return CString();
	}

	CString last = components.last();

	// The path ends with the separator. Ignore it.
	if (last.endsWith(separator())) {
		last.removeLast(separator());
	}

	return last;
}

// # Validators

bool Path::isRoot() const {
	CString absolutePath = DirectoryService::standard().absolutePathFrom(_value);

	Path base = Path(absolutePath);
	CString baseComponent = base.parentPath().absolute();

	// The path ends with the separator. Ignore it.
	if (baseComponent.endsWith(separator())) {
		baseComponent.removeLast(separator());
	}

	CString lastPathComponent = lastComponent();

	return baseComponent == lastPathComponent;
}

bool Path::isValidFilePath() const {
	return !_value.isEmpty();
}

// # StringRepresentable

CString Path::toString() const {
	return absolute();
}

// # Hashable

ubig Path::hashValue() const {
	return _value.hashValue();
}

// # Copyable

Path Path::copy() const {
	return *this;
}
