#include <iostream>
#include<algorithm>
#include<math.h>
#include <random>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int proverkanaprogyl;
	int massiveocenki[10][12];
	int sort;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			proverkanaprogyl = rand() % 5 + 1;
			if (proverkanaprogyl == 1)
			{
				massiveocenki[i][j] = -1;
			}
			else
			{
				massiveocenki[i][j] = 1000 + rand() % 100000;
			}
		}
	}

	for (int q = 0; q < 10; q++)
	{
		for (int u = 0; u < 12; u++)
		{
			for (int m = 0; m < 11; m++)
			{

				if (massiveocenki[q][m] > massiveocenki[q][m + 1])
				{
					sort = massiveocenki[q][m];
					massiveocenki[q][m] = massiveocenki[q][m + 1];
					massiveocenki[q][m + 1] = sort;
				}

			}
		}
	}
	int stroka = 0;
	int itogovayamediana = 0;
	for (int bang = 0; bang < 10; bang++)
			{
		long schetchik = 0;
		int promezhytok;
		int schetchikedinic = 0;
		long mediana;
		long proverka;
		//проверка на -1 и узнаем сколько чисел
		for (int u = 0; u < 12; u++)
		{
			if ((massiveocenki[bang][u]) > 0)
			{
				schetchik += 1;
			}
			if ((massiveocenki[bang][u]) < 0)
			{
				schetchikedinic += 1;
			}
		}

		proverka = schetchik / 2;
		if (schetchik % 2 == 0)
		{
			mediana = (massiveocenki[bang][proverka + schetchikedinic - 1] + massiveocenki[bang][proverka + schetchikedinic]) / 2;

		}
		else
		{
			mediana = (massiveocenki[bang][proverka + schetchikedinic]);

		}

		if (itogovayamediana < mediana)
		{
			itogovayamediana = mediana;
			stroka = bang;
		}
	}
	   	for (int n = 0; n < 10; n++)
	{
		for (int h = 0; h < 12; h++)
		{
			cout << massiveocenki[n][h] << "\t";
		}
		cout << "\n\n\n\n";
	}
	cout << "строка с наибольшей медианой 1-10 >>  " << stroka + 1 << endl;
	cout << "наибольшая медиана >> " << itogovayamediana << endl;
}
