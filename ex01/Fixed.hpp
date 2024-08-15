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

	friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

private:
	int _value;
	static const int _fractionalBits = 8;
};
