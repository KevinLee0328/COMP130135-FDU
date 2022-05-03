#include "queue.h"
#include <iostream> 
#include <cstddef>

Queue::Queue(int qs) : maxsize(qs)
{
    first = last = NULL;
    count = 0;
}

Queue::~Queue()
{
    Node* temp;
    while (first != NULL)
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

bool Queue::enqueue(int num, long time)
{
    if (isfull())
        return false;
    Node* add = new Node;
    add->number = num;
    add->entime = time;
    add->next = NULL;
    count++;
    if (first == NULL)
        first = add;
    else
        last->next = add;
    last = add;
    return true;
}

bool Queue::dequeue()
{
    if (first == NULL)
        return false;
    count--;
    Node *temp = first;
    first = first->next;
    delete temp;
    if (count == 0)
        last = NULL;
    return true;
}

std::ostream& Queue::print(std::ostream& out) const
{
	Node* temp = first;
	while(temp != NULL)
	{
		out << temp->entime << "s：第" << temp->number << "人进队." << std::endl;
		temp = temp->next;
	}
	return out; 
}
