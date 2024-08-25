#pragma once

class Fixed {
public:
	Fixed(); // Default constructor
	Fixed(const Fixed &src); // Copy constructor
	~Fixed(); // Destructor

	Fixed &operator=(const Fixed &src); // Copy assignment operator
	Fixed(Fixed &&src) noexcept; // Move constructor
	Fixed &operator=(Fixed &&src) noexcept; // Move assignment operator


	[[nodiscard]] int getRawBits() const;

	void setRawBits(int const raw);

private:
	int _value;
	static const int _fractionalBits = 8;
};
