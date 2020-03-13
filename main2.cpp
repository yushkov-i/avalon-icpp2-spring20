#include<iostream>
#include<iomanip>
#include<C:/Users/Anton/source/repos/dz2/dz2/Extention.hpp>
using namespace ext;
using namespace std;
const int k = 100;
enum Grade
{
	F = 1,   // не€вка
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

Student input(Student n) {
	int letter, rnd;
	n.Id = GetRandomValue(1, 1000);
	n.Mark = static_cast<Grade>(GetRandomValue(F, A));
	rnd = GetRandomValue(3, 6);
	for (int j = 0; j < rnd; ++j) {
		letter = GetRandomValue('a', 'z');
		n.Name[j] = letter;
	}
	return n;
}

int main(){
	setlocale(0, "rus");
	int crit;
	Student Students[k] = { 0, F, "" }; 


	for (int i = 0; i < k; ++i) {
		Students[i] = input(Students[i]);
		cout << i + 1 << ") " << Students[i].Id << " " << Students[i].Mark << " " << Students[i].Name << endl;
	}
	cout << " ритерий сортировки(Id=1, Mark=2, Name=3): ";
	cin >> crit;
	if (crit == 1) {
		Student swap;
		for (int i = 0; i < k; ++i) {
			for (int j = i; j < k; ++j) {
				if (Students[i].Id > Students[j].Id) {
					swap = Students[i];
					Students[i] = Students[j];
					Students[j] = swap;
				}
			}
		}
	}
	else if (crit == 2) {
		Student swap;
		for (int i = 0; i < k; ++i) {
			for (int j = i; j < k; ++j) {
				if (Students[i].Mark < Students[j].Mark) {
					swap = Students[i];
					Students[i] = Students[j];
					Students[j] = swap;
				}
			}
		}
	}
	else if (crit == 3) {
		for (int i = 0; i < k; ++i) {
			for (int j = i; j < k; ++j) {
				for (int l = 0; l < 7; ++l) {
					char swapName[7] = "";
					if (Students[i].Name[l] > Students[j].Name[l]) {
						for (int a = 0; a < 7; ++a) {
							swapName[a] = Students[i].Name[a];
						}
						for (int a = 0; a < 7; ++a) {
							Students[i].Name[a] = Students[j].Name[a];
							Students[j].Name[a] = swapName[a];
						}

					}
					else {
						break;
					}
				}
			}
		}
	}
	cout << endl;
	for (int i = 0; i < k; ++i) {
		cout << i + 1 << ") " << Students[i].Id << " " << Students[i].Mark << " " << Students[i].Name << endl;
	}
	int mark[5] = { 0 };
	for (int i = 0; i < k; ++i) {
		switch (Students[i].Mark) {
		case 1:
			mark[0] += 1;
			break;
		case 2:
			mark[1] += 1;
			break;
		case 3:
			mark[2] += 1;
			break;
		case 4:
			mark[3] += 1;
			break;
		case 5:
			mark[4] += 1;
			break;
		}
	}
	int moda = 0, count = 0;
	for (int i = 0; i < 5; ++i) {
		if (mark[i] > count) {
			moda = i + 1;
		}
	}
	cout << "Moda = " << moda;

}