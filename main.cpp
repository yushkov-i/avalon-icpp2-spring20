#include "Point.hpp"
#include <iostream>
#include <cstdio>
using namespace std;

int add(long long int a, long long int b)
{
	a = a + b;
	return a + b;
}

int add(int a, int b)
{
	a = a + b;
	return a + b;
}

double add(double a, double b)
{
	a = a + b;
	return a + b;
}

int main()
{
	int val2 = add(5.6, 6.0);
	int val3 = add(5.7, 6.7);

	long long a = 6;
	long long b = 6;
	int c = 5;

	int val = add(a, static_cast<long long>(c));

	//int val2 = add(5, 6, 7);
	   
	Point first{ 5,6 };
	Point second{ 6,7 };	

	if (first != second)
	{
		cout << "Point is equal" << endl;
	}
	else
	{
		cout << "Point is not equal" << endl;
	}

	Point third = first * 2;
	Point forth = 2 * first;	
}