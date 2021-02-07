
#include "../SimpleLock.h"

using namespace easy;

SimpleLock::SimpleLock() {
	_mutex = new std::mutex();
}

SimpleLock::SimpleLock(const SimpleLock& other) {
	_mutex = new std::mutex();
}

SimpleLock::~SimpleLock() {
	delete _mutex;
}

void SimpleLock::lock() const {
	_mutex->lock();
}

void SimpleLock::unlock() const {
	_mutex->unlock();
}
