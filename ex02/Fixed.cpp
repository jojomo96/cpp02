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
	return static_cast<float>(_value) / static_cast<float>(1 << _fractionalBits);
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
	return a.getRawBits() < b.getRawBits() ? a : b;
}

// Static member function max for non-const references
Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a > b ? a : b;
}

// Static member function max for const references
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return a.getRawBits() > b.getRawBits() ? a : b;
}

// Output stream
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

// Greater than
bool Fixed::operator>(const Fixed &rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

// Less than
bool Fixed::operator<(const Fixed &rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

// Greater than or equal to
bool Fixed::operator>=(const Fixed &rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}

// Less than or equal to
bool Fixed::operator<=(const Fixed &rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}

// Equality
bool Fixed::operator==(const Fixed &rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

// Inequality
bool Fixed::operator!=(const Fixed &rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}

// Addition
Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed sum(0);

	sum.setRawBits(this->getRawBits() + rhs.getRawBits());
	return sum;
}

// Subtraction
Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed difference;

	difference.setRawBits(this->getRawBits() - rhs.getRawBits());
	return difference;
}

// Multiplication
Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed product;

	product.setRawBits((this->getRawBits() * rhs.getRawBits()) >> _fractionalBits);
	return product;
}

// Division
Fixed Fixed::operator/(const Fixed &rhs) const {
	if (rhs.getRawBits() == 0) {
		throw std::runtime_error("Error: Division by zero");
	}
	Fixed quotient;
	quotient.setRawBits((this->getRawBits() << _fractionalBits) / rhs.getRawBits());
	return quotient;
}

// Prefix increment
Fixed Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

// Postfix increment
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->setRawBits(this->getRawBits() + 1);
	return tmp;
}

// Prefix decrement
Fixed Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

// Postfix decrement
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->setRawBits(this->getRawBits() - 1);
	return tmp;
}
