#pragma once

#include "../Foundation/CString.h"
#include "Thread.h"
#include "SimpleLock.h"
#include "Atomic.h"

namespace easy {
	class LooperClient {
	public:

		virtual void onLoop() = 0;
	};

	/*
 * Runs code in the background in a fixed time interval.
 */
	class Looper {
	public:
		static const int MIN_WAIT_DELAY_MS = 100;

	private:

		Thread<Looper*> thread;
		LooperClient* client;
		const float secondsDelay;

		AtomicBool active = AtomicBool(false);

	public:

		const CString name;

		Looper(CString name, float secondsDelay, LooperClient* client);
		virtual ~Looper();

		bool isActive();
		float getSecondsDelay();
		LooperClient* getClient();

		void start();
		void stop();
	};
};
