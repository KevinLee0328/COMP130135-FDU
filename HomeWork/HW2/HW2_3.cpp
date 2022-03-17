#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;						using std::cout;
using std::endl;					using std::string;
using std::vector;					using std::ostream;
typedef vector<int>::size_type vec_sz;

void multiply(vector<int>& passive, int positive){
	int temp = 0;
	vec_sz size = passive.size();
	for(vec_sz i = 0; i < size; ++i){
		temp += passive[i] * positive;
		passive[i] = temp % 10;
		temp /= 10;
	}
	while(temp > 0){
		passive.push_back(temp % 10);
		temp /= 10;
	}
}

void plus(vector<int>& passive, const vector<int>& positive){
	int temp = 0;
	vec_sz size_a = passive.size(), size_o = positive.size();
	if(size_a > size_o){
		for(vec_sz i = 0; i < size_o; ++i){
			temp = passive[i] + positive[i];
			passive[i] = temp % 10;
			passive[i + 1] += temp / 10;
		}
	}
	else{
		vec_sz i; 
		for(i = 0; i < size_a - 1; ++i){
			temp = passive[i] + positive[i];
			passive[i] = temp % 10;
			passive[i + 1] += temp / 10;
		}
		while (i < size_o){
			temp = passive[i] + positive[i];
			passive[i] = temp % 10;
			passive.push_back(temp / 10);
			++i; 
		}
	}
}

ostream& output(ostream& out, const vector<int>& number, int n){
	vec_sz size = number.size(); vec_sz i = size - 1;
	out << "1!";
	for(int j = 2; j <= n; ++j) out << "+" << j << "!";
	out << "=";
	while(number[i] == 0) i--;
	for( ; i > 0; i--) out << number[i];
	out << number[0];
	return out;
}

int main()
{
	vector<int> factorial, sum;
	factorial.push_back(1); sum.push_back(0);
	cout << "Enter n(1<=n<=50): ";
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		multiply(factorial, i);
		plus(sum, factorial);
	}
	output(cout, sum, n);
	return 0;
}
