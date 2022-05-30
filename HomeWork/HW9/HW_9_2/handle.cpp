#include <iostream>
#include <sstream>
#include <iomanip>
#include <ios>

#include "shape.h"
#include "handle.h"

using std::istream;
using std::cout;
using std::endl;
using std::domain_error;

istream& Handle::read(istream& is)
{
	delete cp;

	char ch;
	is >> ch;
	
	if (ch == 'T') {
		valid = true;
		try {
			cp = new Triangle(is);
		} catch (domain_error error_message) {
			valid = false;
			cp = 0;
			cout << error_message.what() << endl;
		}
	}
	else if (ch == 'R') {
		valid = true;
		cp = new Rectangle(is);
	}
	else {
		valid = true;
		cp = new Circle(is);
	}
	
	return is;
}

Handle::Handle(const Handle& s): cp(0), valid(false)
{
	if (s.cp) cp = s.cp->clone();
}

Handle& Handle::operator=(const Handle& s)
{
	if (&s != this) {
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}
	return *this;
}


bool compare(Handle x, Handle y) {
	return x.area() < y.area();
}

std::string space(double x) {
	std::ostringstream os;
	std::streamsize prec = os.precision();
	os << std::setprecision(3) << x << std::setprecision(prec);
	std::string space_output(8 - os.str().size(), ' ');
	return space_output;
}
