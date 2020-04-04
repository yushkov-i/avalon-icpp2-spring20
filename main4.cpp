#include <iostream>
#include <stdio.h>
#include <limits>
#include <iomanip>
#include"Date.hpp"
#include"Extention.hpp"
using namespace std;
using namespace ext;









int main() {
	char s[] = " ";//space
	setlocale(0, "rus");
	printf("%4sТип переменной%6s|%4sРазмер,%3s|%15sЗначение%17s|Количество\n", s, s, s, s, s, s);
	printf("%24s|%5sбайт%5s|%4sМинимальное%4s|%2sМаксимальное%6s|значимых бит%4s|\n", s, s, s, s ,s ,s ,s ,s);
	printf("---------------------------------------------------------------------------------------------\n");
	printf("%-24s|%14d|%20d|%20d|%15d|\n", "bool", sizeof(bool), numeric_limits<bool>::min(), numeric_limits<bool>::max(), numeric_limits<bool>::digits);
	printf("%-24s|%14d|%20u|%20u|%15d|\n", "unsigned short", sizeof(unsigned short), numeric_limits<unsigned short>::min(), numeric_limits<unsigned short>::max(), numeric_limits<unsigned short>::digits);
	printf("%-24s|%14d|%20d|%20d|%15d|\n", "short", sizeof(short), numeric_limits<short>::min(), numeric_limits<short>::max(), numeric_limits<short>::digits + 1);
	printf("%-24s|%14d|%20u|%20u|%15d|\n", "unsigned int", sizeof(unsigned int), numeric_limits<unsigned int>::min(), numeric_limits<unsigned int>::max(), numeric_limits<unsigned int>::digits);
	printf("%-24s|%14d|%20d|%20d|%15d|\n", "int", sizeof(int), numeric_limits<int>::min(), numeric_limits<int>::max(), numeric_limits<int>::digits + 1);
	printf("%-24s|%14d|%20u|%20u|%15d|\n", "unsigned long", sizeof(unsigned long), numeric_limits<unsigned long>::min(), numeric_limits<unsigned long>::max(), numeric_limits<unsigned long>::digits);
	printf("%-24s|%14d|%20d|%20d|%15d|\n", "long", sizeof(long), numeric_limits<long>::min(), numeric_limits<long>::max(), numeric_limits<long>::digits + 1);
	printf("%-24s|%14d|%20llu|%20llu|%15d|\n", "unsigned long long", sizeof(unsigned long long), numeric_limits<unsigned long long>::min(), numeric_limits<unsigned long long>::max(), numeric_limits<unsigned long long>::digits);
	printf("%-24s|%14d|%20lld|%20lld|%15d|\n", "long long", sizeof(long long), numeric_limits<long long>::min(), numeric_limits<long long>::max(), numeric_limits<long long>::digits + 1);
	printf("%-24s|%14d|%20d|%20d|%15d|\n", "char", sizeof(char), numeric_limits<char>::min(), numeric_limits<char>::max(), numeric_limits<char>::digits + 1);
	printf("%-24s|%14d|%20e|%20e|%15d|\n", "float", sizeof(float), numeric_limits<float>::min(), numeric_limits<float>::max(), numeric_limits<float>::digits);//doesn't work, why 24 bytes
	printf("%-24s|%14d|%20e|%20e|%15e|\n", "double", sizeof(double), numeric_limits<double>::min(), numeric_limits<double>::max(), numeric_limits<double>::digits);
	cout << "******************************************************TASK № 2*********************************************************" << endl;
	cout << "Юлианская дата" << endl;
	Date date;
	int month = 0;
	cin >> date.day >> month >> date.year;
	date.month = static_cast<Month>(month);
	cout << countJND(date).delta << endl;
	cout << "разница в днях" << endl;
	Date from, to;
	cin >> from.day >> month >> from.year;
	from.month = static_cast<Month>(month);
	cin >> to.day >> month >> to.year;
	to.month = static_cast<Month>(month);
	cout << countDistance(from, to).delta << endl;
	cout << "вывод в консоль" << endl;
	print(date.month, DateFormat::MonthAsInt);
	cout << endl;
	print(date, DateFormat::MonthAsString);
	cout << endl;
	print3(countJND(date));
	cout << endl;
	cout << "Сезон" << endl;
	Month monthh = date.month;
	cout << static_cast<int>(getSeason(monthh)) << endl;
	cout << static_cast<int>(getSeason2(date)) << endl;

}