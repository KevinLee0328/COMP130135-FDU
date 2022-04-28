#ifndef GUARD_Date
#define GUARD_Date 

class Date {
public:
	Date();
	Date(int, int, int);
	Date(std::istream&);
	int year() const { return dateyear; }
	int month() const { return datemonth; }
	int day() const { return dateday; }
	std::ostream& output(std::ostream&);
	Date plus_one_day();
	Date plus_one_month();
	Date plus_one_year();
private:
	int dateyear, datemonth, dateday;
};

int inteval(Date, Date);
bool isvaliddate(Date);
bool checkerror(Date);
bool isleapyear(int);

#endif

