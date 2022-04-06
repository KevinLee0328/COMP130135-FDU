#include <iostream>

using std::ostream;
using std::cout;
using std::endl;

template <class T, class S>
S accumulate(T b, T e, S& t){
	for(T iter = b; iter != e; ++iter)
		t = t + *iter;
	return t;
}

template <class T>
T max_element(T b, T e){
	T maxl = b;
	for(T iter = b; iter != e; ++iter)
		if(*iter > *maxl)
			maxl = iter;
	return maxl;
}

template <class T>
T min_element(T b, T e){
	T minl = b;
	for(T iter = b; iter != e; ++iter)
		if(*iter < *minl)
			minl = iter;
	return minl;
}

template <class T>
ostream& output(T b, T e){
	for(T iter = b; iter != e; ++iter)
		cout << *iter << " ";
	cout << endl;
	return cout;
}
