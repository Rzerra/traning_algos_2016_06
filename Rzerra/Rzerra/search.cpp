#include <iostream>
#include <algorithm>
using namespace std;

template <class TIter, class T>
TIter binarySearch(TIter b, TIter e, const T& key)
{
	assert(std::is_sorted(b, e));
	auto end = e;
	while(b<e)
	{
		TIter m = b+(e-b)/2; // [b, m) U [m] U [m+1, e)

		if(key<*m)
			e = m; // [b, m)
		else if(key>*m)
			b = m+1; // [m+1, e)
		else
			return m;
	}
	return end;
}

template <class TIter, class T>
TIter lowerBound(TIter b, TIter e, const T& key) // [ 1, 2, 3, 4, 5, 5, 5, 5, 8 ) key = 5 m = first 5
{
	assert(std::is_sorted(b, e));
	while(b<e)
	{
		TIter m = b+(e-b)/2; // [b, m) U [m] U [m+1, e)

		if(key>*m)
			b = m+1; // [m+1, e)
		else
			e = m; // [b, m)
	}
	return b;
}

template <class TIter, class T>
TIter upperBound(TIter b, TIter e, const T& key) // [ 1, 2, 3, 4, 5, 5, 5, 5, 8 ) key = 5 m = last 5
{
	assert(std::is_sorted(b, e));
	while(b<e)
	{
		TIter m = b+(e-b)/2; // [b, m) U [m] U [m+1, e)

		if(key<*m)
			e = m; // [b, m)
		else
			b = m+1; // [m+1, e)
	}
	return b;
}

template <class TIter, class T>
TIter binarySearch2(TIter b, TIter e, const T& key)
{
	auto lb = lowerBound(b, e, key);
	if(lb!=e && *lb==key)
		return lb;
	return e;
}

void main()
{
	;
}
