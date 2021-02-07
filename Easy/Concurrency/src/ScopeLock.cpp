
#include "../ScopeLock.h"

using namespace easy;

ScopeLock::ScopeLock() {
	lock = new SimpleLock();
	lock->lock();
}

ScopeLock::ScopeLock(const SimpleLock& lock) {
	this->lock = &lock;
	lock.lock();
}

ScopeLock::ScopeLock(const ScopeLock& other) {
	this->lock = other.lock;
}

ScopeLock& ScopeLock::operator=(const ScopeLock& other) {
	return *this;
}

ScopeLock::~ScopeLock() {
	lock->unlock();
}