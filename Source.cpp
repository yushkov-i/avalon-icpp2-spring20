#include <iostream>
#include "Extention.hpp"
#include <cstring>

using namespace std;
using namespace ext;

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
	char Name[7]{};
};

int main() {
	char length;
	int type_sort, x;
	bool k = 0;
	bool higher_name = 0;;
	char tmp[7]{};
	setlocale(LC_ALL, "Rus");
	Student list[100];
	for (int i = 0; i < 100; i++) {
			list[i].Id = GetRandomValue(1, 1000);		
			while (k == 0) {
				k = 1;
				for (int j = 0; j < i; j++) {
					if (list[j].Id == list[i].Id) {
						list[i].Id = GetRandomValue(1, 1000);
						k = 0;
						break;
					}
				}
			}
			cout << list[i].Id << " - ";
			length = GetRandomValue(3, 6);
			for (int j = 0; j < length; j++) {
				list[i].Name[j] = GetRandomValue(97, 122);
			}
			cout << list[i].Name << ", ";
			list[i].Mark = static_cast<Grade>(GetRandomValue(1, 5));
			cout << list[i].Mark << endl;
	}
	cout << "¬ведите 1 дл€ сортировки по ID, 2 - по Mark, 3 - по Name: ";
	cin >> type_sort;
	k = 0;
	switch (type_sort) {
	case 1:
		while (k == 0) {
			k = 1;
			for (int i = 0; i < 99; i++) {
				if (list[i].Id > list[i + 1].Id) {
					x = list[i].Id;
					list[i].Id = list[i + 1].Id;
					list[i + 1].Id = x;
					strcpy_s(tmp, list[i].Name);
					strcpy_s(list[i].Name, list[i + 1].Name);
					strcpy_s(list[i + 1].Name, tmp);
					x = list[i].Mark;
					list[i].Mark = list[i + 1].Mark;
					list[i + 1].Mark = static_cast<Grade>(x);
					k = 0;
				}
			}
		};
		break;
	case 2:
		while (k == 0) {
			k = 1;
			for (int i = 0; i < 99; i++) {
				if (list[i].Mark > list[i + 1].Mark) {
					x = list[i].Id;
					list[i].Id = list[i + 1].Id;
					list[i + 1].Id = x;
					strcpy_s(tmp, list[i].Name);
					strcpy_s(list[i].Name, list[i + 1].Name);
					strcpy_s(list[i + 1].Name, tmp);
					x = list[i].Mark;
					list[i].Mark = list[i + 1].Mark;
					list[i + 1].Mark = static_cast<Grade>(x);
					k = 0;
				}
			}
		};
		break;
	case 3: 
		while (k == 0) {
		k = 1;
		for (int i = 0; i < 99; i++) {
			if (strlen(list[i].Name) > strlen(list[i].Name)) {
				higher_name = 0;
				for (int t = 0; t < strlen(list[i].Name); t++) {
					if (list[i].Name[t] > list[i + 1].Name[t]) {
						higher_name = 0;
						break;
					}
					else {
						if (list[i].Name[t] == list[i + 1].Name[t]) {
							continue;
						}
						else {
							higher_name = 1;
							break;
						}
					}
				}
			}
			else {
				higher_name = 0;
				for (int t = 0; t < strlen(list[i + 1].Name); t++) {
					if (list[i].Name[t] > list[i + 1].Name[t]) {
						higher_name = 0;
						break;
					}
					else {
						if (list[i].Name[t] == list[i + 1].Name[t]) {
							continue;
						}
						else {
							higher_name = 1;
							break;
						}
					}
				}
			}
			if (higher_name == 0) {
				x = list[i].Id;
				list[i].Id = list[i + 1].Id;
				list[i + 1].Id = x;
				strcpy_s(tmp, list[i].Name);
				strcpy_s(list[i].Name, list[i + 1].Name);
				strcpy_s(list[i + 1].Name, tmp);
				x = list[i].Mark;
				list[i].Mark = list[i + 1].Mark;
				list[i + 1].Mark = static_cast<Grade>(x);
				k = 0;
			}
		}
	};
	break;

	}
	for (int i = 0; i < 100; i++) {
		cout << list[i].Id << " - ";
		cout << list[i].Name << ", ";
		cout << list[i].Mark << endl;
	}
}