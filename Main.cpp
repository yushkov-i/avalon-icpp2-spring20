#include <iostream>
#include <cmath>
#include "Extention.hpp"
#include "Date.hpp"
using namespace std;
using namespace ext;
int main() {
	Date dates[100];
	Date EnteredDate = {0, 0, 0};
	cout << "Generated dates:" << endl;
	for (int i = 0; i < 100; ++i) {
		dates[i].day = GetRandomValue(1, 28);
		dates[i].month = GetRandomValue(1, 12);
		dates[i].year = GetRandomValue(1000, 3000);
		cout << dates[i].day << "." << dates[i].month << "." << dates[i].year << endl;
	}
	cout << endl;
	cout << "Enter day (from 1 to 28): ";
	cin >> EnteredDate.day;
	cout << "Enter month (from 1 to 12): ";
	cin >> EnteredDate.month;
	cout << "Enter year (from 1000 to 3000): ";
	cin >> EnteredDate.year;
	Date closest, MostFar;
	int MinDistance = abs(countDistance(EnteredDate, dates[0]).delta);
	int MaxDistance = abs(countDistance(EnteredDate, dates[0]).delta);
	for (int i = 0; i < 100; ++i) {
		if (abs(countDistance(EnteredDate, dates[i]).delta) > MaxDistance) {
			MaxDistance = abs(countDistance(EnteredDate, dates[i]).delta);
			MostFar = dates[i];
		}
		if (abs(countDistance(EnteredDate, dates[i]).delta) < MinDistance) {
			MinDistance = abs(countDistance(EnteredDate, dates[i]).delta);
			closest = dates[i];
		}
	}
	cout << "Closest date to entered date: " << closest.day << "." << closest.month << "." << closest.year << endl;
	cout << "Most far date to entered date: " << MostFar.day << "." << MostFar.month << "." << MostFar.year << endl;
	system("pause");
}
