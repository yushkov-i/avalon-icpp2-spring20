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
	int swap, criterion;
	char ChSwap[7];
	int count1=0, count2=0, count3=0, count4=0, count5=0, moda=0, tempmoda=0;

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
				if (/*static_cast<int>(*/Students[j].Mark/*)*/ > /*static_cast<int>(*/Students[j + 1].Mark/*)*/) {
					swap = /*static_cast<int>(*/Students[j].Mark/*)*/;
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
						for (int l = 0; l < 7; l++) {
							ChSwap[l] = Students[j].Name[l];
						};
						for (int l = 0; l < 7; l++) {
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
		switch (Students[i].Mark) {
		case 1:
			count1 += 1;
			break;
		case 2:
			count2 += 1;
			break;
		case 3:
			count3 += 1;
			break;
		case 4:
			count4 += 1;
			break;
		case 5:
			count5 += 1;
			break;
		}
	}
	tempmoda = count1;
	if (count2 > tempmoda){
		tempmoda = count2;	
	}
	if (count3 > tempmoda) {
		tempmoda = count3;
	}
	if (count4 > tempmoda) {
		tempmoda = count4;
	}
	if (count5 > tempmoda) {
		tempmoda = count5;
	}
	
	if (count1 == tempmoda) {
		moda = 1;
	}
	if (count2 == tempmoda) {
		moda = 2;
	}
	if (count3 == tempmoda) {
		moda = 3;
	}
	if (count4 == tempmoda) {
		moda = 4;
	}
	if (count5 == tempmoda) {
		moda = 5;
	}
	cout <<endl<< "moda = " << moda << endl;

	




}

