#pragma once
#include <iostream>
struct Point
{
	int x;
	int y;
};

void Print(Point p);
Point add(Point a, Point b);
bool IsEqual(Point a, Point b);
bool operator == (Point a, Point b);
bool operator != (Point a, Point b);
Point operator * (Point a, int mult);
Point operator * (int mult, Point a);