#include "Date.hpp"
#include <iostream>

using namespace std;
using namespace ext;

int main()
{
	//Date date{ 12, static_cast<Month>(2), 1998 }; // ïëîõî
	Date date{ 1998, Month::February, 12 };

	print(date, DateFormat::MonthAsInt);	// 12.2.1998
	cout << endl;
	print(date, DateFormat::MonthAsString);	// 12 february 1998

	cout << endl;
	print(date.month, DateFormat::MonthAsInt); // 2
	cout << endl;
	print(date.month, DateFormat::MonthAsString); // february
}
