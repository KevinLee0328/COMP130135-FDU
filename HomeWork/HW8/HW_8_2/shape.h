#include <iostream>
#include <string>

class Shape{
public:
	virtual std::istream& read(std::istream&) = 0;
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual ~Shape() { }
}; 

class Triangle : public Shape {
public:
	Triangle() : a(0), b(0), c(0) { }
	std::istream& read(std::istream&);
	double area() const;
	double perimeter() const;
private:
	double a, b, c;
};

class Rectangle : public Shape {
public:
	Rectangle() : a(0), b(0) { }
	std::istream& read(std::istream&);
	double area() const;
	double perimeter() const;
private:
	double a, b;
};

class Circle : public Shape {
public:
	Circle() : r(0) { }
	std::istream& read(std::istream&);
	double area() const;
	double perimeter() const;
private:
	const double PI = 3.1416;
	double r;
};

bool comp(Shape*, Shape*);

std::string space(double);