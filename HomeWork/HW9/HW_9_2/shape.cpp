#include <iostream>
#include <string>
#include <stdexcept>
#include <string>
#include <cmath>
#include "shape.h"

const double Circle::PI = 3.1416;

std::istream& Triangle::read(std::istream& in) {
	in >> a >> b >> c;
	if (a + b <= c || b + c <= a || c + a <= b) {
		std::cout << a << ", " << b << ", " << c << " ";
		throw std::domain_error("can't make a triangle.");
	}
	return in;
}

double Triangle::area() const {
	double p = (a + b + c) / 2;
	return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::perimeter() const {
	return (a + b + c);
}

std::istream& Rectangle::read(std::istream& in) {
	in >> a >> b;
	return in;
}

double Rectangle::area() const {
	return a * b;
}

double Rectangle::perimeter() const {
	return (a + b) * 2;
}

std::istream& Circle::read(std::istream& in) {
	in >> r;
	return in;
}

double Circle::area() const {
	return PI * r * r;
}

double Circle::perimeter() const {
	return 2 * PI * r;
}
