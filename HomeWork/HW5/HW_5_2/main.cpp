#include <iostream>
#include "queue.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

int main()
{
	Queue queue(50);
	long time = 0;
	int incount = 0, outcount = 0;
	cout << "\t\tʳ��ĳ�����ڸ߷��ڵ��Ŷ�״��ģ�⣺" << endl;
	while(1){
		if(time % 8 == 0){
			++incount;
			if(!queue.enqueue(incount, time)){
				cerr << "enqueue error!" << endl;
				return 1;
			}
			cout << time << "s����" << incount << "�˽���." << endl;
		}
		if(time % 25 == 0 && time != 0){
			++outcount;
			if(!queue.dequeue()){
				cerr << "dequeue error!" << endl;
				return 1;
			}
			cout << "\t\t" << time << "s����" << outcount << "�˳���." << endl;
		}
		if(queue.isfull()) break;
		++time;
	}
	cout << "\t\t�ô����Ŷ������Ѵﵽ50�ˣ��������" << endl;
	cout << "\t������Ա��" << queue.begin()->entime << "s���." << endl; 
	cout << "\t��β��Ա��" << queue.end()->entime << "s���." << endl;
	return 0;
}
