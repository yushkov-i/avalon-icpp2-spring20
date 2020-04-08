#include <ctime>
#include <algorithm>
#include <iostream>
#include<math.h>
#include <random>

using namespace std;
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
const int n = 100;
int main()
{

	srand(unsigned(time(0)));    //чтобы каждый раз разные

	string alph;  //Создаем алфавит русского языка
	for (char i = 'A'; i <= 'Z'; ++i) alph = alph + i;
	alph += 'H';
	random_shuffle(alph.begin(), alph.end());  //перемешиваем алфавит
	alph[16] = 0;  //Используем возможности Си строк, выбираем 16 первых символов
	alph = alph.c_str();


	//for (int i = 'a'; i < 'z'; i++)
	//	cout << char('a' + rand() % ('z' - 'a')) << " ";


	setlocale(LC_ALL, "Russian");
	Student Students[n];
	int schetId = 0;
	for (int i = 0; i < n; ++i) {
		schetId = i;
		Students[i].Id = schetId + 1;
		Students[i].Mark = static_cast<Grade>(rand() % 5 + 1);
		int temp;
		temp = rand() % 6 + 3;
		for (int j = 0; j < temp; ++j) {
			for (int t = 'a'; t < 'z'; t++)
			{
				/*char symbol = char('a' + rand() % ('z' - 'a'));*/
				for (char i = 'A'; i <= 'Z'; ++i) alph = alph + i;
				{
					alph += 'H';
					random_shuffle(alph.begin(), alph.end());  //перемешиваем алфавит
					alph[temp] = 0;
					alph = alph.c_str();
					char symbol = alph.c_str()[0];
					Students[i].Name[j] = symbol;// так
				}
			}
		}

	}







	cout << "1-Id 2-Mark ";
	int vibor;
	cin >> vibor;
	int perekladka;
	switch (vibor) {
	case 1:
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n - 1 - i; ++j) {
				if (Students[j].Id > Students[j + 1].Id) {
					perekladka = Students[j].Id;
					Students[j].Id = Students[j + 1].Id;
					Students[j + 1].Id = perekladka;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n - 1 - i; ++j) {
				if (Students[j].Mark > Students[j + 1].Mark) {
					perekladka = Students[j].Mark;
					Students[j].Mark = Students[j + 1].Mark;
					Students[j + 1].Mark = static_cast<Grade>(perekladka);
				}
			}
		}
		break;

	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 1 - i; ++j) {
			if (Students[j].Mark > Students[j + 1].Mark) {
				perekladka = Students[j].Mark;
				Students[j].Mark = Students[j + 1].Mark;
				Students[j + 1].Mark = static_cast<Grade>(perekladka);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		switch (vibor) {
		case 1:
			cout << Students[i].Id << " ";
			break;
		case 2:
			cout << Students[i].Mark << " ";
			break;
		case 3:
			cout << Students[i].Name << " ";
			break;
		}
	}
	cout << "" << endl;
	int kolvo1=0;
	int kolvo2 = 0;
	int kolvo3 = 0;
	int kolvo4 = 0;
	int kolvo5 = 0;

	for (int i = 0; i < n; ++i) {
		switch (static_cast<int>(Students[i].Mark)) {
		case 1:
			kolvo1 += 1;
			break;
		case 2:
			kolvo2 += 1;
			break;
		case 3:
			kolvo3 += 1;
			break;
		case 4:
			kolvo4 += 1;
			break;
		case 5:
			kolvo5 += 1;
		}
	}
		
		if (kolvo1 > kolvo2&&( kolvo1 > kolvo3&& kolvo1 > kolvo4&& kolvo1 > kolvo5))
		{
			cout << "moda :  1" << endl;
		}
		if (kolvo2 > kolvo1&&( kolvo2 > kolvo3&& kolvo2 > kolvo4&& kolvo2 > kolvo5))
		{
			cout << "moda :  2" << endl;
		}
		if (kolvo3 > kolvo1&&( kolvo3 > kolvo2&& kolvo3 > kolvo4&& kolvo3 > kolvo5))
		{
			cout << "moda :  3" << endl;
		}
		if (kolvo4 > kolvo1&&( kolvo4 > kolvo2&& kolvo4 > kolvo3&& kolvo4 > kolvo5))
		{
			cout << "moda :  4" << endl;
		}
		if (kolvo5 > kolvo1&& (kolvo5 > kolvo2&& kolvo5 > kolvo3&& kolvo5 > kolvo4))
		{
			cout << "moda :  5" << endl;
		}





		int luchshe;
		int podschet;
		cout << "в какой процент учеников вы хотите попасть " << endl;
		cin >> luchshe;
		switch (luchshe)
		{
		case 25:
			for (int o = 0;o < 25;o++)
			{
				
				podschet = Students[o].Mark;
				
				}
			switch (podschet)
			{
			case 1:
				cout << "получить 2" << endl;
				break;
			case 2:
				cout << "получить 3" << endl;
				break;
			case 3:
				cout << "получить 4" << endl;
				break;
			case 4:
				cout << "получить 5" << endl;
				break;
			case 5:
				cout << "все и так хорошо" << endl;
				break;
			}
			break;
		case 50:
			for (int o = 0;o < 50;o++)
			{
				
				podschet = Students[o].Mark;
				
				}
			switch (podschet)
			{
			case 1:
				cout << "получить 2" << endl;
				break;
			case 2:
				cout << "получить 3" << endl;
				break;
			case 3:
				cout << "получить 4" << endl;
				break;
			case 4:
				cout << "получить 5" << endl;
				break;
			case 5:
				cout << "все и так хорошо" << endl;
				break;
			}
			break;
			break;
		case 75:
			for (int o = 0;o < 75;o++)
			{
				
				podschet = Students[o].Mark;
				
			}
			switch (podschet)
			{
			case 1:
				cout << "получить 2" << endl;
				break;
			case 2:
				cout << "получить 3" << endl;
				break;
			case 3:
				cout << "получить 4" << endl;
				break;
			case 4:
				cout << "получить 5" << endl;
				break;
			case 5:
				cout << "все и так хорошо" << endl;
				break;
			}
			break;
		}


}