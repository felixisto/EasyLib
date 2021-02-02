#pragma once

#include "Transformer.h"
#include "../../Basic/Math.h"

namespace easy {
	template <typename T>
	struct TransformerAssign : Transformer<T> {
		static_assert(constraints::isEqualityComparable<T>::value, "<T> must support equality");

		T v;

		TransformerAssign(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value = v;
		}
	};

	template <typename T>
	struct TransformerAssignRef : Transformer<T> {
		const T* v;

		TransformerAssignRef(const T* value) : v(value) {

		}

		virtual void transform(T& value) const {
			value = *v;
		}
	};

	template <typename T>
	struct TransformerAddition: Transformer<T> {
		T v;

		TransformerAddition(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value += v;
		}
	};

	template <typename T>
	struct TransformerAdditionRef: Transformer<T> {
		const T* v;

		TransformerAdditionRef(const T* value) : v(value) {

		}

		virtual void transform(T& value) const {
			value += *v;
		}
	};

	template <typename T>
	struct TransformerSubtraction: Transformer<T> {
		T v;

		TransformerSubtraction(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value -= v;
		}
	};

	template <typename T>
	struct TransformerSubtractionRef: Transformer<T> {
		const T* v;

		TransformerSubtractionRef(const T* value) : v(value) {

		}

		virtual void transform(T& value) const {
			value -= *v;
		}
	};

	template <typename T>
	struct TransformerMultiplication: Transformer<T> {
		T v;

		TransformerMultiplication(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value *= v;
		}
	};

	template <typename T>
	struct TransformerDivision: Transformer<T> {
		T v;

		TransformerDivision(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value /= v;
		}
	};

	template <typename T>
	struct TransformerSqrt: Transformer<T> {
		T v;

		TransformerSqrt(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value = math::sqrtOf(v);
		}
	};

	template <typename T>
	struct TransformerLog : Transformer<T> {
		T v;

		TransformerLog(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value = math::logarithm(v);
		}
	};
};
