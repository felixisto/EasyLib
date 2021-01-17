#pragma once

#include "SimpleLock.h"

namespace easy {
	/*
	 * Same as SimpleLock, except that lock() is performed on init AND unlock() is performed on destruction.
	 *
	 * Useful when trying to lock on when entering a function, and unlock as soon as we leave the scope of the ScopeLock.
	 */
	struct ScopeLock {
	private:

		const SimpleLock* lock;

		ScopeLock();

		// Private, to prevent usage (bad idea).
		ScopeLock(const ScopeLock& other);
		ScopeLock& operator=(const ScopeLock& other);

	public:

		ScopeLock(const SimpleLock& lock);
		~ScopeLock();
	};
};
