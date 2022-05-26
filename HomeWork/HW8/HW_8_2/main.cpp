#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ios>
#include "shape.h"

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

int main()
{
	ifstream infile("shapes");
	ofstream outfile("result.csv");
	vector<Shape*> shapes;
	Shape* record;
	char ch;

	while (infile >> ch) {
		if (ch == 'T') {
			record = new Triangle;
			try {
				record->read(infile);
				shapes.push_back(record);
			} catch (domain_error error_message) {
				cout << error_message.what() << endl;
				delete record;
			}
		}
		else if (ch == 'R') {
			record = new Rectangle;
			record->read(infile);
			shapes.push_back(record);
		}
		else {
			record = new Circle;
			record->read(infile);
			shapes.push_back(record);
		}
	}

	cout << endl;
	cout << "Area" << "    " << "Perimeter" << endl;
	outfile << "Area,Perimeter" << endl;

	sort(shapes.begin(), shapes.end(), comp);

	for (vector<Shape*>::size_type i = 0; i != shapes.size(); ++i) {
		streamsize prec_cout = cout.precision();
		streamsize prec_outfile = outfile.precision();
		cout << setprecision(3) << shapes[i]->area() << space(shapes[i]->area()) << shapes[i]->perimeter() << setprecision(prec_cout) << endl;
		outfile << setprecision(3) << shapes[i]->area() << "," << shapes[i]->perimeter() << setprecision(prec_outfile) << endl;
	}

	return 0;
}