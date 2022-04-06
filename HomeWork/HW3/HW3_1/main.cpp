#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include "grade.h"
#include "Student_info.h"

using std::cin;                     using std::setprecision;
using std::cout;                    using std::sort;
using std::domain_error;            using std::streamsize;
using std::endl;                    using std::string;
using std::max;                     using std::list;

int main()
{
	list<Student_info> students,fail;
	Student_info record;
	string::size_type maxlen = 0; 
	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}
	list<Student_info>::iterator iter = students.begin();
	while(iter != students.end()) {
	    iter->overall = 0;
		try {
			iter->overall = grade(*iter);
		} catch (domain_error e) {
			cout << iter->name
		    	 << string(maxlen + 1 - iter->name.size(), ' ');
			cout << e.what() << endl;
			iter = students.erase(iter);
			continue;
		}
		++iter;
	}
	students.sort(compare);
	fail = extract_fails(students);
	cout << "passing student records: " << endl;
	for (list<Student_info>::iterator iter = students.begin();
	     iter != students.end(); ++iter) {
	    	streamsize prec = cout.precision();
	    	cout << iter->name
		    	 << string(maxlen + 1 - iter->name.size(), ' ');
			cout << setprecision(3) << iter->overall
			     << setprecision(prec);
			cout << endl;
	}
	cout << "failing student records: " << endl;
	for (list<Student_info>::iterator iter = fail.begin();
	     iter != fail.end(); ++iter) {
	    	streamsize prec = cout.precision();
	    	cout << iter->name
		    	 << string(maxlen + 1 - iter->name.size(), ' ');
			cout << setprecision(3) << iter->overall
			     << setprecision(prec);
			cout << endl;
	}
	return 0;
}

