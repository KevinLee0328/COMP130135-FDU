#include<iostream>
using std::cout; using std::cin; using std::endl; using std::string;
int main()
{
	cout << "输入始发站上车人数，车站数，终点站下车人数和所求的站点编号: ";
	int a,n,m,x;
	cin >> a >> n >> m >> x;
	if(x > n){
		cout << "error!" << endl;
		return 1;
	}
	if(x == n){
		cout << "第" << x << "站开出时车上的人数是: " << m << endl;
		return 0;
	}
	int sum = a, j = 0;
	if(n > 2){
		while(sum != 0){
			++j;
			sum = a; 
			int up1 = j, up2 = a, down = up1; 
			for(int i = 2; i < n - 1 ; ++i){
				down = up1; up1 += up2; up2 = down;
				sum = sum + up1 - down;
			}
			sum -= m;
		}
		sum = a;
		int up1 = j, up2 = a, down = up1; 
		for(int i = 2; i < x; ++i){
			down = up1; up1 += up2; up2 = down;
			sum = sum + up1 - down;
		}
	}
	else{
		cout << "第" << x << "站开出时车上的人数是: " << a << endl;
		return 0;
	}
	cout << "第" << x << "站开出时车上的人数是: " << sum << endl;
	return 0;
}

