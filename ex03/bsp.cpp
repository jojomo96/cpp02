#include "Point.hpp"
#include "Fixed.hpp"

Fixed crossProduct(Fixed const &x1, Fixed const &y1, Fixed const &x2, Fixed const &y2) {
	return x1 * y2 - x2 * y1;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed const x = point.getX();
	Fixed const y = point.getY();
	Fixed const x1 = a.getX();
	Fixed const y1 = a.getY();
	Fixed const x2 = b.getX();
	Fixed const y2 = b.getY();
	Fixed const x3 = c.getX();
	Fixed const y3 = c.getY();

	Fixed const cp1 = crossProduct(x - x1, y - y1, x2 - x1, y2 - y1);
	Fixed const cp2 = crossProduct(x - x2, y - y2, x3 - x2, y3 - y2);
	Fixed const cp3 = crossProduct(x - x3, y - y3, x1 - x3, y1 - y3);

	return (cp1 >= Fixed(0) && cp2 >= Fixed(0) && cp3 >= Fixed(0))
		|| (cp1 <= Fixed(0) && cp2 <= Fixed(0) && cp3 <= Fixed(0));
}
