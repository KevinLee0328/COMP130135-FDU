#include <iostream> 
#include <stdexcept>
#include "Date.h"

using std::cin;				using std::endl;
using std::cout;			using std::domain_error;

int main()
{
	cout << "�������������ڣ������գ��Կո�ָ�����" << endl;
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
	cout << "����һ��"; d1.output(cout); cout << endl;
	cout << "���ڶ���"; d2.output(cout); cout << endl;
	cout << "���������������Ϊ��" << inteval(d1, d2) << endl;
	cout << "������һ����һ��Ϊ��";
	d1.plus_one_day().output(cout);
	cout << endl;
	cout << "������һ����һ��Ϊ��";
	d1.plus_one_month().output(cout);
	cout << endl;
	cout << "������һ����һ��Ϊ��";
	d1.plus_one_year().output(cout);
	cout << endl;
	return 0;
}
