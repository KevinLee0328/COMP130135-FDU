#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;                    using std::string;
using std::max;                     using std::vector;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0; 
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	for (vector<Student_info>::size_type i = 0;
	     i != students.size(); ++i) {
	    students[i].overall = 0;
		try {
			students[i].overall = grade(students[i]);
		} catch (domain_error e) {
			cout << students[i].name
		    	 << string(maxlen + 1 - students[i].name.size(), ' ');
			cout << e.what() << endl;
		}
	}
	sort(students.begin(), students.end(), compare);
	for (vector<Student_info>::size_type i = 0;
	     i != students.size(); ++i) {
	    if(students[i].overall != 0){
	    	streamsize prec = cout.precision();
	    	cout << students[i].name
		    	 << string(maxlen + 1 - students[i].name.size(), ' ');
			cout << setprecision(3) << students[i].overall
			     << setprecision(prec);
			cout << endl;
		}
	}
	return 0;
}

