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
	cout << "\t\t食堂某个窗口高峰期的排队状况模拟：" << endl;
	while(1){
		if(time % 8 == 0){
			++incount;
			if(!queue.enqueue(incount, time)){
				cerr << "enqueue error!" << endl;
				return 1;
			}
			cout << time << "s：第" << incount << "人进队." << endl;
		}
		if(time % 25 == 0 && time != 0){
			++outcount;
			if(!queue.dequeue()){
				cerr << "dequeue error!" << endl;
				return 1;
			}
			cout << "\t\t" << time << "s：第" << outcount << "人出队." << endl;
		}
		if(queue.isfull()) break;
		++time;
	}
	cout << "\t\t该窗口排队人数已达到50人！请分流！" << endl;
	cout << "\t队首人员于" << queue.begin()->entime << "s入队." << endl; 
	cout << "\t队尾人员于" << queue.end()->entime << "s入队." << endl;
	return 0;
}
