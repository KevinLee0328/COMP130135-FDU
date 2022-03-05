#include<iostream>
using std::cout; using std::cin; using std::endl; using std::string;
int main()
{
	cout << "Enter 3 English words: ";
	string str1, str2, str3, temp;
	cin >> str1 >> str2 >> str3;
	if(str1 > str2){
		temp = str1; str1 = str2; str2 = temp;
	}
	if(str1 > str3){
		temp = str1; str1 = str3; str3 = temp;
	}
	if(str2 > str3){
		temp = str2; str2 = str3; str3 = temp;
	}
	cout << str1 << " " << str2 << " " << str3 << endl;
	return 0;
}

