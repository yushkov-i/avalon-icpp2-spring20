#include <iostream>
#include <cmath>
#include "Extention.hpp"
using namespace std;
using namespace ext;

enum class Month
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	Novemver,
	December
};

struct Date
{
	int year;
	Month month;
	int day;
};

struct TimeDelta
{
	int delta;
};

TimeDelta countJND(Date date) {
	TimeDelta res;
	int a = (14 - static_cast<int>(date.month)) / 12;
	int y = date.year + 4800 - a;
	int m = static_cast<int>(date.month) + 12 * a - 3;
	res.delta = (date.day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045);
	return res;
}

int main() {
	Date Dates[100];
	for (int i = 0; i < 100; i++) {
		Dates[i].day = GetRandomValue(1, 28);
		Dates[i].month = static_cast<Month>(GetRandomValue(1, 12));
		Dates[i].year = GetRandomValue(1000, 3000);
	};
	Date Your;
	int month_int;
	cin >> Your.year;
	cin >> month_int;
	Your.month = static_cast<Month>(month_int);
	cin >> Your.day;
	TimeDelta YourJND;
	YourJND = countJND(Your);
	Date Max = Dates[0], Min = Dates[0];
	int r_min = abs(YourJND.delta - countJND(Dates[0]).delta);
	int r_max = abs(YourJND.delta - countJND(Dates[0]).delta);
	for (int i = 0; i < 100; i++) {
		if (r_max < abs(YourJND.delta - countJND(Dates[i]).delta)) {
			r_max = abs(YourJND.delta - countJND(Dates[i]).delta);
			Max = Dates[i];
		}
		if (r_min > abs(YourJND.delta - countJND(Dates[i]).delta)) {
			r_min = abs(YourJND.delta - countJND(Dates[i]).delta);
			Min = Dates[i];
		}
	}
	cout << Max.day << "." << static_cast<int>(Max.month) << "." << Max.year << endl;
	cout << Min.day << "." << static_cast<int>(Min.month) << "." << Min.year << endl;

}