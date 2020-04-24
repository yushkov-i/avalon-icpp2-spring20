#include <iostream>
#include "Header.hpp"

using namespace std;
using namespace ext;

int main() {
	setlocale(LC_ALL, "Rus");
	int a, b;
	a = 8;
	b = 4;
	char* ptr = new char[a] {'h', 'e', 'l', 'l', 'o', 'l', 'l', '\0'};
	char* n = new char[b] {'m', 'e', 'o', '\0'};
	char* c = concatenate(ptr, n);
	char* d = substring(ptr, 2, 3);
	char* firs = new char[3]{ 'l', 'l' };
	char* sec = new char[4]{ 'b', 'b', 'a', '\0' };
	cout << c << endl << d;
	//cout << replaceString(ptr, firs, sec) << endl;
	delete[] ptr;
	delete[] n;
	delete[] d;
	ptr = 0;
	n = 0;
}