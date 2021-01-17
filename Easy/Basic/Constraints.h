#pragma once

#include <type_traits>
#include "Defines.h"

namespace easy {
	namespace constraints {
		// # Type check

		template <typename T>
		struct isPrimitiveType : std::is_fundamental<T> {
		};

		template <typename Base, typename Der>
		struct isTypeOf : std::is_base_of<Base, Der> {
		};

		template <typename A, typename B>
		struct isTypeEqual : std::is_same<A, B> {
		};

		template <typename T>
		struct isNumber : std::is_arithmetic<T> {
		};

		template <typename T>
		struct isInteger : std::is_integral<T> {
		};

		template <typename T>
		struct isReal : std::is_floating_point<T> {
		};

		// # Equality

		template<typename T, typename = void>
		struct isEqualityComparable : std::false_type
		{ };

		template<typename T>
		struct isEqualityComparable<T, typename std::enable_if<true, decltype(std::declval<T&>() == std::declval<T&>(), (void)0)>::type> : std::true_type
		{ };

		template<typename T, typename = void>
		struct isGreaterComparable : std::false_type
		{ };

		template<typename T>
		struct isGreaterComparable<T, typename std::enable_if<true, decltype(std::declval<T&>() > std::declval<T&>(), (void)0)>::type> : std::true_type
		{ };

		template<typename T, typename = void>
		struct isLesserComparable : std::false_type
		{ };

		template<typename T>
		struct isLesserComparable<T, typename std::enable_if<true, decltype(std::declval<T&>() < std::declval<T&>(), (void)0)>::type> : std::true_type
		{ };

		// # Arithmetic

		template<typename T, typename = void>
		struct supportsAddition : std::false_type
		{ };

		template<typename T>
		struct supportsAddition<T, typename std::enable_if<true, decltype(std::declval<T&>() + std::declval<T&>(), (void)0)>::type> : std::true_type
		{ };

		template<typename T, typename = void>
		struct supportsSubtraction : std::false_type
		{ };

		template<typename T>
		struct supportsSubtraction<T, typename std::enable_if<true, decltype(std::declval<T&>() - std::declval<T&>(), (void)0)>::type> : std::true_type
		{ };

		template<typename T, typename = void>
		struct supportsMultiplication : std::false_type
		{ };

		template<typename T>
		struct supportsMultiplication<T, typename std::enable_if<true, decltype(std::declval<T&>() * std::declval<T&>(), (void)0)>::type> : std::true_type
		{ };

		template<typename T, typename = void>
		struct supportsDivision : std::false_type
		{ };

		template<typename T>
		struct supportsDivision<T, typename std::enable_if<true, decltype(std::declval<T&>() / std::declval<T&>(), (void)0)>::type> : std::true_type
		{ };

		// # Constructor

		template <typename T>
		struct hasDefaultConstructor : std::is_default_constructible<T> {
		};

		// # Iterator

		template <typename Der>
		struct isReadIterator : std::is_base_of<ReadIterator, Der> {
		};

		template <typename Der>
		struct isReadWriteIterator : std::is_base_of<ReadWriteIterator, Der> {
		};
	};
};
