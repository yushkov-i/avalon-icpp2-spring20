#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Выберете тип isbn, который вы хотите проверить (10 или 13): ";
	int ans;	
	cin >> ans;
	unsigned long long  int isbn;
	int sum = 0;
	cout << "isbn: ";
	cin >> isbn;
	int temp = isbn % 10;
	isbn /= 10;
	if (ans == 13)
	{
			
		
		for (int i = 1; i < 13; i++)
		{
			if (i % 2 != 0) {
				sum += isbn % 10 * 3;
			}
			else if (i % 2 == 0) {
				sum += isbn % 10 * 1;
			}
			isbn /= 10;
		}
		if (10 - (sum % 10) == temp) {
			cout << "valid";
		}
		else {
			cout << "invalid";
		}
	}
	else if (ans == 10)  //154875155X - valid, хотя должен быть invalid
	{
		for (int i = 2; i < 11; i++) {
			sum += (isbn % 10) * i;
			isbn /= 10;
		}
		if (11 - (sum % 11) == temp) {
			cout << "valid";
		}
		else {
			cout << "invalid";
		}
	}

}