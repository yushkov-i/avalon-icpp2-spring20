#include <iostream>
#include <windows.h>
#include <C:\Users\Usserr\Desktop\C++\homework-02\homework-02\Extention.h>

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
const int n = 100;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int swap, criterion, sum=0;
	char ChSwap[7];
	int moda=1;
	int count[5] = { 0,0,0,0,0 };
	bool b75 = true;

	Student Students[n];
	for (int i = 0; i < n; ++i) {
		Students[i].Id = GetRandomValue(1, 1000);
		Students[i].Mark = static_cast<Grade>(GetRandomValue(1, 5));
		int temp;
		temp = GetRandomValue(3, 6);
		for (int j = 0; j < temp; ++j) {
			int symbol = GetRandomValue('a', 'z');  
			Students[i].Name[j] = symbol;
		}
		for (int j = temp; j < 7; ++j) 
		{
			Students[i].Name[j] = '\0';
		}
	}




	cout << "Выберите по какому критерию отсортировать студентов:\n1. По Id\n2. По Mark\n3. По Name\nСортировать по(1, 2, 3): ";
	cin >> criterion;
	switch (criterion) {
	case 1:
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n - 1 - i; ++j) {
				if (Students[j].Id > Students[j + 1].Id) {
					swap = Students[j].Id;
					Students[j].Id = Students[j + 1].Id;
					Students[j + 1].Id = swap;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n - 1 - i; ++j) {
				if (Students[j].Mark > Students[j + 1].Mark) {
					swap = Students[j].Mark;
					Students[j].Mark = Students[j + 1].Mark;
					Students[j + 1].Mark = static_cast<Grade>(swap);
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n - 1 - i; ++j) {
				for (int k = 0; k < 7; k++) {

					if (Students[j].Name[k] > Students[j + 1].Name[k]) {
						for (int l = 0; l < 7; ++l) {
							ChSwap[l] = Students[j].Name[l];
						};
						for (int l = 0; l < 7; ++l) {
							Students[j].Name[l] = Students[j + 1].Name[l];
							Students[j + 1].Name[l] = ChSwap[l];
						}
						break;
					}
					else if (Students[j].Name[k] < Students[j + 1].Name[k]) {
						break;
					}

				}
			}
		}
		break;
	}
	for (int i = 0; i < n; ++i) {
		switch (criterion) {
		case 1:
			cout << Students[i].Id << endl;
			break;
		case 2:
			cout << Students[i].Mark << endl;
			break;
		case 3:
			cout << Students[i].Name << endl;
			break;
		}
	}


	//moda
	for (int i = 0; i < n; ++i) {
		switch (static_cast<int>(Students[i].Mark)) {
		case 1:
			count[0] += 1;
			break;
		case 2:
			count[1] += 1;
			break;
		case 3:
			count[2] += 1;
			break;
		case 4:
			count[3] += 1;
			break;
		case 5:
			count[4] += 1;
			break;


		}
	}
	
	for (int i = 0; i < 5; ++i) {
		if (count[i] > count[moda-1]) 
		{ 
			moda = i + 1;
		}
		
	}
	cout << endl;
	for (int i = 1; i < 6; ++i) {
		cout << i << ": " << count[i - 1]<< endl;
	}
	cout <<endl<< "moda: " << moda << endl;

	
	for (int i = 0; i < 4; ++i) {
		sum = sum + count[i];
		if (sum > 25) {
			cout << "Вам нужно получить оценку: " << i + 2 << ", чтобы быть лучше 25%." << endl;     
			sum = 0;
			break;
		}
	}
	for (int i = 0; i < 4; ++i) {
		sum = sum + count[i];
		if (sum > 50) {
			cout << "Вам нужно получить оценку: " << i + 2 << ", чтобы быть лучше 50%." << endl;     
			sum = 0;
			break;
		}
	}
	for (int i = 0; i < 4; ++i) {
		sum = sum + count[i];
		if (sum > 75) {
			cout << "Вам нужно получить оценку: " << i + 2 << ", чтобы быть лучше 75%." << endl;    
			sum = 0;
			b75 = false;
			break;
		}
	}
	if (b75){ cout << "Вам нужно получить оценку: 5, чтобы быть лучше 75%." << endl; }


}

