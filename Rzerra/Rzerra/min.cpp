#include <iostream>
using namespace std;

int* findMin(int* b, int* e)
{
	int* m = b;
	while(++b<e)
	{
		if(*b<*m)
			m = b;
	}
	return m;
}

void main()
{
	int a[5] = {5, 7, 1, 3, 9};
	cout<<*findMin(&a[0], &a[5])<<endl;
}
