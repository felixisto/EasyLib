#pragma once

#include "../Basic/Defines.h"
#include "../Basic/Constraints.h"
#include "SimpleLock.h"

namespace easy {
	template <typename T>
	struct Atomic {
	protected:
		SimpleLock lock;

		T value;

	public:
		static_assert(constraints::hasDefaultConstructor<T>::value, "<T> must have a default constructor");

		Atomic() : value(T()) {

		}

		Atomic(T value) : value(value) {

		}

		Atomic(const Atomic& value) : value(value.value) {

		}

		T get() const {
			lock.lock();
			T copy = value;
			lock.unlock();

			return copy;
		}

		void set(T value) {
			lock.lock();
			this->value = value;
			lock.unlock();
		}

		T getAndSet(T value) {
			lock.lock();
			T copy = this->value;
			this->value = value;
			lock.unlock();
			return copy;
		}

		void setAndGet(T value) {
			lock.lock();
			this->value = value;
			lock.unlock();
			return value;
		}
	};

	using AtomicBool = Atomic<bool>;
	using AtomicByte = Atomic<byte>;

	struct AtomicInt: Atomic<integer> {
		AtomicInt() {

		}

		AtomicInt(integer value) : Atomic(value) {

		}

		void increment() {
			set(get() + 1);
		}

		integer getAndIncrement() {
			lock.lock();
			auto oldValue = this->value;
			this->value = value + 1;
			lock.unlock();
			return oldValue;
		}

		integer incrementAndGet() {
			lock.lock();
			this->value = value + 1;
			lock.unlock();
			return value;
		}

		void decrement() {
			set(get() - 1);
		}

		integer getAndDecrement() {
			lock.lock();
			auto oldValue = this->value;
			this->value = value - 1;
			lock.unlock();
			return oldValue;
		}

		integer decrementAndGet() {
			lock.lock();
			this->value = value - 1;
			lock.unlock();
			return value;
		}
	};
};
