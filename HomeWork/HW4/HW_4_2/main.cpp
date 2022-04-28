#include <iostream> 
#include <stdexcept>
#include "Date.h"

using std::cin;				using std::endl;
using std::cout;			using std::domain_error;

int main()
{
	cout << "请输入两个日期（年月日，以空格分隔）：" << endl;
	Date d1(cin);
	try {
		checkerror(d1);
	} catch (domain_error e) {
		cout << e.what() << endl;
		return 1;
	}
	Date d2(cin);
		try {
		checkerror(d2);
	} catch (domain_error e) {
		cout << e.what() << endl;
		return 1;
	}
	cout << "日期一："; d1.output(cout); cout << endl;
	cout << "日期二："; d2.output(cout); cout << endl;
	cout << "两个日期相隔天数为：" << inteval(d1, d2) << endl;
	cout << "给日期一增加一天为：";
	d1.plus_one_day().output(cout);
	cout << endl;
	cout << "给日期一增加一月为：";
	d1.plus_one_month().output(cout);
	cout << endl;
	cout << "给日期一增加一年为：";
	d1.plus_one_year().output(cout);
	cout << endl;
	return 0;
}
