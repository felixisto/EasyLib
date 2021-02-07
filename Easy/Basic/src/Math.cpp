
#include "../Math.h"
#include "../Utilities.h"
#include <chrono>
#include <sstream>
#include <iomanip>

real PI = MATH_PI;
real E = MATH_E;

namespace easy {
    // # Point

    Point::Point() {
        x = 0;
        y = 0;
    }

    Point::Point(const Point& other) {
        x = other.x;
        y = other.y;
    }

    Point::Point(real x, real y) {
        this->x = x;
        this->y = y;
    }

    real Point::distanceBetween(const Point& other) const {
        return math::sqrtOf(math::powerOf2(x - other.x) + math::powerOf2(y - other.y));
    }

    // # Size

    Size::Size() {
        width = 0;
        height = 0;
    }

    Size::Size(const Size& other) {
        width = other.width;
        height = other.height;
    }

    Size::Size(real width, real height) {
        this->width = width;
        this->height = height;
    }

    real Size::areaSize() const {
        return width * height;
    }

    // # Rectangle

    Rectangle::Rectangle() {
    }

    Rectangle::Rectangle(const Rectangle& other) {
        origin = other.origin;
        size = other.size;
    }

    Rectangle::Rectangle(const Point& origin, const Size& size) {
        this->origin = origin;
        this->size = size;
    }

    // # Range

    Range Range::CreateStart(uinteger start) {
        return Range(start, start);
    }

    Range Range::CreateStartEnd(uinteger start, uinteger end) {
        return Range(start, end);
    }

    Range Range::CreateStartLength(uinteger start, uinteger length) {
        return Range(start, start + length);
    }

    Range::Range() {
        start = 0;
        end = 0;
    }

    Range::Range(const Range& other) {
        start = other.start;
        end = other.end;
    }

    Range::Range(uinteger start, uinteger end) {
        this->start = start;
        this->end = end;
    }

    integer Range::length() const {
        return end - start;
    }

    bool Range::overlaps(const Range& other) const {
        return math::maximum(start, other.start) <= math::minimum(end, other.end);
    }

    void Range::moveForwardsBy(integer value) {
        start += value;
        end += value;
    }
};