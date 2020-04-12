#include <iostream>
using namespace std;

struct Point
{
	int x;
	int y;
};

struct Circle
{
	Point center;
	int radius;
};

void print(const Point& point)
{
	cout << point.x << " " << point.y;
}

void print(Circle& c)
{
	print(c.center);
	cout << " " << c.radius;
}

bool operator == (Point lhs, Point rhs)
{
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator < (Point lhs, Point rhs)
{
	return lhs.x < rhs.x && lhs.y < rhs.y;	 
}

bool operator == (Circle lhs, Circle rhs)
{
	return lhs.center == rhs.center
		&& lhs.radius == rhs.radius;
}

void swapCoortinate(Point * ptr)
{
	int temp = ptr->x; // (*ptr).x
	ptr->x = ptr->y;
	ptr->y = temp;
}

void swapCoortinate(Point & ref)
{
	int temp = ref.x; // (*ptr).x
	ref.x = ref.y;
	ref.y = temp;
}

/*
Point minPoint(Point lhs, Point rhs)
{
	return lhs < rhs ? lhs : rhs;
}
*/

Point * minPoint(Point * lhs, Point * rhs)
{
	return *lhs < *rhs ? lhs : rhs;
}

Point & minPoint(Point & lhs, Point & rhs)
{
	return lhs < rhs ? lhs : rhs;
}

Point & minPoint(Point points[], int size)
{
	int index = 0;
	Point min = points[0];
	for (int i = 0; i < size; ++i)
	{
		if (points[i] < min)
		{
			min = points[i];
			index = i;
		}
	}

	return points[index];
}

Point operator ++(Point& point)
{
	++point.x;
	++point.y;
	return point;
}

Point operator ++(Point& point, int)
{
	Point temp = point;
	++point.x;
	++point.y;

	return temp;	
}

int main()
{
	Point p{ 4,5 };
	Point pp{ 7,8 };
	Circle c{ {5,6},7 };
	Circle cc{ {2,3}, 4 };

	print(p);
	cout << endl;
	print(c);
	cout << endl;

	bool result = (p == p);
	bool result2 = (c == cc);
	bool result3  = operator == (c, c);

	//Point * ptrMain = &p;
	//swapCoortinate(&p); // swapCoortinate(0x80);
	//swapCoortinate(p); // swapCoortinate(0x80)

	int a = 6; // 0x80
	int b = 7; // 0x84
	int * ptr; // 0xccccccccc
	ptr = &a; // 0x80
	*ptr = 10; // a = 10
	ptr = &b; // 0x84
	*ptr = 14; // b = 14;

	int & refA = a;
	int & refrefA = a;
	refA = 20;
	refrefA = b; // a = 14;

	cout << a << endl;
	cout << refA << endl;
	cout << refrefA << endl;

	cout << ++a << endl; // 15, a = 15
	cout << a++ << endl; // 15, a = 16

	/*Point * ptrP = &p;
	Point * ptrPP = &pp;
	Point * minPtr = minPoint(ptrP, ptrPP)*/
	/*Point * minPtr = minPoint(&p, &pp); // minPoint(0x80, 0x88)
	swapCoortinate(*minPtr);*/

	Point & minP = minPoint(p, pp); // неявное преобразование
	swapCoortinate(minP); // 0x80

	Point points[3] = { {7,8},{1,2},{4,5} };
	Point & minPointFromArray = minPoint(points, 3);
	swapCoortinate(minPointFromArray);
	
	++a;
	a = a + 1;

	// (5,4)
	++p;
	// (6,5)
	print(p++); //консоль 6 5, а сама p станет(7,6)
}