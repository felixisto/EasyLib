#pragma once

#include "../Basic/Defines.h"
#include "../Basic/Basic.h"
#include "../Foundation/CString.h"

namespace easy {
	struct Character: StringRepresentable, Hashable {
		character value;

		Character() : value(0) {

		}

		Character(const Character& other) : value(other.value) {

		}

		Character(character value) : value(value) {

		}

		Character(char16_t value) {
			this->value = reinterpret_cast<char&>(value);
		}

		bool operator==(const Character& other) const {
			return value == other.value;
		}

		bool operator<(const Character& other) const {
			return value < other.value;
		}

		bool operator>(const Character& other) const {
			return value > other.value;
		}

		Character& operator=(const Character& other) {
			value = other.value;
			return *this;
		}

		bool isDigit() const {
			return IsCharDigit(value);
		}

		// # StringRepresentable

		virtual CString toString() const {
			return CString::format("%c", value);
		}

		// # Hashable

		virtual ubig hashValue() const {
			return (ubig)value;
		}
	};

};
