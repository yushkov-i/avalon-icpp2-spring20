#include <iostream>
#include "D:\Home\C++\Extention.hpp"
#include <cstdlib>

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

struct Student {
	int Id;
	Grade Mark;
	char Name[7];
};

const int One_Hundred = 100;

int main() {
	setlocale(LC_ALL, "RUS");
	short Temp;
	Temp = 0;
	Student Students[One_Hundred];
	for (int i = 0; i < One_Hundred; i++) {
		Students[i].Id = GetRandomValue(1, 1000);
		Students[i].Mark = static_cast<Grade>(GetRandomValue(1, 5));
		Temp = GetRandomValue(3, 6);
		for (int j = 0; j < Temp; j++) {
			Students[i].Name[j] = GetRandomValue('a', 'z');
		}
		if (Temp != 6) {
			for (int j = Temp; j < (Temp + 6 - Temp); j++) {
				Students[i].Name[j] = '\0';
			}
		}
		Students[i].Name[Temp] = '\0';
		Temp = 0;
	};

	for (int i = 0; i < One_Hundred; i++) {
		for (int j = 0; j < One_Hundred - 1 - i; j++) {
			if (static_cast<int>(Students[j].Mark) > static_cast<int>(Students[j + 1].Mark)) {
				Grade Swap = Students[j].Mark;
				Students[j].Mark = Students[j + 1].Mark;
				Students[j + 1].Mark = Swap;

			}
		}
	}
	int Mass_Count[5] = {};
	Grade Сurrent_Mark = Students[0].Mark;
	for (int i = 0; i < One_Hundred; i++) {
		if (Сurrent_Mark == Students[i].Mark) {
			Mass_Count[static_cast<int>(Сurrent_Mark) - 1]++;
		}
		else {
			Сurrent_Mark = static_cast<Grade>(static_cast<int>(Сurrent_Mark + 1));
			Mass_Count[static_cast<int>(Сurrent_Mark) - 1]++;
		}
	}
	int Summa = 0;
	// на 25%
	if (Mass_Count[4] > 75) {
		cout << "Задача не имеет смысла.(25%)" << endl;
	}
	else {
		for (int i = 0; i < 5; i++) {
			Summa = Summa + Mass_Count[i];
			if (Summa >= 25) {
				cout << "Вам нужно получить оценку: " << static_cast<Grade>(i + 2) << ", чтобы быть лучше 25%." << endl;
				break;
			}
		}
	}
	Summa = 0;
	// на 50%
	if (Mass_Count[4] > 50) {
		cout << "Задача не имеет смысла.(50%)" << endl;
	}
	else {
		for (int i = 0; i < 5; i++) {
			Summa = Summa + Mass_Count[i];
			if (Summa >= 50) {
				cout << "Вам нужно получить оценку: " << static_cast<Grade>(i + 2) << ", чтобы быть лучше 50%." << endl;
				break;
			}
		}
	}
	Summa = 0;
	// на 75%
	if (Mass_Count[4] > 25) {
		cout << "Задача не имеет смысла.(75%)" << endl;
	}
	else {
		for (int i = 0; i < 5; i++) {
			Summa = Summa + Mass_Count[i];
			if (Summa >= 75) {
				cout << "Вам нужно получить оценку: " << static_cast<Grade>(i + 2) << ", чтобы быть лучше 75%." << endl;
				break;
			}
		}
	}
	cout << "Так!" << endl;
	system("pause");
	return 0;
}