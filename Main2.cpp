#include<iostream>
#include "Date.hpp"
using namespace std;
using namespace ext;
int main() {
	Date date;
	cout << "Enter day (as a number)\n";
	cin >> date.day;
	cout << "Enter Month (as a number)\n";
	cin >> date.month;
	cout << "Enter year (as a number)\n";
	cin >> date.year;
	cout << "Julian day (JDN) by Gregorian calendar date: " << countJND(date).delta << endl;
	
	Date DateFrom, DateTo;
	cout << "Enter day (DateFrom) as a number\n";
	cin >> DateFrom.day;
	cout << "Enter Month (DateFrom) as a number\n";
	cin >> DateFrom.month;
	cout << "Enter year (DateFrom) as a number\n";
	cin >> DateFrom.year;
	cout << "Enter day (DateTo) as a number\n";
	cin >> DateTo.day;
	cout << "Enter Month (DateTo) as a number\n";
	cin >> DateTo.month;
	cout << "Enter year (DateTo) as a number\n";
	cin >> DateTo.year;
	cout << "Distance between DateFrom and DateTo: " << countDistance(DateFrom, DateTo).delta;
	
}