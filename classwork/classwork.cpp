#include <cstdio>
#include <limits>
#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int maxValue(int data[], int size)
{
	int tempMax = data[0];
	int index = 0;
	for (int i = 1; i < size; ++i)
	{
		if (data[i] > tempMax)
		{
			tempMax = data[i];
			index = i;
		}
	}
	return index;
}

int* maxValuePtr(int data[], int size)
{
	int* ptr = &data[0];
	for (int i = 1; i < size; ++i)
	{
		if (*ptr < data[i])
		{
			ptr = &data[i];
		}
	}

	return ptr;
}

int& maxValueRef(int data[], int size)
{
	int tempMax = data[0];
	int index = 0;
	for (int i = 1; i < size; ++i)
	{
		if (data[i] > tempMax)
		{
			tempMax = data[i];
			index = i;
		}
	}
	return data[index];
}

int& max(int& a, int& b)
{
	return a > b ? a : b;
}

struct Point
{
	int x;
	int y;
};

void printPoint(Point point)
{
	cout << "x = " << point.x << endl;
	cout << "y = " << point.y << endl;
}

Point operator ++(Point& p)
{
	++p.x;
	++p.y;
	return p;
}

Point operator ++(Point& p, int)
{
	Point temp = p;
	++p.x;
	++p.y;
	return temp;	
}

int main()
{
	Point p{ 10,15 };
	
	Point pp = ++p;
	Point ppp = p++;	

	int a = 10;
	int b = a++;

	printPoint(p);

	int data[5] = { 5,4,7,3,6 };

	int maxIndex = maxValue(data, 5);
	data[maxIndex] *= 2;

	int* maxPtr = maxValuePtr(data, 5);
	*maxPtr *= 2;

	int& maxRef = maxValueRef(data, 5);
	maxRef = maxRef * 2;

	int a = 10;
	int b = 15;

	int& maxValue = max(a, b);
	maxValue *= 2;	
}
