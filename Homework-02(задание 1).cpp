#include <iostream>
#include "D:\Home\C++\Extention.hpp"
#include <cstdlib>

using namespace std;
using namespace ext;

enum Grade
{
	F = 1,   // ������
	D = 2,  // �������������������
	C = 3,  // �����������������
	B = 4,  // ������
	A = 5,  // �������      
};

struct Student {
	int Id;
	Grade Mark;
	char Name[7];
};
const int One_Hundred = 100;
int main() {
	setlocale(LC_ALL, "RUS");
	short Type;
	cout << "�������� ����������: \n �� id - ������� 1; \n �� Mark - ������� 2; \n �� Name - ������� 3;" << endl;
	cin >> Type;
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

	if (Type == 1) {
		for (int i = 0; i < One_Hundred; i++) {
			for (int j = 0; j < One_Hundred - 1 - i; j++) {
				if (Students[j].Id > Students[j + 1].Id) {
					int Swap = Students[j].Id;
					Students[j].Id = Students[j + 1].Id;
					Students[j + 1].Id = Swap;
				}
			}
		}
	}
	else if (Type == 2) {

		for (int i = 0; i < One_Hundred; i++) {
			for (int j = 0; j < One_Hundred - 1 - i; j++) {
				if (static_cast<int>(Students[j].Mark) > static_cast<int>(Students[j + 1].Mark)) {
					Grade Swap = Students[j].Mark;
					Students[j].Mark = Students[j + 1].Mark;
					Students[j + 1].Mark = Swap;

				}
			}
		}

	}
	else if (Type == 3) {

		for (int i = 0; i < One_Hundred; i++) {
			for (int j = 0; j < One_Hundred - 1 - i; j++) {
				for (int k = 0; k < 7; k++) {

					if (Students[j].Name[k] > Students[j + 1].Name[k]) {
						char Swap[7];
						for (int l = 0; l < 7; l++) {
							Swap[l] = Students[j].Name[l];
						};
						for (int l = 0; l < 7; l++) {
							Students[j].Name[l] = Students[j + 1].Name[l];
							Students[j + 1].Name[l] = Swap[l];
						}
						break;
					}
					else if (Students[j].Name[k] < Students[j + 1].Name[k]) {
						break;
					}

				}
			}
		}

	}
	else {
		cout << "������ ������������ ���� ����! ��������� �������!";
		system("pause");
		return 0;
	};
	cout << "���!" << endl;
	system("pause");
	return 0;
}
