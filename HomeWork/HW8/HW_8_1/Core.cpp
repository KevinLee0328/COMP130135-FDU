#include <algorithm>
#include "Core.h"
#include "grade.h"

using std::min;
using std::istream;
using std::string;
using std::vector;
std::istream& read_hw(std::istream& in, std::vector<double>& hw);

string Core::name() const { return n; }

double Core::grade() const
{
	return ::grade(midterm, final, homework);
}

istream& Core::read_common(istream& in)
{
	in >> n >> midterm >> final;
	return in;
}

istream& Core::read(istream& in)
{
	read_common(in);
	read_hw(in, homework);
	return in;
}

istream& Grad::read(istream& in)
{
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}

double Grad::grade() const
{
	return min(Core::grade(), thesis);
}

bool compare(const Core& c1, const Core& c2)
{
	return c1.name() < c2.name();
}

bool compare_Core_ptrs(const Core* cp1, const Core* cp2)
{
	return compare(*cp1, *cp2);
}

