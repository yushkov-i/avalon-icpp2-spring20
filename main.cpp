#include <iostream>
#include "Date.hpp"

using namespace std;
using namespace ext;

int main() {
	setlocale(LC_ALL, "Rus");
	TimeDelta x, y;
	x.delta = 365;
	y.delta = 5;
	Date test{2017, Month::December, 1};
	Date test1{2018, Month::December, 1};
	test = test + x;
	x.delta += y.delta;
	print(x);
	print(test, DateFormat::MonthAsInt);
}