#include <stdexcept>
#include "Vec.h"
#include "grade.h"
#include "median.h"

using std::domain_error;  using std::vector;


// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because `median' does so for us.
double grade(double midterm, double final, const Vec<double>& hw)
{
	return grade(midterm, final, median(hw.begin(), hw.end()));
}

const char* letter_grade(double grade)
{
	static const char* const letters[]={"A","A-","B+","B","B-","C+","C","C-","D","F"};
	if(grade <= 100 && grade >= 90) return letters[0];
	else if(grade < 90 && grade >= 85) return letters[1];
	else if(grade < 85 && grade >= 82) return letters[2];
	else if(grade < 82 && grade >= 78) return letters[3];
	else if(grade < 78 && grade >= 75) return letters[4];
	else if(grade < 75 && grade >= 71) return letters[5];
	else if(grade < 71 && grade >= 66) return letters[6];
	else if(grade < 66 && grade >= 62) return letters[7];
	else if(grade < 62 && grade >= 60) return letters[8];
	else return letters[9];
}
