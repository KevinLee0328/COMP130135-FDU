#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include "median.h"
#include "grade.h"
#include "Student_info.h"
#include "Vec.h" 

using std::cin;				using std::cout;
using std::sort;			using std::domain_error;
using std::endl;			using std::string;
using std::max;				using std::vector;
using std::ifstream;		using std::ofstream;
using std::cerr;			using std::size_t;

int main()
{
	ifstream infile("grades");
	ofstream outfile("final");
	Vec<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;       // the length of the longest name

	// read and store all the students' data.
	// Invariant: 'students' contains all the student records read so far
	//			'maxlen' contains the length of the longest name in 'students'
	while (record.read(infile)) {
		// find length of longest name
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	// write the names and grades
	for (Vec<Student_info>::size_type i = 0;
	     i != students.size(); ++i) {

		// write the name, padded on the right to 'maxlen+1' characters
		cout << students[i].name()
		     << string(maxlen + 1 - students[i].name().size(), ' ');
		outfile << students[i].name()
		     << string(maxlen + 1 - students[i].name().size(), ' ');

		// compute and write the grade
		try {
			double final_grade = students[i].grade();
			cout << letter_grade(final_grade) << endl;
			outfile << letter_grade(final_grade) << endl;
		} catch (domain_error e) {
			cerr << e.what() << endl;
			outfile << e.what() << endl;
		}
	}
	cout << endl; 
	
	cout << "the following is the result of testing median function on array" << endl
		 << "the random array is:" << endl;
	const size_t NDim = 11;
	int array[NDim];
	srand((unsigned)time(NULL));
	for(size_t i = 0; i < NDim ; ++i){
		array[i] = rand() % 90 + 10;
		cout << array[i] << " ";
	}
	cout << endl;
	cout << "the median of the array is: " << median(array, array + NDim) << endl
		 << "after median function called, the array is unchanged:" << endl;
	for(size_t i = 0; i < NDim ; ++i)
		cout << array[i] << " ";
	cout << endl;
	return 0;
}

