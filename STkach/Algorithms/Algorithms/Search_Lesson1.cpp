#include <cassert>

int search_1(int m[], int size, int key);
int search_2(int m[], int size, int key);
int search_3(int m[], int size, int key);
int search_4(int m[], int size, int key);

int search_1(int m[], int size, int key)
{
	//assert(m != 0);
	assert(size >= 0);

	for (int i = 0; i < size; ++i)
	{
		if (m[i] == key)
			return i;
	}
	return -1;
}

int search_2(int m[], int size, int key)
{
	int i = 0;
	while (i < size)
	{
		if (m[i] == key)
			return i;

		++i;
	}
	return -1;
}

int search_3(int m[], int size, int key)
{
	m[size] = key;
	int i = 0;

	while (m[i] != key)
	{
		++i;
	}

	if (size == i)
	{
		return -1;
	}
	else
	{
		return i;
	}
}

int search_4(int m[], int size, int key)
{
	int end = key;
	int last = size - 1;
	int original_end = m[last];

	if (m[last] != end)
	{
		m[last] = end;
	}
	else
	{
		return last;
	}

	int i = 0;
	while (m[i] != key)
	{
		++i;
	}

	m[last] = original_end;

	if (last == i)
	{
		return -1;
	}
	else
	{
		return i;
	}

}