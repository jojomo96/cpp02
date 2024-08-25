#include <iostream>
#include "Point.hpp"
#include "bsp.hpp"

int main() { {
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

		// Print the results
		std::cout << "Point (5.0, 5.0) is " << (result1 ? "inside" : "outside") << " the triangle." << std::endl;
		std::cout << "Point (15.0, 5.0) is " << (result2 ? "inside" : "outside") << " the triangle." << std::endl;
	} {
		// Define the vertices of the triangle
		const Point a(0.0f, 0.0f);
		const Point b(10.0f, 0.0f);
		const Point c(5.0f, 10.0f);

		// Define a point that lies on the edge of the triangle
		const Point pointOnEdge(5.0f, -0.003f);

		std::cout << pointOnEdge.getY() << std::endl;

		// Test if the point is inside the triangle
		bool resultOnEdge = bsp(a, b, c, pointOnEdge);

		// Print the result
		std::cout << "Point (5.0, 0.0) is " << (resultOnEdge ? "inside" : "outside") << " the triangle." << std::endl;
	}

	return 0;
}
