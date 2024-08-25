#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : _value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	int maxValue = std::numeric_limits<int>::max() >> _fractionalBits;
	int minValue = std::numeric_limits<int>::min() >> _fractionalBits;
	if (value > maxValue || value < minValue) {
		std::cerr << "Error: Value out of range for fixed-point representation. "
				<< "Valid range is [" << minValue << ", " << maxValue << "]." << std::endl;
		_value = 0; // Set to a default value or handle the error as needed
	} else {
		_value = static_cast<int>(roundf(value * (1 << _fractionalBits)));
	}
}

Fixed::Fixed(const Fixed &src) : _value(src._value) {
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(Fixed &&src) noexcept : _value(src._value) {
	// std::cout << "Move constructor called" << std::endl;
	src._value = 0;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_value = src.getRawBits();
	return *this;
}

Fixed &Fixed::operator=(Fixed &&src) noexcept {
	// std::cout << "Move assignment operator called" << std::endl;
	if (this != &src) {
		_value = src._value;
		src._value = 0;
	}
	return *this;
}

int Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;
}

// Static member function min for non-const references
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return a < b ? a : b;
}

// Static member function min for const references
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return a < b ? a : b;
}

// Static member function max for non-const references
Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a > b ? a : b;
}

// Static member function max for const references
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return a > b ? a : b;
}

// Output stream
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

// Greater than
bool operator>(const Fixed &lhs, const Fixed &rhs) {
	return lhs.toFloat() > rhs.toFloat();
}

// Less than
bool operator<(const Fixed &lhs, const Fixed &rhs) {
	return lhs.toFloat() < rhs.toFloat();
}

// Greater than or equal to
bool operator>=(const Fixed &lhs, const Fixed &rhs) {
	return lhs.toFloat() >= rhs.toFloat();
}

// Less than or equal to
bool operator<=(const Fixed &lhs, const Fixed &rhs) {
	return lhs.toFloat() <= rhs.toFloat();
}

// Equality
bool operator==(const Fixed &lhs, const Fixed &rhs) {
	return lhs.getRawBits() == rhs.getRawBits();
}

// Inequality
bool operator!=(const Fixed &lhs, const Fixed &rhs) {
	return lhs.getRawBits() != rhs.getRawBits();
}

// Addition
Fixed operator+(const Fixed &lhs, const Fixed &rhs) {
	return Fixed(lhs.toFloat() + rhs.toFloat());
}

// Subtraction
Fixed operator-(const Fixed &lhs, const Fixed &rhs) {
	return Fixed(lhs.toFloat() - rhs.toFloat());
}

// Multiplication
Fixed operator*(const Fixed &lhs, const Fixed &rhs) {
	return Fixed(lhs.toFloat() * rhs.toFloat());
}

// Division
Fixed operator/(const Fixed &lhs, const Fixed &rhs) {
	if (rhs.toFloat() == 0) {
		throw std::runtime_error("Error: Division by zero");
	}
	return Fixed(lhs.toFloat() / rhs.toFloat());
}

// Prefix increment
Fixed &operator++(Fixed &fixed) {
	fixed.setRawBits(fixed.getRawBits() + 1);
	return fixed;
}

// Postfix increment
Fixed operator++(Fixed &fixed, int) {
	Fixed tmp(fixed);
	fixed.setRawBits(fixed.getRawBits() + 1);
	return tmp;
}

// Prefix decrement
Fixed &operator--(Fixed &fixed) {
	fixed.setRawBits(fixed.getRawBits() - 1);

	return fixed;
}

// Postfix decrement
Fixed operator--(Fixed &fixed, int) {
	Fixed tmp(fixed);
	fixed.setRawBits(fixed.getRawBits() - 1);
	return tmp;
}

