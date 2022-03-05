#include<iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
	cout << "Enter the side length of a square: ";
	int len;
	cin >> len; 
	for(int i = 0; i < len; ++i){
		for(int j = 0; j < len; ++j){
			cout << "* ";
		}
		cout << endl;
	}
	cout << "Enter the side length and width of a rectangle: ";
	int wid;
	cin >> len; cin >> wid;
	for(int i = 0; i < wid; ++i){
		for(int j = 0; j < len; ++j){
			cout << "* ";
		}
		cout << endl;
	}
	cout << "Enter the base length of an isosceles triangle(odd number): ";
	cin >> len;
	for(int i = 0; i < len / 2 + 1; ++i){
		for(int j = 0; j < len / 2 - i; ++j){
			cout << "  ";
		}
		for(int j = 0; j < i * 2 + 1; ++j){
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}

