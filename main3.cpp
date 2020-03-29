#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;
int main()
{
	int agent[10][12] = { 0 };
	int CountOfMonths[10] = { 0 };
	int rndStart = GetRandomValue(0, 11); // when agent went on work
	int rndEnd = GetRandomValue(rndStart, 11); // when agent get fired or went to vacation
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 12; ++j) {
			if (j >= rndStart && j <= rndEnd) {
				int absence = GetRandomValue(0, 1); // progyl
				if (absence == 0) {
					agent[i][j] = GetRandomValue(1000, 100000);
				}
				else {
					agent[i][j] = -1;
				}
			}
			else {
				agent[i][j] = -1;
			}
			if (agent[i][j] != -1) {
				CountOfMonths[i] ++;
			}
			cout << agent[i][j] << " ";
		}
		cout << endl;
	}

	int mediana[10] = { 0 };

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 12; ++j) {
			if (CountOfMonths[i] % 2 != 0) {
				mediana[i] = (CountOfMonths[i] - 1) / 2;// there we find number of the mediana
			}
			else if (CountOfMonths[i] % 2 == 0){
				mediana[i] = CountOfMonths[i] / 2;// also number of mediana, but then we will calculate mediana = this (number + (number - 1)) / 2
			}
		}
	}

	int check = 0;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 12; ++j) {

			if (agent[i][j] != -1) {
				if (check == mediana[i]) {
					if (CountOfMonths[i] % 2 != 0) {
						mediana[i] = agent[i][j]; // calculating mediana of 'i' agent
					}
					else if (CountOfMonths[i] % 2 == 0) {
						int k = 1;
						while (agent[i][j - k] == -1) {
							k++;
						} // there we find that month, where agent worked
						mediana[i] = (agent[i][j] + agent[i][j - k]) / 2; // calculate mediana
					}
				}
				check++;
			}

		}
		check = 0;
	}

	for (int i = 0; i < 10; ++i) {
		cout << mediana[i] << " ";
	}
	cout << endl;
	int MaxMediana = mediana[0];
	for (int i = 0; i < 10; ++i) {
		if (mediana[i] > MaxMediana) {
			MaxMediana = mediana[i];
		}
	}
	cout << "MaxMediana = " << MaxMediana << endl;

}