#include <iostream>
using namespace std;

struct Point
{
	int x;
	int y;
};

int main()
{
	int * ptrInt = new int{4};
	double * ptrDouble = new double{5.5};

	cout << *ptrInt << endl;
	cout << ptrInt[5] << endl;

	cout << *ptrDouble << endl;

	*ptrInt = 10;
	*ptrDouble = 8.8;

	delete ptrDouble;
	ptrDouble = nullptr;
	delete ptrInt;
	ptrInt = nullptr;
	
	if (ptrDouble != nullptr)
	{
		cout << *ptrDouble << endl;
	}
	//много строк кода

	ptrDouble = new double{ 6.8 };

	Point * ptrPoint = new Point{ 5,6 };
	cout << ptrPoint->x << " " << ptrPoint->y << endl;
	ptrPoint->x = 7;
	ptrPoint->y = 8;
	cout << ptrPoint->x << " " << ptrPoint->y << endl;

	delete ptrPoint;
	ptrPoint = nullptr;

	ptrPoint = new Point{ 9,10 };

	int * ptrIntArray = new int[10]{1,2,3,4};
	cout << *(ptrIntArray + 1)<< endl;
	cout << ptrIntArray[1] << endl;

	delete[] ptrIntArray;

	Point * ptrPointArray = new Point[3]{};
	for (int i = 0; i < 3; ++i)
	{
		cout << ptrPointArray[i].x << " " << ptrPointArray[i].y << endl;
	}
	delete[] ptrPointArray;
}