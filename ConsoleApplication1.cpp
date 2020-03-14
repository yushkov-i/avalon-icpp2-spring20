#include <iostream>
#include <limits>
#include <conio.h>
#include"extention.hpp"
using namespace ext;
using namespace std;

int main()
{
	//1.
	int a[10][12][2],p=0,q[10],j=0;
	for (int k; k < 10; ++k) {
		for (int i = 0; i < 12; ++i) {
			a[k][i][0] = getrandomvalue(1000, 100000);
			a[k][i][1] = getrandomvalue(-1, 0);
		}
		for (int i = 0; i < 12; ++i) {
			if (a[k][i][1] == 0) {
				++p;
			}
		}
		if (p % 2 == 0) {
			p = p / 2 - 1;
			q[k] = (a[k][p][0]+a[k][p+1][0])/2;
		}
		else {
			p = (p - 1) / 2; 
			q[k] = a[k][p][0];
	}
	}
	for (int i = 0; i < 10; ++i) {
		if (q[i] > j)j = q[i];
	}
	cout << j;
	
	/*
	2.
	setlocale(0, "");
	std::cout << "Тип переменной    " << "| " << "Размер, " << "|          " << "Значение            " << "| " << "Количество " <<endl;
	std::cout << "Тип переменной    " << "| " << "Байт    " << "| " << "Минимальное  " << "|  " << "Максимальное " << "| " <<"значимых бит"<<endl;
	std::cout << std::boolalpha;
	std::cout << "bool              " << "|    " << sizeof(bool) << "    |       " << std::numeric_limits<bool>::min()   << "  |           " << std::numeric_limits<bool>::max()  << "| "<< std::numeric_limits<bool>::digits <<endl;
	std::cout << "unsigned short    " << "|    " << sizeof(unsigned short) << "    |       " << std::numeric_limits<unsigned short>::min() << "  |              " << std::numeric_limits<unsigned short>::max() << "| " << std::numeric_limits<unsigned short>::digits << endl;
	std::cout << "short             " << "|    " << sizeof(short) << "    |      " << std::numeric_limits<short>::min() << "  |          " << std::numeric_limits<short>::max() << "| " << std::numeric_limits<short>::digits << endl;
	std::cout << "unsigned int      " << "|    " << sizeof(unsigned int) << "    |       " << std::numeric_limits<unsigned int>::min() << "  |         " << std::numeric_limits<unsigned int>::max() << "| " << std::numeric_limits<unsigned int>::digits << endl;
	std::cout << "int               " << "|    " << sizeof(int) << "    | " << std::numeric_limits<int>::min() << " |      " << std::numeric_limits<int>::max() << "| " << std::numeric_limits<int>::digits << endl;
	std::cout << "unsigned long     " << "|    " << sizeof(unsigned long) << "    |       " << std::numeric_limits<unsigned long>::min() << "  |         " << std::numeric_limits<unsigned long>::max() << "| " << std::numeric_limits<unsigned long>::digits << endl;
	std::cout << "long              " << "|    " << sizeof(long) << "    |  " << std::numeric_limits<long>::min() << "  |    " << std::numeric_limits<long>::max() << "| " << std::numeric_limits<long>::digits << endl;
	std::cout << "unsigned long long" << "|    " << sizeof(unsigned long long) << "    | " << std::numeric_limits<unsigned long long>::min() << "  |     " << std::numeric_limits<unsigned long long>::max() << "| " << std::numeric_limits<unsigned long long>::digits << endl;
	std::cout << "long long         " << "|    " << sizeof(long long) << "|" << std::numeric_limits<long long>::min() << "|" << std::numeric_limits<long long>::max() << "|" << std::numeric_limits<long long>::digits << endl;
	std::cout << "char              " << "|    " << sizeof(char) << "    |       " << std::numeric_limits<char>::min() << "  |                  " << std::numeric_limits<char>::max() << "| " << std::numeric_limits<char>::digits << endl;
	std::cout << "float             " << "|    " << sizeof(float) << "    | " << std::numeric_limits<float>::min() << "  | " << std::numeric_limits<float>::max() << "   | " << std::numeric_limits<float>::digits << endl;
	std::cout << "double            " << "|    " << sizeof(double) << "    | " << std::numeric_limits<double>::min() << "  | " << std::numeric_limits<double>::max() << " | " << std::numeric_limits<double>::digits << endl;
	*/
	system("pause");
	return 0;
}