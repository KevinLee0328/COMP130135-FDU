#include "Str.h"
#include <cctype>
#include <iostream>
#include <iterator>

using std::isspace;
using std::istream;
using std::istream_iterator;
using std::ostream;

ostream& operator<<(ostream& os, const Str& s)
{
	for (Str::size_type i = 0; i != s.size(); ++i)
		os << s[i];
	return os;
}

istream& operator>>(istream& is, Str& s)
{
	s.data.clear();
	char c;
	while (is.get(c) && isspace(c));
	if (is) {
		do	s.data.push_back(c);
		while (is.get(c) && !isspace(c));
		if (is)
			is.unget();
	}
	return is;
}

Str operator+(const Str& s, const Str& t)
{
	Str r = s;
	r += t;
	return r;
}

bool operator==(const Str& lhs, const Str& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	Str::const_iterator liter = lhs.begin();
	Str::const_iterator riter = rhs.begin();
	while (liter != lhs.end() && riter != rhs.end()) {
		if (*liter != *riter)
			return false;
		++liter;
		++riter;
	}
	return true;
}

bool operator!=(const Str& lhs, const Str& rhs) {
	return !(lhs == rhs);
}

bool operator>(const Str& lhs, const Str& rhs) {
	if (lhs == rhs)
		return false;
	Str::const_iterator liter = lhs.begin();
	Str::const_iterator riter = rhs.begin();
	while (liter != lhs.end() && riter != rhs.end()) {
		if (*liter > *riter)
			return true;
		if (*liter < *riter)
			return false;
		++liter;
		++riter;
	}
	if (liter == lhs.end() && riter != rhs.end())
		return false;
	return true;
}

bool operator<(const Str& lhs, const Str& rhs) {
	return rhs > lhs;
}

bool operator>=(const Str& lhs, const Str& rhs) {
	return !(lhs < rhs);
}

bool operator<=(const Str& lhs, const Str& rhs) {
	return !(lhs > rhs);
}