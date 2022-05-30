#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>
#include "Student_info.h"

using std::cout;
using std::ifstream; 
using std::domain_error;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::sort;
using std::string;
using std::vector;
using std::max;

int main()
{
	ifstream infile("grades2");
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while (record.read(infile)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), Student_info::compare);

	for (vector<Student_info>::size_type i = 0;
	     i != students.size(); ++i) {
		cout << students[i].name()
		     << string(maxlen + 1 - students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
			     << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}

