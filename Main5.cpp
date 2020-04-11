#include <iostream>
#include"Extention.hpp"
#include "Date.hpp"
#include <cmath>
using namespace std;
using namespace ext;
int main() {
	setlocale(0, "rus");
	Date dates[100];
	Date inputDate = {};
	int t = 0;
	for (int i = 0; i < 100; ++i) {
		dates[i].day = GetRandomValue(1, 28);
		dates[i].month = static_cast<Month>(GetRandomValue(1, 12));
		dates[i].year = GetRandomValue(1000, 3000);
		cout << dates[i].day << "." << static_cast<int>(dates[i].month) << "." << dates[i].year << endl;
	}
	while (inputDate.day > 28 || inputDate.day < 1) {
		cout << "1 <= Day <= 28. input day:";
		cin >> inputDate.day;
		cout << endl;
	}
	while (t > 12 || t < 1) {
		cout << "1 <= Month <= 12. input month:";
		cin >> t;
		inputDate.month = static_cast<Month>(t);
		cout << endl;
	}
	while (inputDate.year > 3000 || inputDate.year < 1000) {
		cout << "1000 <= Year <= 3000. input year:";
		cin >> inputDate.year;
		cout << endl;
	}
	Date close = dates[0], far = dates[0];
	TimeDelta inputJND = countJND(inputDate);
	int rangeMin = abs(countDistance(inputDate, dates[0]).delta);
	int rangeMax = abs(countDistance(inputDate, dates[0]).delta);
	for (int i = 0; i < 100; ++i) {
		if (abs(countDistance(inputDate, dates[i]).delta) > rangeMax) {
			rangeMax = abs(countDistance(inputDate, dates[i]).delta);
			far = dates[i];
		}
		if (abs(countDistance(inputDate, dates[i]).delta) < rangeMin) {
			rangeMin = abs(countDistance(inputDate, dates[i]).delta);
			close = dates[i];
		}
	}
	cout << "Closest date to entered date: " << close.day << "." << static_cast<int>(close.month) << "." << close.year << endl;
	cout << "Furthest date to entered date: " << far.day << "." << static_cast<int>(far.month) << "." << far.year << endl;
	system("pause");
}