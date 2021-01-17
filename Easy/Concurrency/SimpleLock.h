#pragma once

#include <mutex>

namespace easy {
	struct SimpleLock {
	private:

		std::mutex* _mutex;

		// Private, to prevent usage (bad idea).
		SimpleLock(const SimpleLock& other);

	public:

		SimpleLock();
		~SimpleLock();

		void lock() const;
		void unlock() const;
	};
};
