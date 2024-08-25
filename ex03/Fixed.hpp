#pragma once
#include <ostream>

class Fixed {
public:
	Fixed(); // Default constructor

	explicit Fixed(int value); // Constructor with parameters

	explicit Fixed(float value); // Constructor with parameters

	Fixed(const Fixed &src); // Copy constructor

	Fixed(Fixed &&src) noexcept; // Move constructor

	~Fixed(); // Destructor

	Fixed &operator=(const Fixed &src); // Copy assignment operator

	Fixed &operator=(Fixed &&src) noexcept; // Move assignment operator

	[[nodiscard]] int getRawBits() const;

	void setRawBits(int raw);

	[[nodiscard]] float toFloat() const;

	[[nodiscard]] int toInt() const;

	static Fixed &min(Fixed &a, Fixed &b);

	static Fixed &max(Fixed &a, Fixed &b);

	static const Fixed &min(const Fixed &a, const Fixed &b);

	static const Fixed &max(const Fixed &a, const Fixed &b);

	friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

	friend bool operator>(const Fixed &lhs, const Fixed &rhs);

	friend bool operator<(const Fixed &lhs, const Fixed &rhs);

	friend bool operator>=(const Fixed &lhs, const Fixed &rhs);

	friend bool operator<=(const Fixed &lhs, const Fixed &rhs);

	friend bool operator==(const Fixed &lhs, const Fixed &rhs);

	friend bool operator!=(const Fixed &lhs, const Fixed &rhs);

	friend Fixed operator+(const Fixed &lhs, const Fixed &rhs);

	friend Fixed operator-(const Fixed &lhs, const Fixed &rhs);

	friend Fixed operator*(const Fixed &lhs, const Fixed &rhs);

	friend Fixed operator/(const Fixed &lhs, const Fixed &rhs);

	friend Fixed &operator++(Fixed &fixed);

	friend Fixed operator++(Fixed &fixed, int);

	friend Fixed &operator--(Fixed &fixed);

	friend Fixed operator--(Fixed &fixed, int);

private:
	int _value;
	static const int _fractionalBits = 8;
};
