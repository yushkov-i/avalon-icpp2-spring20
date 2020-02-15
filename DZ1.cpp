#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");

	int n, pt1, pt2;
	long long isbn, sum;
	cout << "Введите колчество ISBN-13 для проверки: ";
	cin >> n;

	
	for (int i = 0; i < n; i++)
	{
		cout << "Введите код под номером " << i + 1 << ": ";
		cin >> isbn;

		pt1 = isbn / 10000000;
		pt2 = isbn % 10000000;

		sum = pt1 / 100000 + (pt1 / 10000 % 10)*3 + pt1 / 1000 % 10 + (pt1 / 100 % 10)*3 + pt1 / 10 % 10 + (pt1 % 10)*3;
	    sum += pt2 / 1000000 + (pt2 / 100000 % 10)*3+ pt2 / 10000 % 10 + (pt2 / 1000 % 10)*3 + pt2 % 1000 / 100 + (pt2 % 100 / 10)*3;

		cout << "Данный ISBN-13 ";
		if (isbn % 10 == 10 - sum % 10)
			cout << "действителен";
		else
			cout << "недействителен";
		 
		cout << endl << endl;
	}

}


