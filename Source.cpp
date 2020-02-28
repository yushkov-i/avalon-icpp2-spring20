#include <iostream>
#include "Extention.hpp"
#include <cstring>

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
	char Name[7]{};
};

int main() {
	char length;
	int type_sort, x, summ{};
	bool k = 0;
	bool higher_name = 0;
	int num_of_grades[5]{};
	char tmp[7]{};
	setlocale(LC_ALL, "Rus");
	Student list[100];
	for (int i = 0; i < 100; i++) {
			list[i].Id = GetRandomValue(1, 1000);	
			k = 0;
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
			if (list[i].Mark == 1) {
				cout << 'F' << endl;
				num_of_grades[0]++;
			}
			if (list[i].Mark == 2) {
				cout << 'D' << endl;
				num_of_grades[1]++;
			}
			if (list[i].Mark == 3) {
				cout << 'C' << endl;
				num_of_grades[2]++;
			}
			if (list[i].Mark == 4) {
				cout << 'B' << endl;
				num_of_grades[3]++;
			}
			if (list[i].Mark == 5) {
				cout << 'A' << endl;
				num_of_grades[4]++;
			}
	}
	cout << "Введите '1' для сортировки по ID, '2' - по оценкам, '3' - по именам: ";
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
		summ += list[i].Mark;
		cout << list[i].Name << ", ";
		if (list[i].Mark == 1) {
			cout << 'F' << endl;
		}
		if (list[i].Mark == 2) {
			cout << 'D' << endl;
		}
		if (list[i].Mark == 3) {
			cout << 'C' << endl;
		}
		if (list[i].Mark == 4) {
			cout << 'B' << endl;
		}
		if (list[i].Mark == 5) {
			cout << 'A' << endl;
		}
	}
	cout << "\nСредний балл: " << summ / 100.00 << endl;
	cout << "Количество оценок 'F': " << num_of_grades[0] << endl;
	cout << "Количество оценок 'D': " << num_of_grades[1] << endl;
	cout << "Количество оценок 'C': " << num_of_grades[2] << endl;
	cout << "Количество оценок 'B': " << num_of_grades[3] << endl;
	cout << "Количество оценок 'A': " << num_of_grades[4] << endl;
	summ = 0;
	char p = 0;
	while (1) {
		if (num_of_grades[p] + summ >= 25) {
			cout << "Чтобы стать лучше 25% студентов нужно получить оценку ";
			if (p == 1) {
				cout << 'F' << " или выше " << endl;
			}
			if (p == 2) {
				cout << 'D' << " или выше " << endl;
			}
			if (p == 3) {
				cout << 'C' << " или выше " << endl;
			}
			if (p == 4) {
				cout << 'B' << " или выше " << endl;
			}
			if (p == 0) {
				cout << 'A' << " или выше " << endl;
			}
			break;
		}
		else {
			summ += num_of_grades[p];
			p++;
		}
	}
	while (1) {
		if (num_of_grades[p] + summ >= 50) {
			cout << "Чтобы стать лучше 50% студентов нужно получить оценку ";
			if (p == 1) {
				cout << 'F' << " или выше " << endl;
			}
			if (p == 2) {
				cout << 'D' << " или выше " << endl;
			}
			if (p == 3) {
				cout << 'C' << " или выше " << endl;
			}
			if (p == 4) {
				cout << 'B' << " или выше " << endl;
			}
			if (p == 0) {
				cout << 'A' << " или выше " << endl;
			}
			break;
		}
		else {
			summ += num_of_grades[p];
			p++;
		}
	}
	while (1) {
		if (num_of_grades[p] + summ >= 75) {
			cout << "Чтобы стать лучше 75% студентов нужно получить оценку ";
			if (p == 1) {
				cout << 'F' << " или выше " << endl;
			}
			if (p == 2) {
				cout << 'D' << " или выше " << endl;
			}
			if (p == 3) {
				cout << 'C' << " или выше " << endl;
			}
			if (p == 4) {
				cout << 'B' << " или выше " << endl;
			}
			if (p == 0) {
				cout << 'A' << " или выше " << endl;
			}
			break;
		}
		else {
			summ += num_of_grades[p];
			p++;
		}
	}
}
