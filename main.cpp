
#include <stdio.h>
#include <iostream>
#include "Date.hpp"
#include <limits>  
using namespace std;
using namespace ext;
int main() {
	setlocale(0, "rus");

		/*
			TimeDelta delta = { 10 };
			Month month = static_cast<Month>(7);
			Date data = { 2020,Month::January, 1 };
			Date data2 = { 2020,Month::February, 1 };
			print(data); //12.2.1998
			cout << endl;
			print(data, DateFormat::MonthAsString); //12 February 1998
			cout << endl;
			print(data.month, DateFormat::MonthAsString);//2
			cout << endl;
			cout << countJND(data).delta << endl;
			cout << countDistance(data, data2).delta << endl;
			cout << static_cast<int>(getSeason(data)) << endl;
			cout << static_cast<int>(getSeason(month)) << endl;
			print(data + delta);
			*/

		
	char a[] = "  ";
	printf("Тип переменной%-10s|%+4sРазмер,%3s|%15sЗначение%13s|%3sКоличесво\n",a, a,  a, a, a,a);
	printf("%-24s|%-5sбайт%-5s|%4sМинимальное%4s|%2sМаксимальное%2s|%sзначимых бит\n", a,a,a, a, a, a,a,a,a);
	printf("----------------------------------------------------------------------------------------------\n");
	char Bool[] = "bool";	
	printf("%-24s|%14d|%19d|%16d|%15d|\n", Bool, sizeof(bool), numeric_limits<bool>::min(), numeric_limits<bool>::max(), numeric_limits<bool>::digits);
	char us[] = "unsigned short";
	printf("%-24s|%14d|%19d|%16d|%15d|\n", us, sizeof(unsigned short), numeric_limits<unsigned short>::min(), numeric_limits<unsigned short>::max(), numeric_limits<unsigned short>::digits);
	char s[] = "short";
	printf("%-24s|%14d|%19d|%16d|%15d|\n", s, sizeof(short), numeric_limits<short>::min(), numeric_limits<short>::max(), numeric_limits<short>::digits);
	char ui[] = "unsigned int";
	printf("%-24s|%14d|%19d|%16d|%15d|\n", ui, sizeof(unsigned int), numeric_limits<unsigned int>::min(), numeric_limits<unsigned int>::max(), numeric_limits<unsigned int>::digits);
	char i[] = "int";
	printf("%-24s|%14d|%19d|%16d|%15d|\n", i, sizeof(int), numeric_limits<int>::min(), numeric_limits<int>::max(), numeric_limits<int>::digits);
	char ul[] = "unsigned long";
	printf("%-24s|%14d|%19d|%16d|%15d|\n", ul, sizeof(unsigned long), numeric_limits<unsigned long>::min(), numeric_limits<unsigned long>::max(), numeric_limits<unsigned long>::digits);
	char l[] = "long";
	printf("%-24s|%14d|%19d|%16d|%15d|\n", l, sizeof(long), numeric_limits<long>::min(), numeric_limits<long>::max(), numeric_limits<long>::digits);
	char ull[] = "unsigned long long";
	printf("%-24s|%14d|%19d|%16d|%15d|\n", ull, sizeof(unsigned long long), numeric_limits<unsigned long long>::min(), numeric_limits<unsigned long long>::max(), numeric_limits<unsigned long long>::digits);
	char ll[] = "long long";
	printf("%-24s|%14d|%19d|%16d|%15d|\n", ll, sizeof(long long), numeric_limits<long long>::min(), numeric_limits<long long>::max(), numeric_limits<long long>::digits);
	char c[] = "char";
	printf("%-24s|%14d|%19d|%16d|%15d|\n", c, sizeof(char), numeric_limits<char>::min(), numeric_limits<char>::max(), numeric_limits<char>::digits);
	char f[] = "float";
	printf("%-24s|%14d|%19d|%16d|%15d|\n", f, sizeof(float), numeric_limits<float>::min(), numeric_limits<float>::max(), numeric_limits<float>::digits);
	char d[] = "double";
	printf("%-24s|%14d|%19d|%16d|%15d|\n", d, sizeof(double), numeric_limits<double>::min(), numeric_limits<double>::max(), numeric_limits<double>::digits);
}