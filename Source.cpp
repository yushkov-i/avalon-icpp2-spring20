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
		int id;
		Grade Mark;
		char name[7];
	};
int main()
{
	Student student[100];
	int a;
	for (int m = 0; m < 100; ++m) {
		for (int k = 0; k < 100; ++k) {
			student[k].id = GetRandomValue(1, 1000);
			student[k].Mark = static_cast<Grade>(GetRandomValue(1, 5));
			int l = GetRandomValue(3, 6);

			for (int i = 0; i < l; ++i)
			{
				student[k].name[i] = GetRandomValue('a', 'z');
			}
			student[k].name[l] = '\0';
		}
	}
	cout << ("Выберете сортировку") << endl << ("1.id") << endl << ("1.Mark") << endl << ("3.Name");
	cin >> a;
	if(a==1)
	{
		int size=100;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (student[j].id > student[j + 1].id) {
					swap(student[j], student[j + 1]);
				}
			}
		}
		for (int i = 0; i < size; i++) {
			cout << student[i].id << " ";
		}
		cout << endl;
	}
	else if (a == 2)
	{
		int size = 100;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (student[j].Mark > student[j + 1].Mark) {
					swap(student[j], student[j + 1]);
				}
			}
		}
		for (int i = 0; i < size; i++) {
			cout << student[i].Mark << " ";
		}
		cout << endl;
	}
	else
	{
		int size = 100;
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (student[j].name[0] > student[j + 1].name[0]) {
					swap(student[j], student[j + 1]);
					}
				else if(student[j].name[1] > student[j + 1].name[1]){
					swap(student[j], student[j + 1]);
				}
				else if (student[j].name[2] > student[j + 1].name[2]) {
					swap(student[j], student[j + 1]);
				}
				else if (student[j].name[3] > student[j + 1].name[3]) {
					swap(student[j], student[j + 1]);
				}
				else if (student[j].name[4] > student[j + 1].name[4]) {
					swap(student[j], student[j + 1]);
				}
				else if (student[j].name[5] > student[j + 1].name[5]) {
					swap(student[j], student[j + 1]);
				}
				else if (student[j].name[6] > student[j + 1].name[6]) {
					swap(student[j], student[j + 1]);
				}
			}
		}
		for (int i = 0; i < size; i++) {
			cout << student[i].name << " ";
		}
		cout << endl;
	}
	int size = 100;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (student[j].Mark > student[j + 1].Mark) {
				swap(student[j], student[j + 1]);
			}
		}
	}
	cout << endl<<student[26].Mark << endl << student[51].Mark << endl << student[76].Mark;
}