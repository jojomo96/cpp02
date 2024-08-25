#pragma once

#include "Fixed.hpp"

class Point {
public:
	Point(); // Default constructor

	Point(float x, float y); // Constructor with parameters

	Point(Point const &src); // Copy constructor

	~Point(); // Destructor

	Point &operator=(Point const &src); // Copy assignment operator

	Point &operator=(Point &&src) noexcept; // Move assignment operator

	[[nodiscard]] Fixed getX() const;

	[[nodiscard]] Fixed getY() const;

private:
	Fixed const x;
	Fixed const y;
};
