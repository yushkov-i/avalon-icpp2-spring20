#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;
enum Grade
{
	F = 1,   // неявка
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
	const int N = 10;
	Student stud[N];
	int moda[5] = { 0, 0, 0, 0, 0 };
	int max = 0;
	int res;
	float prcnt;
	for (int i = 0; i < N; i++)
	{
		stud[i].Id = GetRandomValue(1, 1000);
		stud[i].Mark = static_cast<Grade>(GetRandomValue(1, 5));
		moda[stud[i].Mark - 1] = moda[stud[i].Mark - 1] + 1;
		int lenght = GetRandomValue(3, 6);
		for (int k = 0; k < lenght; k++)
		{
			stud[i].Name[k] = GetRandomValue('a', 'z');
		}
		stud[i].Name[lenght] = '\0';
		cout << "Id: " << stud[i].Id << endl << "Mark: " << stud[i].Mark << endl << "Name: " << stud[i].Name << endl << endl;
	};
	
	for (int i = 0; i < 5; i++)
	{
		if (moda[i] > max)
			max = moda[i];
	};
	
	cout << endl << "Moda : ";

	for (int k = 0; k < 5; k++)
	{
		if (moda[k] == max)
			cout << static_cast<Grade>(k + 1) << " ";
	};
	prcnt = 0.25;
	for (int i = 2; i <= 5; i++)
	{
		res = 0;
		for (int k = 0; k < N; k++)
		{
			if (i > stud[k].Mark)
				res = res + 1;
			if (res >= N * prcnt)
			{
				cout << endl << "> " << prcnt * 100 << "% - " << static_cast<Grade>(i);
				prcnt = prcnt + 0.25;
			}
		};
	};
}