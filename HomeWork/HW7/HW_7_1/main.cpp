#include <iostream>
#include "Str.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
	cout << "please enter your first name: ";
	Str name;
	cin >> name;
	const Str greeting = "Hello, " + name + "!";
	cout << "please enter the number of the blanks surrounding the greeting: ";
	int blk;
	cin >> blk;
	cout << endl;
	const int rows = blk * 2 + 3;
	const Str::size_type cols = greeting.size() + blk * 2 + 2;
	for(int r = 0; r < rows; ++r) {
		Str::size_type c = 0;
		while(c < cols){
			if(c == blk + 1 && r == blk + 1) {
				cout << greeting;
				c += greeting.size();
			}
			else{
				if(c * r == 0 || c == cols - 1 || r == rows - 1){
					cout << "*";
				}
				else{
					cout << " ";
				}
				++c;
			}
		}
		cout << endl;
	}
	cout << "逐个字符输出greeting(字符之间以空格分隔):" << endl;
	for(Str::size_type i = 0; i < greeting.size(); ++i) {
		cout << greeting[i] << " ";
	}
	cout << endl;
	return 0;
}

