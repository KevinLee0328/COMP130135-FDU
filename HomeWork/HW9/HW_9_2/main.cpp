#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ios>
#include "handle.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::domain_error;
using std::sort;
using std::setprecision;
using std::streamsize;

ifstream& readinfo(ifstream& is, vector<Handle>& shapes)
{
	Handle record;
	while (record.read(is)) {
		if (record.isvalid()) {
			shapes.push_back(record);
		}
	}
	return is;
}

ofstream& cal_output(vector<Handle>& shapes)
{
	ofstream outfile("result.csv");
	
	cout << endl;
	cout << "Area" << "    " << "Perimeter" << endl;
	outfile << "Area,Perimeter" << endl;
	
	for (vector<Handle>::size_type i = 0; i != shapes.size(); ++i) {
		streamsize prec_cout = cout.precision();
		streamsize prec_outfile = outfile.precision();
		cout << setprecision(3) << shapes[i].area() << space(shapes[i].area()) << shapes[i].perimeter() << setprecision(prec_cout) << endl;
		outfile << setprecision(3) << shapes[i].area() << "," << shapes[i].perimeter() << setprecision(prec_outfile) << endl;
	}
	
	return outfile;
}

int main()
{
	vector<Handle> shapes;
	ifstream infile("shapes");
	readinfo(infile, shapes);
	sort(shapes.begin(), shapes.end(), compare);
	cal_output(shapes);
	
	return 0;
}
