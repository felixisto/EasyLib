#pragma once

#include "ThreadManager.h"

namespace easy {
	/*
	 * Internal stuff used by Thread.
	 */
	template <typename T>
	struct ThreadContext {
	private:

		SimpleLock lock;

		void (*_function)(T);
		T _value;
		std::thread* _thread;

	public:

		ThreadContext(void (*function)(T), T value) : _function(function), _value(value) {
			_thread = NULL;
		}

		virtual ~ThreadContext() {
			delete _thread;
		}

		// Call this first.
		void start() {
			_function(_value);

			// Force wait, to avoid cases where the thread almost immediately returns
			system::sleep(0.1);
		}

		// Then immediately call this.
		void onStart(std::thread* thread) {
			// Call this, just so that the manager will record this thread.
			ThreadManager::standard().currentThreadID();

			ScopeLock l(lock);

			_thread = thread;
		}

		// For external threads, that want to wait for this thread to finish.
		// Can be called anytime after start() is called.
		void wait() {
			lock.lock();

			std::thread* thread = _thread;
			_thread = NULL;

			lock.unlock();

			if (thread != NULL) {
				// Do not wait for yourself
				if (std::this_thread::get_id() == thread->get_id()) {
					return;
				}

				thread->join();
			}
		}

		// Call this last.
		void finish() {
			// Finish by detaching
			lock.lock();

			std::thread* thread = _thread;
			_thread = NULL;

			lock.unlock();

			if (thread != NULL) {
				thread->detach();
			}
		}
	};

	/*
	 * Parallel code execution.
	 *
	 * Can be started only once. Can take one argument as a parameter for the execution.
	 */
	template <typename T>
	struct Thread {
	private:
		std::thread* _thread;
		std::shared_ptr<ThreadContext<T>> _context;
		bool _isStarted;

		void (*_function)(T);

		static void startThreadEntry(std::shared_ptr<ThreadContext<T>> context) {
			// Because shared_ptr is allocated here, it will keep the ThreadContext instance valid until the function returns.
			context.get()->start();
			context.get()->finish();
		}

		void startThread(T value) {
			auto newContext = new ThreadContext<T>(_function, value);

			_context = std::shared_ptr<ThreadContext<T>>(newContext);
			_thread = new std::thread(startThreadEntry, _context);
			newContext->onStart(_thread);
		}

	public:

		Thread(void (*ThreadFunction)(T)) : _function(ThreadFunction) {
			_thread = NULL;
			_isStarted = false;
		}

		virtual ~Thread() {
			// Delete nothing, context will be destroyed, which will lead to deleting the thread
		}

		void start(T value) {
			if (_isStarted) {
				return;
			}

			_isStarted = true;

			startThread(value);
		}

		void startAndWait(T value) {
			_isStarted = true;

			startThread(value);
			wait();
		}

		void wait() {
			if (!_isStarted) {
				return;
			}

			_context->wait();
		}
	};

	struct ThreadVoid: Thread<int> {
		void start() {
			Thread::start(0);
		}
	};
};
