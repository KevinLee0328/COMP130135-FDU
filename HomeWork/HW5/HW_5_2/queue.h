#ifndef GUARD_QUEUE_H_
#define GUARD_QUEUE_H_

#include <iostream>

struct Node { int number; long entime; Node* next;};

class Queue
{
private:
	enum {MAXSIZE = 50};
	Node* first;
	Node* last;
	int count;
	const int maxsize;
	Queue(const Queue& q) : maxsize(0) { }
	Queue& operator=(const Queue& q) { return *this;}
public:
	Queue(int qs = MAXSIZE);
	~Queue();
	bool isempty() const { return count == 0;}
	bool isfull() const { return count == maxsize;}
	Node* begin() const { return first;} 
	Node* end() const { return last;} 
	int size() const { return count;}
	bool enqueue(int, long);
	bool dequeue();
	std::ostream& print(std::ostream&) const;
};
#endif
