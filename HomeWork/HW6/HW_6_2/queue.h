#ifndef GUARD_QUEUE_H_
#define GUARD_QUEUE_H_

#include <iostream>
#include <cstddef>

template <class T>
class Queue
{
private:
    struct Node { T val; long entime; Node* next; };
public:
    typedef size_t size_type;
    
    Queue(size_type qs = MAXSIZE);
    Queue(const Queue& q);
    ~Queue();
    
    Queue& operator=(const Queue& q);
	
	bool enqueue(T, long);
    bool dequeue();
    
    Node* begin() const { return head; }
    Node* end() const { return rear; }
	
	size_type size() const { return count; }
    size_type limit() const { return maxsize; }
    bool isempty() const { return count == 0; }
    bool isfull() const { return count == maxsize; }

    std::ostream& output(std::ostream&) const;
private:
	enum { MAXSIZE = 50 };
	
	Node* head;
	Node* rear;
	size_type count;
	const size_type maxsize;
	
	void copylink(Node*);
	void freelink();
};

template <class T> 
Queue<T>::Queue(size_type qs) : maxsize(qs)
{
    head = rear = NULL;
    count = 0;
    std::clog << "default constructor called." << std::endl;
}

template <class T> 
Queue<T>::Queue(const Queue& q) : maxsize(q.limit())
{
	head = rear = NULL;
    count = 0;
	copylink(q.begin());
	std::clog << "copy constructor called." << std::endl;
}

template <class T> 
Queue<T>::~Queue()
{
    freelink();
    std::clog << "destructor called." << std::endl;
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& q)
{
    if (&q != this) {
        freelink();
        head = rear = NULL;
        count = 0;
        copylink(q.begin());
    }
    std::clog << "operator=() called." << std::endl;
    return *this;
}

template <class T> 
bool Queue<T>::enqueue(T num, long time)
{
    if (isfull())
        return false;
    Node* add = new Node;
    add->val = num;
    add->entime = time;
    add->next = NULL;
    count++;
    if (head == NULL)
        head = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

template <class T> 
bool Queue<T>::dequeue()
{
    if (head == NULL)
        return false;
    count--;
    Node *temp = head;
    head = head->next;
    delete temp;
    if (count == 0)
        rear = NULL;
    return true;
}

template <class T> 
std::ostream& Queue<T>::output(std::ostream& out) const
{
	Node* temp = head;
	int num = 0;
	while(temp != NULL)
	{
		out << temp->entime << " ";
		temp = temp->next;
		++num;
		if(num == 10){
			num = 0;
			out << std::endl;
		}
	}
    out << std::endl;
	return out; 
}

template <class T> 
void Queue<T>::copylink(Node* temp){
	while(temp != NULL)
	{
    	Node* add = new Node;
    	add->val = temp->val;
    	add->entime = temp->entime;
    	add->next = NULL;
    	count++;
    	if (head == NULL)
        	head = add;
    	else
        	rear->next = add;
    	rear = add;
    	temp = temp->next;
	}
}

template <class T>
void Queue<T>::freelink(){
	Node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
 
#endif
