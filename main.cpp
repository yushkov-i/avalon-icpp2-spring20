// ConsoleApplication20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 
#include <string> 
#include<algorithm>
#include<math.h>
#include <random>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	string str;
	int j = 0;
	cout << "Введите дату" << endl;
	getline(cin, str);
	if (str[2] == '.' && str[5] == '.')
	{
		j = 1;
	}
	if (str[1] == '.' && str[4] == '.')
	{
		j = 2;
	}
	if (str[2] == '.' && str[4] == '.')
	{
		j = 3;
	}
	if (str[1] == '.' && str[3] == '.')
	{
		j = 4;
	}
	for (int i = 0; i < str.length(); i++)
	{

		if (str[i] == '.')
		{

			str.erase(i, 1);
			i--;
		}
	}
	int value = atoi(str.c_str());

	int dd = 0;
	int mes = 0;
	int god = 0
		;
	if (j == 1)
	{
		// 12 34 5678
		god = value % 10000; //5678
		mes = (value - god) / 10000 % 100; //12 34 5678 - 5678 > 12 34 > 34
		dd = (value - value % 1000000) / 1000000; // 12 34 5678 - 34 5678 / 1000000
	}
	if (j == 2)
	{
		god = value % 10000; //1 23 4567 - 4567
		mes = (value - god) / 10000 % 100; // 1 23 4567 - 4567 - 1 23 0000 - 23
		dd = (value - value % 1000000) / 1000000; // 1 23 4567 - 1
	}
	if (j == 3)
	{
		god = value % 10000; //12 3 4567 - 4567
		mes = (value - god) / 10000 % 10; // 12 3 4567 - 4567 - 12 3 0000 - 23
		dd = (value - value % 100000) / 100000; // 12 3 4567 - 12 3 4567
	}
	if (j == 4)
	{
		god = value % 10000; //1 3 4567 - 4567
		mes = (value - god) / 10000 % 10; // 1 3 4567 - 4567 - 1 3 - 23
		dd = (value - value % 100000) / 100000; // 1 3 4567 
	}

	int schetchikdney1;

	schetchikdney1 = dd + mes * 28 + god * 365;


	string str2;
	int q = 0;
	cout << "Введите дату" << endl;
	getline(cin, str2);
	if (str2[2] == '.' && str2[5] == '.')
	{
		q = 1;
	}
	if (str2[1] == '.' && str2[4] == '.')
	{
		q = 2;
	}
	if (str2[2] == '.' && str2[4] == '.')
	{
		q = 3;
	}
	if (str2[1] == '.' && str2[3] == '.')
	{
		q = 4;
	}
	for (int q = 0; q < str2.length(); q++)
	{

		if (str2[q] == '.')
		{

			str2.erase(q, 1);
			q--;
		}
	}
	int value2 = atoi(str2.c_str());
	int a2, y2, m2;
	int dd2 = 0;
	int mes2 = 0;
	int god2 = 0;
	if (q == 1)
	{
		// 12 34 5678
		god2 = value2 % 10000; //5678
		mes2 = (value2 - god2) / 10000 % 100; //12 34 5678 - 5678 > 12 34 > 34
		dd2 = (value2 - value2 % 1000000) / 1000000; // 12 34 5678 - 34 5678 / 1000000
	}
	if (q == 2)
	{
		god2 = value2 % 10000; //1 23 4567 - 4567
		mes2 = (value2 - god2) / 10000 % 100; // 1 23 4567 - 4567 - 1 23 0000 - 23
		dd2 = (value2 - value2 % 1000000) / 1000000; // 1 23 4567 - 1
	}
	if (q == 3)
	{
		god2 = value2 % 10000; //12 3 4567 - 4567
		mes2 = (value2 - god2) / 10000 % 10; // 12 3 4567 - 4567 - 12 3 0000 - 23
		dd2 = (value2 - value2 % 100000) / 100000; // 12 3 4567 - 12 3 4567
	}
	if (q == 4)
	{
		god2 = value2 % 10000; //1 3 4567 - 4567
		mes2 = (value2 - god2) / 10000 % 10; // 1 3 4567 - 4567 - 1 3 - 23
		dd2 = (value2 - value2 % 100000) / 100000; // 1 3 4567 
	}
	int schetchikdney2;
	schetchikdney2 = dd2 + mes2 * 28 + god2 * 365;
	cout << schetchikdney1 << endl;
	cout << schetchikdney2 << endl;
	if (schetchikdney1 == schetchikdney2)
	{
		cout << "разница - 0 дней" << endl;
	}
	if (schetchikdney1 > schetchikdney2)
	{
		schetchikdney1 = schetchikdney1 - schetchikdney2;
		cout << "разница - " << schetchikdney1 << endl;
	}
	else
	{
		schetchikdney2 = schetchikdney2 - schetchikdney1;
		cout << "разница - " << schetchikdney2 << endl;
	}

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
