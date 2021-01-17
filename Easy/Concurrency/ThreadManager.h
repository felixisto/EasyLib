#pragma once

#include "../Foundation/Date.h"
#include "SimpleLock.h"
#include "ScopeLock.h"
#include <thread>
#include <map>

namespace easy {
	struct ThreadInfo {
		CString name;
		Date dateCreated;

		ThreadInfo() {}
		ThreadInfo(const ThreadInfo& other) : name(other.name), dateCreated(other.dateCreated) {}
		ThreadInfo(CString name) : name(name), dateCreated(Date::now()) {}
	};

	/*
	 * Keeps track of thread information.
	 *
	 * The main thread is defined by whichever thread calls standard() first.
	 */
	struct ThreadManager {
	private:
		SimpleLock lock;

		size_t _mainThreadID;

		std::map<size_t, ThreadInfo> _identifiers;

		ThreadManager() : lock() {
			_mainThreadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
			_identifiers[_mainThreadID] = CString("main-thread");
		}

		CString newName(size_t identifier) {
			size_t size = _identifiers.size();
			return CString::format("thread-%lu", size);
		}

	public:

		static ThreadManager& standard() {
			static ThreadManager c;
			return c;
		}

		size_t getMainThreadID() const {
			return _mainThreadID;
		}

		size_t currentThreadID() {
			ScopeLock l(lock);

			auto identifier = std::hash<std::thread::id>{}(std::this_thread::get_id());

			for (auto it = _identifiers.begin(); it != _identifiers.end(); ++it) {
				if (it->first == identifier) {
					return it->first;
				}
			}

			_identifiers[identifier] = ThreadInfo(newName(identifier));

			return identifier;
		}

		const ThreadInfo& currentThreadInfo() {
			auto identifier = currentThreadID();

			ScopeLock l(lock);

			return _identifiers[identifier];
		}
	};

	/*
	 * Checks if the current thread is the main thread.
	 *
	 * The main thread is defined by whichever thread calls isMain() first.
	 * Call init() or isMain() on app initialization, preferably in main().
	 */
	struct CurrentThread {
		static void init() {
			ThreadManager::standard();
		}

		static bool isMain() {
			return ThreadManager::standard().getMainThreadID() == identifier();
		}

		static size_t identifier() {
			return ThreadManager::standard().currentThreadID();
		}

		static const ThreadInfo& info() {
			return ThreadManager::standard().currentThreadInfo();
		}
	};
};
