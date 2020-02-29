#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;
enum Grade
{
	F = 1,
	D = 2,
	C = 3,
	B = 4,
	A = 5,
};
struct Student
{
	int Id;
	Grade Mark;
	char Name[7];
};

int main() {
	Student student[100];
	for (int i = 0; i < 100; i++) {
		student[i].Id = GetRandomValue(1, 1000);
		student[i].Mark = static_cast<Grade>(GetRandomValue(1, 5));
		int length = GetRandomValue(3, 6);
		for (int i = 0; i < length; i++)
		{
			student[i].Name[i] = GetRandomValue('a', 'z');
		}
		student[i].Name[length] = '\0';
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 7; j++) {
			cout << student[i].Name[j];
		}
		cout << " ";
	}
	cout << "Enter 1, 2 or 3 to choose method: 1 - by Id, 2 - by Mark, 3 - by Name" << endl;
	int number;
	cin >> number;
	if (number == 1) {
		bool isSwap = false;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 99; j++) {
				if (student[j].Id > student[j + 1].Id) {
					int temp = student[j].Id;
					student[j].Id = student[j + 1].Id;
					student[j + 1].Id = temp;
					isSwap = true;
					Grade temp1 = student[j].Mark;
					student[j].Mark = student[j + 1].Mark;
					student[j + 1].Mark = temp1;
					char temp2[7];
					for (int i = 0; i < 7; i++)
					{
						temp2[i] = student[j].Name[i];
					}
					for (int i = 0; i < 7; i++)
					{
						student[j].Name[i] = student[j + 1].Name[i];
					}
					for (int i = 0; i < 7; i++)
					{
						student[j + 1].Name[i] = temp2[i];
					}
				}
			}
			if (!isSwap) {
				break;
			}
			isSwap = false;
		}
	}
	if (number == 2) {
		bool isSwap = false;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 99; j++) {
				if (student[j].Mark > student[j + 1].Mark) {
					Grade temp = student[j].Mark;
					student[j].Mark = student[j + 1].Mark;
					student[j + 1].Mark = temp;
					isSwap = true;
					int temp1 = student[j].Id;
					student[j].Id = student[j + 1].Id;
					student[j + 1].Id = temp1;
					char temp2[7];
					for (int i = 0; i < 7; i++)
					{
						temp2[i] = student[j].Name[i];
					}
					for (int i = 0; i < 7; i++)
					{
						student[j].Name[i] = student[j + 1].Name[i];
					}
					for (int i = 0; i < 7; i++)
					{
						student[j + 1].Name[i] = temp2[i];
					}
				}
			}
			if (!isSwap) {
				break;
			}
			isSwap = false;
		}
	}
	if (number == 3) {
		bool isSwap = false;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 99; j++) {
				if (student[j].Name[0] > student[j + 1].Name[0]) {
					char temp[7];
					for (int i = 0; i < 7; i++)
					{
						temp[i] = student[j].Name[i];
					}
					for (int i = 0; i < 7; i++)
					{
						student[j].Name[i] = student[j + 1].Name[i];
					}
					for (int i = 0; i < 7; i++)
					{
						student[j + 1].Name[i] = temp[i];
					}
					isSwap = true;
					int temp1 = student[j].Id;
					student[j].Id = student[j + 1].Id;
					student[j + 1].Id = temp1;
					Grade temp2 = student[j].Mark;
					student[j].Mark = student[j + 1].Mark;
					student[j + 1].Mark = temp2;
				}
			}
			if (!isSwap) {
				break;
			}
			isSwap = false;
		}
	}
}