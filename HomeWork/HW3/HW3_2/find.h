#include <iostream>
#include <algorithm>

using std::find;
using std::ostream;
using std::endl;

template <class T>
T lookfor(T is1, T is2)
{
	T os;
	for(typename T::iterator iter = is1.begin(); iter != is1.end(); ++iter){
		typename T::iterator result = find(is2.begin(), is2.end(), *iter);
		if(result != is2.end()) os.push_back(*iter);
	}
	return os;
}

template <class T>
ostream& output(ostream& out, T os){
	for(typename T::iterator iter = os.begin(); iter != os.end(); ++iter)
		out << *iter << " ";
	out << endl;
	return out;
}

