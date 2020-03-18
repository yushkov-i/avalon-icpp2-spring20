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
	const int N = 5;
	Student stud[N];
	for (int i = 0; i < N; i++)
	{
		stud[i].Id = GetRandomValue(1, 1000);
		stud[i].Mark = static_cast<Grade>(GetRandomValue(1, 5));
		int lenght = GetRandomValue(3, 6);
		for (int k = 0; k < lenght; k++)
		{
			stud[i].Name[k] = GetRandomValue('a', 'z');
		}
		stud[i].Name[lenght] = '\0';
	};
	short choice;
	Student tmp;
	cout << "Sort by 1) Id 2) Mark 3) Name" << endl;
	cin >> choice;
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N - i - 1; k++)
		{
			if ((choice == 1) and (stud[k].Id > stud[k + 1].Id) or (choice == 2) and (stud[k].Mark > stud[k + 1].Mark) or (choice == 3) and (stud[k].Name[0] > stud[k + 1].Name[0]))
			{
				tmp = stud[k];
				stud[k] = stud[k + 1];
				stud[k + 1] = tmp;
			};
		};
	};
	for (int i = 0; i < N; i++)
	{
		cout << "Id: " << stud[i].Id << endl << "Mark: " << stud[i].Mark << endl << "Name: " << stud[i].Name << endl << endl;
	}

}