#ifndef GUARD_shape_h
#define GUARD_shape_h

#include <iostream>

class Shape{
	friend class Handle;
public:
	virtual std::istream& read(std::istream&) = 0;
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual ~Shape() { }
protected:
	virtual Shape* clone() const = 0;
}; 

class Triangle : public Shape {
public:
	Triangle() : a(0), b(0), c(0) { }
	Triangle(std::istream& is) { read(is); }
	std::istream& read(std::istream&);
	double area() const;
	double perimeter() const;
private:
	double a, b, c;
	Triangle* clone() const { return new Triangle(*this); }
};

class Rectangle : public Shape {
public:
	Rectangle() : a(0), b(0) { }
	Rectangle(std::istream& is) { read(is); }
	std::istream& read(std::istream&);
	double area() const;
	double perimeter() const;
private:
	double a, b;
	Rectangle* clone() const { return new Rectangle(*this); }
};

class Circle : public Shape {
public:
	Circle() : r(0) { }
	Circle(std::istream& is) { read(is); }
	std::istream& read(std::istream&);
	double area() const;
	double perimeter() const;
private:
	static const double PI;
	double r;
	Circle* clone() const { return new Circle(*this); }
};

#endif
