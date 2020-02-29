#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "введите 10 еслиISBN -10 иначе введите 13 ISBN-13  -  ";
	int vodim1;
	cin >> vodim1;
	if (vodim1 ==10)
	{
	unsigned long long  int chislo;
	int kod;
	int schetchik;
	schetchik = 0;
	cout << "vvedite 10 znachnoe chislo" << endl;
	cin >> chislo;

	kod = chislo % 10;
	chislo = (chislo - kod) / 10;

	for (int i = 2; i < 10; i++)
	{
		schetchik = (chislo % 10) * i + schetchik;
		chislo = (chislo - chislo % 10) / 10;
										}
	schetchik = schetchik % 11;
	schetchik = 11 - schetchik;
	if (kod == schetchik)
	{
		cout << "kod verniy";
	}
	else
	{
		cout << "kod neverniy";
	}
	}
	else
	{
#include <iostream>
#include<algorithm>
#include<math.h>
		
			unsigned long long  int chislo;
			int kod;
			int schetchik;
			schetchik = 0;
			cout << "vvedite 10 znachnoe chislo" << endl;
			cin >> chislo;

			kod = chislo % 10;
			chislo = (chislo - kod) / 10;

			for (int i = 0; i < 6; i++)
			{
				schetchik = (chislo % 10) * 3 + schetchik;
				chislo = (chislo - chislo % 10) / 10;



				schetchik = (chislo % 10) * 1 + schetchik;
				chislo = (chislo - chislo % 10) / 10;


			}
			schetchik = schetchik % 10;
			schetchik = 10 - schetchik;
			if (kod == schetchik)
			{
				cout << "kod verniy";
			}
			else
			{
				cout << "kod neverniy";
			}

		}
	}
