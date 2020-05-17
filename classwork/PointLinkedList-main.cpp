#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;	
};

struct PointNode
{
	Point value;
	PointNode * nextNode;
};

PointNode * createLinkedList()
{
	PointNode * first = new PointNode{ Point{3,4}, nullptr };
	PointNode * second = new PointNode{ Point{5,6}, nullptr };
	PointNode * third = new PointNode{ Point{7,8}, nullptr };

	first->nextNode = second;
	second->nextNode = third;

	return first;
}

void printLinkedList(PointNode * mainPtr)
{
	if (mainPtr == nullptr)
	{
		return;
	}
	PointNode * currentPtr = mainPtr;
	do
	{
		Point currentPoint = currentPtr->value;
		cout << currentPoint.x << " " << currentPoint.y << endl;
		currentPtr = currentPtr->nextNode;
	} while (currentPtr != nullptr);
}

void addToLinkedList(PointNode * & mainPtr, const Point & newPoint)
{
	PointNode * newPointNode = new PointNode{ newPoint, nullptr };
	//newPointNode->value = newPoint;
	//newPointNode->nextNode = nullptr;

	newPointNode->nextNode = mainPtr;
	mainPtr = newPointNode;
}

int main()
{
	PointNode * mainPtr = createLinkedList(); // mainPtr = 0x80

	printLinkedList(mainPtr);
	cout << "------------------" << endl;

	Point point{ 9,10 };

	addToLinkedList(mainPtr, point); // mainPtr = 0x800
	printLinkedList(mainPtr);
}