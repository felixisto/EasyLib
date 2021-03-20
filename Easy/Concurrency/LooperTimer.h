#pragma once

#include "../Foundation/CString.h"
#include "../Foundation/Date.h"
#include "Atomic.h"

namespace easy {
	/*
	 * Keeps track of some time interval. Useful when trying to run code in a loop with a fixed interval.
	 *
	 * Thread safe: yes
	 */
	class LooperTimer {
	private:

		const real _interval;
		Atomic<Date> _lastUpdate;

	public:

		LooperTimer(real interval) : _interval(interval) {
			_lastUpdate.set(Date::now());
		}

		real timePassedSinceLastUpdate() const {
			Date now = Date::now();
			return now.timeSince(_lastUpdate.get());
		}

		bool hasExpired() const {
			auto timePassed = timePassedSinceLastUpdate();
			return timePassed >= _interval;
		}

		void restart() {
			_lastUpdate.set(Date::now());
		}

		// Returns true, when the time interval has passed; retruns false otherwise.
		// When the time interval passes, the last update date is refreshed.
		bool update() {
			if (!hasExpired()) {
				return false;
			}

			restart();

			return true;
		}
	};
};
