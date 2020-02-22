#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	setlocale(0, "rus");
	int n ,isbn, sum,v;
	cout << "¬ведите количество номеров ISBN-13, которые выхотите проверить: ";
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cout << "¬ведите номер ISBN-13: " ;
		cin >> isbn;
		v= isbn % 10;
		sum = 0;
		for (int i = 1; i < 13; ++i) {
			isbn /= 10;
			if (i % 2 != 0) {
				sum += isbn % 10 * 3;
			}
			else {
				sum += isbn % 10 * 1;
			}		
		}
		if (v == 10 - sum % 10) {cout << "valid"<<endl; }
		else { cout << "invalid" << endl; }
		isbn = 0;
	}



}