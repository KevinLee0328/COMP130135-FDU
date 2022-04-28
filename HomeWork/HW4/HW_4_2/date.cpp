#include <iostream>
#include <stdexcept>

#include "Date.h"

using std::ostream;
using std::istream;

Date::Date(): dateyear(0), datemonth(0), dateday(0) { }

Date::Date(int y, int m, int d) { dateyear = y; datemonth = m; dateday = d; }

Date::Date(istream& is) { is >> dateyear >> datemonth >> dateday; }

ostream& Date::output(ostream& out){
	out << dateyear << "Äê" << datemonth << "ÔÂ" << dateday << "ÈÕ"; 
	return out;
}	

Date Date::plus_one_day() {
	int y = dateyear, m = datemonth, d = dateday;
	const int month_of_year = 12; int day_of_month[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
	if(isleapyear(y)) day_of_month[1] = 29;
	else day_of_month[1] = 28;
	++d;
	if(d > day_of_month[m-1]){
		++m;
		d = 1;
	}
	if(m > month_of_year){
		++y;
		m = 1;
	}
	Date date(y, m, d);
	return date;
}

Date Date::plus_one_month() {
	int y = dateyear, m = datemonth, d = dateday;
	const int month_of_year = 12; int day_of_month[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
	if(isleapyear(y)) day_of_month[1] = 29;
	else day_of_month[1] = 28;
	++m;
	if(m > month_of_year){
		++y;
		m = 1;
	}
	if(d > day_of_month[m-1]){
		d = day_of_month[m-1];
	}
	Date date(y, m, d);
	return date;
} 

Date Date::plus_one_year(){
	int y = dateyear, m = datemonth, d = dateday;
	const int month_of_year = 12; int day_of_month[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
	++y;
	if(isleapyear(y)) day_of_month[1] = 29;
	else day_of_month[1] = 28;
	if(d > day_of_month[m-1]){
		d = day_of_month[m-1];
	}
	Date date(y, m, d);
	return date;
}

bool islater(const Date& x, const Date& y) {
	if (x.year() > y.year())
		return true;
	else if (x.year() < y.year())
		return false;
	if (x.month() > y.month())
		return true;
	else if (x.month() < y.month())
		return false;
	if (x.day() > y.day())
		return true;
	else
		return false;
}

bool isleapyear(int year){
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
	else return false;
}

bool isvaliddate(Date date)
{
	int year = date.year();
	int month = date.month();
	int day = date.day();
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if (month == 2)
    {
        if (isleapyear(year))
        {
            if (day > 29)
                return false;
        }
        else
        {
            if (day > 28)
                return false;
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }
    return true;
}

int inteval(Date d1, Date d2) {
	int i = 0;
	if (islater(d1, d2)){
		while(!(d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year())){
			d2 = d2.plus_one_day();
			++i;
		}	
	}
	else {
		while(!(d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year())){
			d1 = d1.plus_one_day();
			++i;
		}	
	}
	return i; 
}

bool checkerror(Date date)
{
	int year = date.year();
	int month = date.month();
	int day = date.day();
    if (year < 0){
    	throw std::domain_error("invalid year");
        return false;
	}
    if (month < 1 || month > 12){
    	throw std::domain_error("invalid month");
        return false;
	}
    if (day < 1 || day > 31){
    	throw std::domain_error("invalid day");
        return false;
	}
    if (month == 2)
    {
        if (isleapyear(year))
        {
            if (day > 29){
            	throw std::domain_error("invalid day");
                return false;
        	}
        }
        else
        {
			if (day > 28){
            	throw std::domain_error("invalid day");
                return false;
        	}
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30){
        	throw std::domain_error("invalid day");
            return false;
		}
    }
    return true;
}
