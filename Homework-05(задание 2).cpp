#include <iostream>
#include <cmath>
#include "D:\Home\C++\Extention.hpp"
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

const int Sto = 100;

TimeDelta countJND(Date date) {
	int A, Y, M, JDN = 0;
	A = (14 - static_cast<int>(date.month)) / 12;
	Y = date.year + 4800 - A;
	M = static_cast<int>(date.month) + 12 * A - 3;
	JDN = date.day + (153 * M + 2) / 5 + 365 * Y + Y / 4 - Y / 100 + Y / 400 - 32045;
	TimeDelta Primer;
	Primer.delta = JDN;
	return Primer;
};

int main() {
	setlocale(LC_ALL, "RUS");
	Date Dates[Sto];
	for (int i = 0; i < Sto; i++) {
		Dates[i].day = GetRandomValue(1, 28);
		Dates[i].month = static_cast<Month>(GetRandomValue(1, 12));
		Dates[i].year = GetRandomValue(1000, 3000);
	};
	Date Your;
	int month_int;
	cout << "¬ведите год: ";
	cin >> Your.year;
	cout << "¬ведите мес€ц: ";
	cin >> month_int;
	Your.month = static_cast<Month>(month_int);
	cout << "¬ведите день: ";
	cin >> Your.day;
	TimeDelta YourJND;
	YourJND = countJND(Your);
	Date Max = Dates[0], Min = Dates[0];
	int raznica_min = abs(YourJND.delta - countJND(Dates[0]).delta);
	int raznica_max = abs(YourJND.delta - countJND(Dates[0]).delta);
	for (int i = 0; i < Sto; i++) {
		if (raznica_max < abs(YourJND.delta - countJND(Dates[i]).delta)) {
			raznica_max = abs(YourJND.delta - countJND(Dates[i]).delta);
			Max = Dates[i];
		}
		if (raznica_min > abs(YourJND.delta - countJND(Dates[i]).delta)) {
			raznica_min = abs(YourJND.delta - countJND(Dates[i]).delta);
			Min = Dates[i];
		}
	}
	cout << "—ама€ удалЄнна€ - " << Max.day << "." << static_cast<int>(Max.month) << "." << Max.year << endl;
	cout << "—ама€ ближн€€ - " << Min.day << "." << static_cast<int>(Min.month) << "." << Min.year << endl;

}