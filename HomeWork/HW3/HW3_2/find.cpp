#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include "find.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;

int main()
{
	vector<int> ranint1, ranint2;
	srand((unsigned)time(NULL));
	for(int i = 0; i < 13; ++i){
		ranint1.push_back(rand() % 20);
		ranint2.push_back(rand() % 20);
	}
	cout << "Random integer vector 1:" << endl;
	output(cout, ranint1);
	cout << "Random integer vector 2:" << endl;
	output(cout, ranint2);
	vector<int> osint = lookfor(ranint1, ranint2);
	cout << "Vector in common:" << endl;
	output(cout, osint);
	
	list<string> iptstr1, iptstr2;
	string temp;
	cout << "Enter some words for string list 1:" << endl;
	while(cin >> temp)
		iptstr1.push_back(temp);
	cout << "Enter some words for string list 2:" << endl;
	cin.clear();
	while(cin >> temp)
		iptstr2.push_back(temp);
	list<string> osstr = lookfor(iptstr1, iptstr2);
	cout << "List in common:" << endl;
	output(cout, osstr);
	return 0;
}


