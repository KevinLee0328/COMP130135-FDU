#ifndef GUARD_handle_h
#define GUARD_handle_h

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "shape.h"

class Handle {
public:
	Handle(): cp(0), valid(false) { }
	Handle(std::istream& is): cp(0), valid(false) { read(is); }
	Handle(const Handle&);
	Handle& operator=(const Handle&);
	~Handle() { delete cp; }

	std::istream& read(std::istream&);
	bool isvalid() const { return valid; }
	double area() const {
		if (cp) return cp->area();
		else throw std::runtime_error("uninitialized Shape");
	}
	double perimeter() const {
		if (cp) return cp->perimeter();
		else throw std::runtime_error("uninitialized Shape");
	}

private:
	Shape* cp;
	bool valid;
};

bool compare(Handle, Handle);

std::string space(double);

#endif

