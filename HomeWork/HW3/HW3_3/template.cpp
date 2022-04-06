#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include "template.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::list;

int main()
{
	srand((unsigned)time(NULL));
	list<int> ranint;
	for(int i = 0; i < 10; ++i)
		ranint.push_back(rand() % 100);
	cout << "The integer list:" << endl;
	output(ranint.begin(), ranint.end());
	int sumint = 0;
	cout << "The sum of the integer list: " << accumulate(ranint.begin(), ranint.end(), sumint) << endl
		 << "The max element in the integer list: " << *max_element(ranint.begin(), ranint.end()) << endl
		 << "The min element in the integer list: " << *min_element(ranint.begin(), ranint.end()) << endl
		 << endl;

	list<double> randb;
	for(int i = 0; i < 10; ++i){
		double tempdb = 0, digit = 1;
		for(int j = 0; j < 7; ++j){
			tempdb += rand() % 10 * digit;
			digit /= 10;
		}
		randb.push_back(tempdb);
	}
	cout << "The double list:" << endl;
	output(randb.begin(), randb.end());
	double sumdb = 0;
	cout << "The sum of the double list: " << accumulate(randb.begin(), randb.end(), sumdb) << endl
		 << "The max element in the double list: " << *max_element(randb.begin(), randb.end()) << endl
		 << "The min element in the double list: " << *min_element(randb.begin(), randb.end()) << endl
		 << endl;

	list<string> ranstr;
	string space = "0";
	for(int i = 0; i < 10; ++i){
		string tempstr = "";
		int count = rand() % 6 + 1;
		for(int j = 0; j < count; ++j){
			space[0] = rand() % 26 + 'a';
			tempstr = tempstr + space;
		}
		ranstr.push_back(tempstr);
	}
	cout << "The string list:" << endl;
	output(ranstr.begin(), ranstr.end());
	string sumstr = "";
	cout << "The sum of the string list: " << accumulate(ranstr.begin(), ranstr.end(), sumstr) << endl
		 << "The max element in the string list: " << *max_element(ranstr.begin(), ranstr.end()) << endl
		 << "The min element in the string list: " << *min_element(ranstr.begin(), ranstr.end()) << endl
		 << endl;
	return 0;
}
