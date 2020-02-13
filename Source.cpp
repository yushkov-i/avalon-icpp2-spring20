#include <iostream>
#include <cstdlib>

using namespace std;
int Perevod(char Num_P) {
	switch (Num_P) {
	case (48):
		return 0;
		break;
	case (49):
		return 1;
		break;
	case (50):
		return 2;
		break;
	case (51):
		return 3;
		break;
	case (52):
		return 4;
		break;
	case (53):
		return 5;
		break;
	case (54):
		return 6;
		break;
	case (55):
		return 7;
		break;
	case (56):
		return 8;
		break;
	case (57):
		return 9;
		break;
	//default:
	//	break;
	};
};


int* ISBN_13(char Number13[]) {
	int Summa, Num_Proizved, Count_Chetnosti;
	Summa = 0;
	Count_Chetnosti = 0;
	for (int i = 0; i < 12; i++) {
		Num_Proizved = Perevod(Number13[i]);
		if (Count_Chetnosti % 2 == 0) {
			Summa = Summa + Num_Proizved;
		}
		else {
			Summa = Summa + Num_Proizved * 3;
		};
		Count_Chetnosti++;
	};
	if (((Perevod(Number13[12]) != 0) && (10 - Summa % 10 == Perevod(Number13[12]))) || (10 - Summa % 10 == 10 && Perevod(Number13[12]) == 0)) {
		cout << "Номер указан верно!" << endl;
		system("pause");
		return 0;
	}
	else {
		cout << "Номер указан неверно!" << endl;
		system("pause");
		return 0;
	};

};

int* ISBN_10(char Number10[]) {
	int Summa, Num_Proizved;
	Summa = 0;
	for (int i = 0; i < 9; i++) {
		Num_Proizved = Perevod(Number10[i]);
		Summa = Summa + Num_Proizved * (10 - i);
	};
	if ((Summa % 11 == 0) && (Perevod(Number10[9]) == 0)) {
		cout << "Номер указан верно!" << endl;
		system("pause");
		return 0;
	}
	else if ((11 - Summa % 11 == 10) && (Number10[9] == 88 || Number10[9] == 120)) {
		cout << "Номер указан верно!" << endl;
		system("pause");
		return 0;
	}
	else if (11 - Summa % 11 == Perevod(Number10[9])) {
		cout << "Номер указан верно!" << endl;
		system("pause");
		return 0;
	}
	else {
		cout << "Номер указан неверно!" << endl;
		system("pause");
		return 0;
	};
};

int main() {
	setlocale(LC_ALL, "RUS");
	short Type;
	cout << "Введите 1, чтобы использовать ISBN-13." << endl;
	cout << "Введите 2, чтобы использовать ISBN-10." << endl;
	cin >> Type;
	if (Type == 1) {
		char Number[14] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\n' };
		cout << "Введите номер(13 символов): №";
		for (int i = 0; i < 13; i++) {
			cin >> Number[i];
			if (Number[i] < 48 || Number[i] > 57) {
				cout << "Ошибка ввода номера! Повторите попытку." << endl;
				system("pause");
				return 0;
			};
		};
		ISBN_13(Number);
	}
	else if (Type == 2) {
		char Number[11] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\n' };
		cout << "Введите номер(10 символов): №";
		for (int i = 0; i < 10; i++) {
			cin >> Number[i];
			if (((Number[i] < 48 || Number[i] > 57) && (Number[i] != 88 && Number[i] != 120)) || (i != 9 && (Number[i] == 88 || Number[i] == 120))) {
				cout << "Ошибка ввода номера! Повторите попытку." << endl;
				system("pause");
				return 0;
			};
		};
		ISBN_10(Number);
	}
	else {
		cout << "Ошибка ввода типа! Повторите попытку." << endl;
		system("pause");
		return 0;
	};
}
