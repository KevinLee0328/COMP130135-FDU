#include<iostream>
#include<string>
using std::cout; using std::cin; using std::string; using std::endl;

int main()
{
	cout << "please enter your first name: ";
	string name;
	cin >> name;
	const string greeting = "hello " + name + " !";
	cout << "please enter the number of the blanks surrounding the greeting: ";
	int blk;
	cin >> blk;
	cout << endl;
	const int rows = blk * 2 + 3;
	const string::size_type cols = greeting.size() + blk * 2 + 2;
	for(int r = 0; r < rows; ++r){
		string::size_type c = 0;
		while(c < cols){
			if(c == blk + 1 && r == blk + 1){
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
	return 0;
}

