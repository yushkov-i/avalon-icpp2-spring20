#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(0, "rus");
	int ISBNnumber, sum, div, ctrl, n, size = 2;
	sum = 0;
	cin >> n;
	cin >> ISBNnumber;
	long long int* number = new long long int[n];
	long long int* savenumber = new long long int[n];
	if (ISBNnumber == 13) {
		for (int j = 0; j < n; ++j) {
			cout << "Введите номер:";
			cin >> number[j];
			savenumber[j] = number[j];
			for (int i = 0; i < ISBNnumber - 1; ++i) {
				if (i % 2 != 0) {
					sum += (number[j] % 10) * 1;
				}
				else if (i % 2 == 0) {
					sum += (number[j] % 10) * 3;
				}
				number[j] = number[j] / 10;
			}
			div = sum % 10;
			ctrl = 10 - div;
			if ((sum + ctrl) % 10 == 0) {
				cout << j + 1 << "-й номер " << savenumber[j] << " действителен" << endl;
			}
			else {
				cout << j + 1 << "-й номер " << savenumber[j] << " недействителен" << endl;
			}
		}
	}
	else if (ISBNnumber == 10) {
		for (int j = 0; j < n - 1; ++j) {
			cout << "Введите номер:";
			cin >> number[j];
			savenumber[j] = number[j];
			for (int i = 0; i < ISBNnumber - 1; ++i) {
				sum += (number[j] % 10) * size;
				number[j] = number[j] / 10;
				size += 1;
			}
			div = sum % 11;
			ctrl = 11 - div;
			if ((sum + ctrl) % 11 == 0) {
				cout << j + 1 << "-й номер " << savenumber[j] << " действителен" << endl;
			}
			else {
				cout << j + 1 << "-й номер " << savenumber[j] << " недействителен" << endl;
			}
		}
	}
}