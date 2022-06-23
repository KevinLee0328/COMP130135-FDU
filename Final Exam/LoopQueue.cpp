#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

template<typename T>
class LoopQueue{
public:
	typedef typename vector<T>::size_type size_type;

	LoopQueue(int capacity) : data(capacity + 1) {
		first = last = 0;
	}

	bool isEmpty()const { return first == last; }
	bool isFull()const { return (last + 1) % data.size() == first; }

	size_type getLength()const {
		if (last >= first) return last - first;
		return last - first + data.size();
	}

	bool dequeue(T& e) {
		if (isEmpty()) return false;
		e = data[first];
		first = (first + 1) % data.size();
		return true;
	}
	bool enqueue(const T& e) {
		if (isFull()) return false;
		data[last] = e;
		last = (last + 1) % data.size();
		return true;
	}

	void print() {
		size_type i;
		for (i = first; i != last; i = (i + 1) % data.size()) {
			cout << "<" << data[i] << ">";
		}
		cout << endl;
	}

private:
	vector<T> data;
	size_type first, last;
};

int main()
{
	int a;
	LoopQueue<int> qu(3);
	for (int i = 1; i < 6; i++) {
		qu.enqueue(i);
	}
	qu.dequeue(a);
	cout << qu.getLength() << endl;
	qu.enqueue(a);
	cout << qu.getLength() << endl;
	qu.print();
	return 0;
}