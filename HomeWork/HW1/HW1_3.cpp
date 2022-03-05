#include<iostream>
using std::cout; using std::cin; using std::endl;

void february(int year, int *day){
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) *day = 29;
	else *day = 28;
	return;
}
int main()
{
	const int month_of_year = 12; int day_of_month[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
	int day, month, year;
	cout << "Enter the baby's birthday: ";
	cin >> year; cin >> month; cin >> day;
	february(year, day_of_month + 1);
	for(int i = 0; i < 99; ++i){
		++day;
		if(day > day_of_month[month-1]){
			++month;
			day = 1;
		}
		if(month > month_of_year){
			++year;
			month = 1;
			february(year, day_of_month + 1);
		}
	}
	cout << "The baby's 100-day date is: " << year << " " << month << " " << day << endl;
	return 0;
}

