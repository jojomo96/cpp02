
#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	_value = static_cast<int>(roundf(value * (1 << _fractionalBits)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _value(src._value) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(Fixed &&src) noexcept : _value(src._value) {
	std::cout << "Move constructor called" << std::endl;
	src._value = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_value = src.getRawBits();
	return *this;
}

Fixed &Fixed::operator=(Fixed &&src) noexcept {
	std::cout << "Move assignment operator called" << std::endl;
	if (this != &src) {
		_value = src._value;
		src._value = 0;
	}
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}
