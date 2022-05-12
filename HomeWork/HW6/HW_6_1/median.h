#ifndef GUARD_median_h
#define GUARD_median_h

// 'median.h'
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <cstddef>

template <class In> 
bool comp(In x, In y){
	return *x > *y;
}

template <class In> 
typename std::iterator_traits<In>::value_type median(In begin, In end)
{

	std::vector<In> temp;
	for(In iter = begin; iter != end ; ++iter) temp.push_back(iter);

	typedef typename std::vector<In>::size_type vec_sz;
	vec_sz size = temp.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");

	std::sort(temp.begin(), temp.end(), comp<In>);

	vec_sz mid = size/2;

	return size % 2 == 0 ? (*temp[mid] + *temp[mid-1]) / 2 : *temp[mid];
}

#endif

