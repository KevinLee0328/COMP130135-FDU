#include <iostream>
#include <algorithm>
#include "Str.h" 
#include "Vec.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "Enter some text: ";

	Str temp;
	Vec<Str> strvec;
	while (cin >> temp) 
		strvec.push_back(temp);

	std::sort(strvec.begin(), strvec.end());

	Str::size_type maxsize = 0;
	for (Vec<Str>::size_type i = 0; i < strvec.size(); ++i) 
		if (strvec[i].size() > maxsize) 
			maxsize = strvec[i].size();

	for (Vec<Str>::size_type i = 0; i < strvec.size(); ++i) {
		int sum = 1;
		while (i != (strvec.size() - 1) && strvec[i] == strvec[i + 1]) {
			++sum;
			++i;
		}
		cout << strvec[i] << Str(maxsize - strvec[i].size() + 1, ' ') << sum << endl;
	}

	return 0;
}
