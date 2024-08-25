#include "Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(float const x, float const y) : x(x), y(y) {
}

Point::Point(Point const &src) = default;

Point::~Point() = default;

Point &Point::operator=(Point const &src) {
	if (this != &src) {
		const_cast<Fixed &>(x) = src.x;
		const_cast<Fixed &>(y) = src.y;
	}
	return *this;
}

Point &Point::operator=(Point &&src) noexcept {
	if (this != &src) {
		const_cast<Fixed &>(x) = src.x;
		const_cast<Fixed &>(y) = src.y;
	}
	return *this;
}

Fixed Point::getX() const {
	return x;
}

Fixed Point::getY() const {
	return y;
}
