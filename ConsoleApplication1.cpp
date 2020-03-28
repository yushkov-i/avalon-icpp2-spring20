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
	printf("Тип переменной    | Размер, |          Значение            | Количество ");cout <<endl;
	printf("Тип переменной    | Байт    | Минимальное  |  Максимальное | значимых бит");cout<<endl;
	printf( boolalpha );
	printf("bool              |    ",sizeof(bool),"    |       ",numeric_limits<bool>::min(),"  |           ",numeric_limits<bool>::max(),"| ",numeric_limits<bool>::digits;cout <<endl;
	printf("unsigned short    |    ",sizeof(unsigned short),"    |       ",numeric_limits<unsigned short>::min(),"  |           ",numeric_limits<unsigned short>::max(),"| ",numeric_limits<unsigned short>::digits;cout <<endl;
	printf("short             |    ",sizeof(short),"    |       ",numeric_limits<short>::min(),"  |           ",numeric_limits<short>::max(),"| ",numeric_limits<short>::digits;cout <<endl;
	printf("unsigned int      |    ",sizeof(unsigned int),"    |       ",numeric_limits<unsigned int>::min(),"  |           ",numeric_limits<unsigned int>::max(),"| ",numeric_limits<unsigned int>::digits;cout <<endl;
    printf("int               |    ",sizeof(int),"    |       ",numeric_limits<int>::min(),"  |           ",numeric_limits<int>::max(),"| ",numeric_limits<int>::digits;cout <<endl;
	printf("unsigned long     |    ",sizeof(unsigned long),"    |       ",numeric_limits<unsigned long>::min(),"  |           ",numeric_limits<unsigned long>::max(),"| ",numeric_limits<unsigned long>::digits;cout <<endl;
    printf("long              |    ",sizeof(long),"    |       ",numeric_limits<long>::min(),"  |           ",numeric_limits<long>::max(),"| ",numeric_limits<long>::digits;cout <<endl;
	printf("unsigned long long|    ",sizeof(unsigned long long),"    |       ",numeric_limits<unsigned long long>::min(),"  |           ",numeric_limits<unsigned long long>::max(),"| ",numeric_limits<unsigned long long>::digits;cout <<endl;
	printf("long long         |    ",sizeof(long long),"    |       ",numeric_limits<long long>::min(),"  |           ",numeric_limits<long long>::max(),"| ",numeric_limits<long long>::digits;cout <<endl;
	printf("char              |    ",sizeof(char),"    |       ",numeric_limits<char>::min(),"  |           ",numeric_limits<char>::max(),"| ",numeric_limits<char>::digits;cout <<endl;
	printf("float             |    ",sizeof(float),"    |       ",numeric_limits<float>::min(),"  |           ",numeric_limits<float>::max(),"| ",numeric_limits<float>::digits;cout <<endl;
	printf("double            |    ",sizeof(double),"    |       ",numeric_limits<double>::min(),"  |           ",numeric_limits<double>::max(),"| ",numeric_limits<double>::digits;cout <<endl;
	*/
	system("pause");
	return 0;
}