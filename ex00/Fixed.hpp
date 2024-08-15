
#pragma once

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &src);
	~Fixed();

	Fixed &operator=(const Fixed &src);

	[[nodiscard]] int getRawBits() const;
	void setRawBits(int const raw);
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;
};
