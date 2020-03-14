#include <iostream>
#include "Date.h"
#include <limits>
using namespace ext;
using namespace std;
int main()
{
	/*setlocale(LC_ALL, "RU");
	cout << "Hello World!\n";
	Date b;
	TimeDelta h;
	h.delta = 2;
	b.month = static_cast<Month>(8);
	b.day = 6;
	b.year = 2018;
	PrintSeasonAsString(getSeason(b));
	TimeDelta a;
	a = countJND(b);
	cout << a.delta << endl;
	Date ss = b + h;
	print(ss, DateFormat::MonthAsString);
	cout << endl;
	print(ss, DateFormat::MonthAsInt);
	cout << endl;
	print(countDistance(b, ss));
	if (ss > b) cout << "date ss is bigger than date b.";*/


	
	printf("Тип переменной\t\t|\tРазмер,\t|\t\t\tЗначение\t\t\t|    количество |\n\t\t\t|\tбайт\t|\t\tминимальное | максимальное\t\t|   значимых бит|\n");
	for (int i = 0; i < 97; i++) printf("-");
	printf("\nbool\t\t\t|\t%8d|\t\t%12d|\t\t\t%8d|\t%8d|\n",
		sizeof(bool), numeric_limits<bool>::min(), numeric_limits<bool>::max(), numeric_limits<bool>::digits);
	printf("unsigned short\t\t|\t%8u|\t\t%12u|\t\t\t%8u|\t%8u|\n",
		sizeof(unsigned short), numeric_limits<unsigned short>::min(), numeric_limits<unsigned short>::max(), numeric_limits<unsigned short>::digits);
	printf("short\t\t\t|\t%8d|\t\t%12d|\t\t\t%8d|\t%8d|\n",
		sizeof(short), numeric_limits<short>::min(), numeric_limits<short>::max(), numeric_limits<short>::digits);
	printf("unsigned int\t\t|\t%8u|\t\t%12u|\t\t%16u|\t%8u|\n",
		sizeof(unsigned int), numeric_limits<unsigned int>::min(), numeric_limits<unsigned int>::max(), numeric_limits<unsigned int>::digits);
	printf("int\t\t\t|\t%8d|\t\t%12d|\t\t%16d|\t%8d|\n",
		sizeof(int), numeric_limits<int>::min(), numeric_limits<int>::max(), numeric_limits<int>::digits);
	printf("unsigned long\t\t|\t%8u|\t\t%12u|\t\t%16u|\t%8d|\n",
		sizeof(unsigned long), numeric_limits<unsigned long>::min(), numeric_limits<unsigned long>::max(), numeric_limits<unsigned long>::digits);
	printf("long\t\t\t|\t%8d|\t\t%12d|\t\t%16d|\t%8d|\n",
		sizeof(long), numeric_limits<long>::min(), numeric_limits<long>::max(), numeric_limits<long>::digits);
	printf("unsigned long long\t|\t%8u|\t\t%12llu|\t    %20llu|%15u|\n",
		sizeof(unsigned long long), numeric_limits<unsigned long long>::min(), numeric_limits<unsigned long long>::max(), numeric_limits<unsigned long long>::digits);
	printf("long long\t\t|\t%8u|\t%19lld|\t     %16lld|%15u|\n",
		sizeof(long long), numeric_limits<long long>::min(), numeric_limits<long long>::max(), numeric_limits<long long>::digits);
	printf("char\t\t\t|\t%8d|\t\t%12d|\t\t\t%8d|\t%8d|\n",
		sizeof(char), numeric_limits<char>::min(), numeric_limits<char>::max(), numeric_limits<char>::digits);
	printf("float\t\t\t|\t%8u|\t\t%12e|\t\t%16e|%15d|\n",
		sizeof(float), numeric_limits<float>::min(), numeric_limits<float>::max(), numeric_limits<float>::digits);
	printf("double\t\t\t|\t%8u|\t%20e|\t\t%16e|%15d|\n",
		sizeof(double), numeric_limits<double>::min(), numeric_limits<double>::max(), numeric_limits<double>::digits);



	system("pause");
}