#include "Point.hpp"

Point add(Point a, Point b)
{
	Point temp = { a.x + b.x, a.y + b.y };
	Print(temp);
	return temp;
}

void Print(Point p)
{
	std::cout << p.x << " " << p.y;
}

bool IsEqual(Point first, Point second)
{
	return first.x == second.x && first.y == second.y;
}

bool operator == (Point first, Point second)
{
	return first.x == second.x && first.y == second.y;
}

bool operator != (Point first, Point second)
{
	return !(first == second);
}

Point operator * (Point a, int mult)
{
	return Point{ a.x * mult, a.y * mult };
}

Point operator * (int mult, Point a)
{
	return a * mult;
}