#include <iostream>
#include "Header.hpp"

using namespace std;
using namespace ext;

int main() {
	setlocale(LC_ALL, "Rus");
	TimeDelta x, y;
	x.delta = 365;
	y.delta = 5;
	Date test{ 2017, Month::December, 1 };
	Date test1{ 2018, Month::December, 1 };
	Date dates[5]{ {2019, Month::December, 2}, { 2019, Month::December, 1 }, { 2017, Month::December, 1 }, { 2016, Month::December, 1 }, { 2015, Month::December, 1 } };
	test = test + x;
	x.delta += y.delta;
	sort(dates, 5);
	for (int i = 0; i < 5; i++) {
		cout << dates[i].day << '.' << static_cast<int>(dates[i].month) << '.' << dates[i].year << endl;
	}
}