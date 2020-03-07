#include <iostream>
#include <limits>
#include<locale.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	char clear = { ' ' };
	//space    20                   11             61               12
	printf("Тип переменной%6c|%2cРазмер,%2c|%24cЗначение%29c|%2cКоличество \n", clear, clear, clear, clear, clear, clear);
	printf("%20c|%3cбайт%4c|%8cМинимальное%9c|%10cМаксимальное%10c|%cзначимых бит\n", clear, clear, clear, clear, clear, clear, clear, clear);
	printf("------------------------------------------------------------------------------------------------------------\n");
	printf("bool%16c|%11d|%28d|%32d|%12d|    \n", clear, sizeof(bool), numeric_limits<bool>::min(), numeric_limits<bool>::max());
	printf("unsigned short%6c|%11d|%28d|%32d|%12d| \n", clear, sizeof(unsigned short), numeric_limits<unsigned short>::min(), numeric_limits<unsigned short>::max());
	printf("short%15c|%11d|%28d|%32d|%12d| \n", clear, sizeof(short), numeric_limits<short>::min(), numeric_limits<short>::max());
	printf("unsigned int%8c|%11u|%28u|%32u|%12d|\n", clear, sizeof(unsigned int), numeric_limits<unsigned int>::min(), numeric_limits<unsigned int>::max());
	printf("int%17c|%11d|%28d|%32d|%12d| \n", clear, sizeof(int), numeric_limits<int>::min(), numeric_limits<int>::max());
	printf("unsigned long%7c|%11u|%28u|%32u|%12d| \n", clear, sizeof(unsigned long), numeric_limits<unsigned long>::min(), numeric_limits<unsigned long>::max());
	printf("long%16c|%11d|%28d|%32d|%12d| \n", clear, sizeof(long), numeric_limits<long>::min(), numeric_limits<long>::max());
	printf("unsigned long long%2c|%11u|%28u|%32u|%12d| \n", clear, sizeof(unsigned long long), numeric_limits<unsigned long long>::min(), numeric_limits<unsigned long long>::max());
	printf("long long%11c|%11d|%28d|%32d|%12d|  \n", clear, sizeof(long long), numeric_limits<long long>::min(), numeric_limits<long long>::max());
	printf("char%16c|%11d|%28d|%32d|%12d| \n", clear, sizeof(char), numeric_limits<char>::min(), numeric_limits<char>::max());
	printf("float%15c|%11d|%28f|%32f|%12d| \n", clear, sizeof(float), numeric_limits<float>::min(), numeric_limits<float>::max());
	printf("double%14c|%11d|%28f|%32f|%12d| \n", clear, sizeof(double), numeric_limits<double>::min(), numeric_limits<double>::max());
	cout << clear << " " << sizeof(unsigned int) << " " << numeric_limits<unsigned int>::min() << " " << numeric_limits<unsigned int>::max();
	/*#include <limits>
 

std::numeric_limits<long double>::max(); // максимальный
std::numeric_limits<long double>::min();  // минимальный*/



	system("pouse");
}