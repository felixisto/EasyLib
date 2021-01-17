#pragma once

#include "../../Basic/Constraints.h"
#include "../Enumeration/ConstIterator.h"
#include "../../Formatters/NumberFormatter.h"

namespace easy {
    /*
     * Counts values - average, median, etc. Does not mutate the given collection.
     *
     * Relies on iterators to sort, so, if the given iterators are invalidated, this component is also invalidated.
     */
	template <typename IteratorType, typename E>
    struct CountingNumbers {
    private:
        IteratorType _iterator;
        bool _isSorted;

    public:
        static_assert(constraints::isEqualityComparable<E>::value, "<E> must support equality");
        static_assert(constraints::supportsAddition<E>::value, "<E> must support addition");
        static_assert(constraints::supportsDivision<E>::value, "<E> must support division");
        static_assert(constraints::isReadIterator<IteratorType>::value, "<IteratorType> must be a read iterator");

        CountingNumbers(IteratorType iterator, bool isSorted) : _iterator(iterator), _isSorted(isSorted) {

        }

        CountingNumbers(IteratorType iterator) : CountingNumbers(iterator, false) {

        }

        CountingNumbers(const CountingNumbers& other) : CountingNumbers(other._data, other._isSorted) {

        }

        std::vector<E> readAsSTDVector() const {
            std::vector<E> data;

            auto it = _iterator;

            while (it.hasNext()) {
                data.push_back(it.get());
                it++;
            }

            return data;
        }

        E get(integer index) const {
            auto it = _iterator;
            integer count = 0;

            while (count != index) {
                count++;
                it++;
            }

            return it.get();
        }

        E first() const {
            return get(0);
        }
        
        integer size() const {
            auto it = _iterator;
            integer count = 0;

            while (it.hasNext()) {
                count++;
                it++;
            }

            return count;
        }

        /// Returns the difference between max and min.
        real distance() const {
            return maximum() - minimum();
        }

        real minimum() const {
            E lowest = 0;
            bool isFirst = true;

            auto it = _iterator;

            while (it.hasNext()) {
                auto& current = it.get();

                if (current < lowest) {
                    lowest = current;
                } else if (isFirst) {
                    isFirst = false;
                    lowest = current;
                }

                it++;
            }

            return RealValueFormatter().parse(lowest);
        }

        real maximum() const {
            E max = 0;
            bool isFirst = true;

            auto it = _iterator;

            while (it.hasNext()) {
                auto& current = it.get();

                if (current > max) {
                    max = current;
                } else if (isFirst) {
                    isFirst = false;
                    max = current;
                }

                it++;
            }

            return RealValueFormatter().parse(max);
        }

        real sum() const {
            E sum = 0;

            auto it = _iterator;

            while (it.hasNext()) {
                sum = sum + it.get();
                it++;
            }

            return RealValueFormatter().parse(sum);
        }

        real average() const {
            return RealValueFormatter().parse(sum() / size());
        }

        /// Note: values are sorted automatically, if required.
        real median() const {
            auto data = readAsSTDVector();

            if (!_isSorted) {
                std::sort(data.begin(), data.end());
            }

            return median(data);
        }

        /// Note: values are sorted automatically, if required.
        real median() {
            auto data = readAsSTDVector();

            if (!_isSorted) {
                _isSorted = true;
                std::sort(data.begin(), data.end());
            }

            return median(data);
        }

    private:

        real median(std::vector<E>& sortedData) const {
            auto length = sortedData.size();

            if (length == 0) {
                return 0;
            }

            if (length == 1) {
                return RealValueFormatter().parse(sortedData[0]);
            }

            bool isSizeEven = math::isNumberEven(length);

            E result = 0;

            if (isSizeEven) {
                integer indexA = length / 2;
                integer indexB = indexA - 1;
                result = (sortedData[indexA] + sortedData[indexB]) / 2;
            }
            else {
                integer index = length / 2;
                result = sortedData[index];
            }

            return RealValueFormatter().parse(result);
        }
	};
};
