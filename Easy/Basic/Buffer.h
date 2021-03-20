#pragma once

#include "Defines.h"
#include "Math.h"

namespace easy {
	template <typename T>
	struct Buffer {
	private:

		T* _value;
		int _length;

	public:
		static int lengthToSizeInBytes(integer length) {
			return (int)(sizeof(T) * length);
		}

		int elementSize() const {
			return (int)sizeof(T);
		}

		int length() const {
			return _length;
		}

		int sizeInBytes() const {
			return lengthToSizeInBytes(_length);
		}

		Buffer() {
			_value = (T*)malloc(lengthToSizeInBytes(1));
			_length = 1;
			zeroOut();
		}

		Buffer(const Buffer<T>& other) {
			_value = (T*)malloc(other.sizeInBytes());
			_length = other._length;
			memcpy(_value, other._value, other.sizeInBytes());
		}

		Buffer(int length) {
			_value = (T*)malloc(lengthToSizeInBytes(length));
			_length = length;

			zeroOut();
		}

		Buffer(const T* buffer, int length) : Buffer(buffer, length, false) {
		}

		Buffer(const T* buffer, int length, bool addZeroAtEnd) {
			if (addZeroAtEnd) {
				length += 1;
			}

			_value = (T*)malloc(lengthToSizeInBytes(length));
			_length = length;

			if (addZeroAtEnd) {
				zeroOut();
			}

			copyBytes(0, buffer, Range::CreateStartLength(0, length));
		}

		virtual ~Buffer() {
			free(_value);
		}

		const T* buffer() const {
			return _value;
		}

		T* buffer() {
			return _value;
		}

		bool operator==(const Buffer<T>& other) const {
			if (_length != other._length) {
				return false;
			}

			return memcmp(_value, other._value, sizeInBytes()) == 0;
		}

		Buffer<T>& operator=(const Buffer<T>& other) {
			copy(other);

			return *this;
		}

		Buffer<T>& operator+=(const Buffer<T>& other) {
			append(other);
			return *this;
		}

		Buffer<T> operator+(const Buffer<T>& other) const {
			Buffer<T> currentCopy = *this;
			currentCopy.append(other);
			return currentCopy;
		}

		T& operator[](integer index) const {
			return _value[index];
		}

		T& get(integer index) const {
			return _value[index];
		}

		T* getBuffer() const {
			return _value;
		}

		bool contains(const T& value) const {
			return countValue(value) > 0;
		}

		bool contains(T& value) {
			return countValue(value) > 0;
		}

		integer countValue(const T& value) const {
			const T* start = _value;

			integer count = 0;

			for (int e = 0; e < length(); e++) {
				if (*start == value) {
					count++;
				}

				start++;
			}

			return count;
		}

		integer countValue(T& value) {
			const T* start = _value;

			integer count = 0;

			for (int e = 0; e < length(); e++) {
				if (*start == value) {
					count++;
				}

				start++;
			}

			return count;
		}

		Buffer<T> subbuffer(const Range& range) {
			T* start = _value + range.start;
			T* end = _value + range.end;

			Buffer<T> result = Buffer<T>(range.length());
			result.copyBytes(0, _value, range);
			return result;
		}

		void setValues(T value) {
			memset(_value, value, sizeInBytes());
		}

		void zeroOut() {
			setValues(0);
		}

		void insertBytes(integer startIndex, const T* other, integer otherLength) {
			integer oldLength = length();

			setLength(oldLength + otherLength);

			T* moveStart = buffer() + startIndex;
			T* moveEnd = moveStart + startIndex;
			int moveSizeInBytes = lengthToSizeInBytes(oldLength - startIndex);
			memcpy(moveEnd, moveStart, moveSizeInBytes);

			T* insertStart = moveStart;
			int insertSizeInBytes = lengthToSizeInBytes(otherLength);
			memcpy(insertStart, other, insertSizeInBytes);
		}

		void insertBytes(integer startIndex, const Buffer<T>& other) {
			insertBytes(startIndex, other.buffer(), other.length());
		}

		void copyBytes(integer selfStartIndex, const T* other, const Range& otherRange) {
			integer newSizeInBytes = lengthToSizeInBytes(otherRange.length());
			T* thisStart = buffer() + selfStartIndex;
			const T* otherStart = other + otherRange.start;

			memcpy(thisStart, otherStart, newSizeInBytes);
		}

		void copyBytes(integer startIndex, const Buffer<T>& other, const Range& otherRange) {
			copyBytes(startIndex, other.buffer(), otherRange);
		}

		void copy(const Buffer<T>& other, const Range& range) {
			integer newLength = range.length();
			integer newSizeInBytes = lengthToSizeInBytes(newLength);

			if (_length != newLength) {
				_value = (T*)realloc(_value, newSizeInBytes);
			}

			const T* otherStart = other.buffer() + range.start;

			memcpy(_value, otherStart, newSizeInBytes);
			_length = newLength;
		}

		void copy(const Buffer<T>& other) {
			copy(other, Range(0, other.length()));
		}

		void setSizeInBytes(int size) {
			int oldSize = _length;

			_length = size / sizeof(T);
			_value = (T*)realloc(_value, sizeInBytes());

			if (oldSize < _length) {
				T* end = _value + oldSize;

				memset(end, 0, _length - oldSize);
			}
		}

		void setLength(int length) {
			setSizeInBytes(lengthToSizeInBytes(length));
		}

		void append(const Buffer<T>& other) {
			integer oldLength = length();

			setLength(oldLength + other.length());

			T* end = _value + oldLength;

			memcpy(end, other.buffer(), other.sizeInBytes());
		}
	};

	using BoolsBuffer = Buffer<bool>;
	using CharsBuffer = Buffer<char>;
	using BytesBuffer = Buffer<byte>;
	using IntsBuffer = Buffer<integer>;
	using RealsBuffer = Buffer<real>;
};
