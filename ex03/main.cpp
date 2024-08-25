#include <iostream>
#include "Point.hpp"
#include "bsp.hpp"


void printPointStatus(const Point &pointOnEdge, const bool resultOnEdge) {
	std::cout << "Point (" << pointOnEdge.getX() << ", " << pointOnEdge.getY() << ") is "
			<< (resultOnEdge ? "inside" : "outside") << " the triangle." << std::endl;
}

int main() {
	// Define the vertices of the triangle
	const Point a(0.0f, 0.0f);
	const Point b(10.0f, 0.0f);
	const Point c(5.0f, 10.0f);

	// Define a point to test
	const Point point1(5.0f, 5.0f);
	const Point point2(15.0f, 5.0f);

	// Test if the points are inside the triangle
	bool result1 = bsp(a, b, c, point1);
	bool result2 = bsp(a, b, c, point2);

	printPointStatus(point1, result1);
	printPointStatus(point2, result2);

	// Define a point that lies on the edge of the triangle
	const Point pointOnEdge(5.0f, 0.0f);

	// Test if the point is inside the triangle
	bool resultOnEdge = bsp(a, b, c, pointOnEdge);
	bool resultOnVertex = bsp(a, b, c, a);

	// Print the result
	printPointStatus(pointOnEdge, resultOnEdge);
	printPointStatus(a, resultOnVertex);
	return 0;
}
