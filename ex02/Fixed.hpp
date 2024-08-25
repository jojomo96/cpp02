#pragma once
#include <ostream>

class Fixed {
public:
	Fixed();

	explicit Fixed(const int value);

	explicit Fixed(const float value);

	Fixed(const Fixed &src);

	Fixed(Fixed &&src) noexcept; // Move constructor

	~Fixed();

	Fixed &operator=(const Fixed &src);

	Fixed &operator=(Fixed &&src) noexcept; // Move assignment operator

	[[nodiscard]] int getRawBits() const;

	void setRawBits(int const raw);

	[[nodiscard]] float toFloat() const;

	[[nodiscard]] int toInt() const;

	static Fixed &min(Fixed &a, Fixed &b);

	static Fixed &max(Fixed &a, Fixed &b);

	static const Fixed &min(const Fixed &a, const Fixed &b);

	static const Fixed &max(const Fixed &a, const Fixed &b);

private:
	int _value;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

bool operator>(const Fixed &lhs, const Fixed &rhs);

bool operator<(const Fixed &lhs, const Fixed &rhs);

bool operator>=(const Fixed &lhs, const Fixed &rhs);

bool operator<=(const Fixed &lhs, const Fixed &rhs);

bool operator==(const Fixed &lhs, const Fixed &rhs);

bool operator!=(const Fixed &lhs, const Fixed &rhs);

Fixed operator+(const Fixed &lhs, const Fixed &rhs);

Fixed operator-(const Fixed &lhs, const Fixed &rhs);

Fixed operator*(const Fixed &lhs, const Fixed &rhs);

Fixed operator/(const Fixed &lhs, const Fixed &rhs);

Fixed &operator++(Fixed &fixed);

Fixed operator++(Fixed &fixed, int);

Fixed &operator--(Fixed &fixed);

Fixed operator--(Fixed &fixed, int);
