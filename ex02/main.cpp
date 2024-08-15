#include <iostream>
#include "Fixed.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

void printTestResult(const std::string &testName, const Fixed &actual, const Fixed &expected) {
	std::cout << testName << ": " << actual << " (Expected: " << expected << ")";
	if (actual == expected) {
		std::cout << GREEN << " [PASS]" << RESET << std::endl;
	} else {
		std::cout << RED << " [FAIL]" << RESET << std::endl;
	}
}

void printTestResultBool(const std::string &testName, bool actual, bool expected) {
	std::cout << testName << ": " << (actual ? "true" : "false") << " (Expected: " << (expected ? "true" : "false") <<
			")";
	if (actual == expected) {
		std::cout << GREEN << " [PASS]" << RESET << std::endl;
	} else {
		std::cout << RED << " [FAIL]" << RESET << std::endl;
	}
}

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(10);
	Fixed d(10.5f);
	Fixed e(-5.5f);
	Fixed f(-10);

	std::cout << CYAN << "Initial Values:" << RESET << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;
	std::cout << "e: " << e << std::endl;
	std::cout << "f: " << f << std::endl;

	std::cout << CYAN << "\nIncrement/Decrement Tests:" << RESET << std::endl;
	printTestResult("++a", ++a, Fixed(1));
	printTestResult("a++", a++, Fixed(1));
	printTestResult("a", a, Fixed(2));
	printTestResult("--a", --a, Fixed(1));
	printTestResult("a--", a--, Fixed(1));
	printTestResult("a", a, Fixed(0));

	std::cout << CYAN << "\nArithmetic Tests:" << RESET << std::endl;
	printTestResult("b + c", b + c, Fixed(20.1f));
	printTestResult("b - c", b - c, Fixed(0.1f));
	printTestResult("b * c", b * c, Fixed(101.016f));
	printTestResult("b / c", b / c, Fixed(1.01f));

	std::cout << CYAN << "\nComparison Tests:" << RESET << std::endl;
	printTestResultBool("b > c", b > c, true);
	printTestResultBool("b < c", b < c, false);
	printTestResultBool("b >= c", b >= c, true);
	printTestResultBool("b <= c", b <= c, false);
	printTestResultBool("b == c", b == c, false);
	printTestResultBool("b != c", b != c, true);

	printTestResult("max(a, b)", Fixed::max(a, b), b);
	printTestResult("min(a, b)", Fixed::min(a, b), a);
	printTestResult("max(c, d)", Fixed::max(c, d), d);
	printTestResult("min(e, f)", Fixed::min(e, f), f);

	std::cout << CYAN << "\nCopy and Move Tests:" << RESET << std::endl;
	Fixed g(b); // Copy constructor
	printTestResult("Copy constructor", g, b);

	Fixed h(std::move(g)); // Move constructor
	printTestResult("Move constructor", h, b);
	printTestResultBool("g after move", g.getRawBits() == 0, true);
	// Check if g is in a valid state (typically 0 or some "moved-from" state)

	Fixed i;
	i = c; // Copy assignment operator
	printTestResult("Copy assignment", i, c);

	Fixed j;
	j = std::move(i); // Move assignment operator
	printTestResult("Move assignment", j, c);
	printTestResultBool("i after move", i.getRawBits() == 0, true); // Check if i is in a valid state

	return 0;
}
