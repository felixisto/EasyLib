#pragma once

#include "Transformer.h"
#include "../../Basic/Math.h"

namespace easy {
	template <typename T>
	struct TransformerAssign : Transformer<T> {
		static_assert(constraints::isCopyAssignable<T>::value, "<T> must support assignment");

		const T& v;

		TransformerAssign(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value = v;
		}
	};

	template <typename T>
	struct TransformerAddition: Transformer<T> {
		static_assert(constraints::isCopyAssignable<T>::value, "<T> must support assignment");

		const T& v;

		TransformerAddition(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value += v;
		}
	};

	template <typename T>
	struct TransformerSubtraction: Transformer<T> {
		static_assert(constraints::isCopyAssignable<T>::value, "<T> must support assignment");

		const T& v;

		TransformerSubtraction(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value -= v;
		}
	};

	template <typename T>
	struct TransformerMultiplication: Transformer<T> {
		static_assert(constraints::isCopyAssignable<T>::value, "<T> must support assignment");

		const T& v;

		TransformerMultiplication(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value *= v;
		}
	};

	template <typename T>
	struct TransformerDivision: Transformer<T> {
		static_assert(constraints::isCopyAssignable<T>::value, "<T> must support assignment");

		const T& v;

		TransformerDivision(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value /= v;
		}
	};

	template <typename T>
	struct TransformerSqrt: Transformer<T> {
		static_assert(constraints::isCopyAssignable<T>::value, "<T> must support assignment");

		const T& v;

		TransformerSqrt(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value = math::sqrtOf(v);
		}
	};

	template <typename T>
	struct TransformerLog : Transformer<T> {
		static_assert(constraints::isCopyAssignable<T>::value, "<T> must support assignment");

		const T& v;

		TransformerLog(const T& value) : v(value) {

		}

		virtual void transform(T& value) const {
			value = math::logarithm(v);
		}
	};
};
