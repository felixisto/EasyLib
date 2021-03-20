#pragma once

#include "../Collections/Array/Vector.h"
#include "../Concurrency/SimpleLock.h"
#include "../Concurrency/ScopeLock.h"

template<class T>
class Observable {
private:

	SimpleLock lock;
	Vector<T*> observers;

public:

	Vector<T*> getObservers() {
		ScopeLock l(lock);

		auto observersCopy = observers;

		return observersCopy;
	}

	virtual void subscribe(T* observer) {
		ScopeLock l(lock);

		// Skip if already subscribed
		for (int e = 0; e < observers.size(); e++) {
			if (observers.get(e) == observer) {
				return;
			}
		}

		observers.add(observer);
	}

	virtual void unsubscribe(T* observer) {
		ScopeLock l(lock);

		for (int e = 0; e < observers.size(); e++) {
			if (observers.get(e) == observer) {
				observers.removeAt(e);
				return;
			}
		}
	}
};