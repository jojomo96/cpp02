
#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _value(src._value) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed::Fixed(Fixed &&src) noexcept : _value(src._value) {
	std::cout << "Move constructor called" << std::endl;
	src._value = 0;
}

Fixed &Fixed::operator=(Fixed &&src) noexcept {
	if (this != &src) {
		_value = src._value;
		src._value = 0;
	}
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}
