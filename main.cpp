#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;

enum Grade
{
	F = 1,  // неявка
	D = 2,  // неудовлетворительно
	C = 3,  // удовлетворительно
	B = 4,  // хорошо
	A = 5,  // отлично      
};

struct Student
{
	int Id;
	Grade Mark;
	char Name[7];
};

int main()
{
	Grade mark = Grade::B;
	cout << static_cast<int>(mark) << endl;

	Grade userMark;
	int i;
	cin >> i;
	userMark = static_cast<Grade>(i);

	Student student;
	student.Id = GetRandomValue(1, 1000);
	student.Mark = static_cast<Grade>(GetRandomValue(1, 5));
	int temp = GetRandomValue(3, 6);
	for (int i = 0; i < temp; ++i)
	{
		student.Name[i] = GetRandomValue('a', 'z');
	}
	student.Name[temp] = '\0';

	/*
	int data[SIZE] = { 2,3,4,3,2,1,3,4 };

	for (int i = 0; i < SIZE; ++i)
	{
		bool hasSwap = false;
		for (int j = 0; j < SIZE - 1 - i; ++j)
		{
			if (data[j] > data[j + 1])
			{
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
				hasSwap = true;
			}
		}
		if (!hasSwap)
		{
			break;
		}
	}
	*/
}