#include <iostream>
#include <cstdlib>
#include "D:\Home\C++\Extention.hpp"
using namespace std;
using namespace ext;

const int Player_10 = 2;
const int Month_12 = 12;

void Swap_1_on_100001(int **Mass_Pay, int i) {
	for (int j = 0; j < Month_12; j++) {
		if (Mass_Pay[i][j] == -1) {
			Mass_Pay[i][j] = 100001;
		}
	}
	//return Mass_Pay[Month_12];
}

int Puziriki(int Mass_Pay[Month_12]) {
	for (int i = 0; i < Month_12; i++) {
		for (int j = 0; j < Month_12 - 1 - i; j++) {
			if (Mass_Pay[j] > Mass_Pay[j + 1]) {
				int Swap = Mass_Pay[j];
				Mass_Pay[j] = Mass_Pay[j + 1];
				Mass_Pay[j + 1] = Swap;
			}
		}
	}
	return Mass_Pay[Month_12];
}



int main() {
	setlocale(LC_ALL, "RUS");
	int Mass_Agent[Player_10][Month_12] = {};
	int Flag;
	for (int i = 0; i < Player_10; i++) {
		for (int j = 0; j < Month_12; j++) {
			Flag = GetRandomValue(1, 100);
			if (Flag > 0 && Flag <= 10) {
				Mass_Agent[i][j] = -1;
			}
			else {
				Mass_Agent[i][j] = GetRandomValue(1000, 100000);
			}
		}
	}

	for (int i = 0; i < Player_10; i++) {
		for (int j = 0; j < Month_12; j++) {
			if (Mass_Agent[i][j] == -1) {
				Mass_Agent[i][j] = 100001;
			}
		}
	}
	//Mass_Agent[k][j]
	for (int k = 0; k < Player_10; k++) {
		for (int i = 0; i < Month_12; i++) {
			for (int j = 0; j < Month_12 - 1 - i; j++) {
				if (Mass_Agent[k][j] > Mass_Agent[k][j + 1]) {
					int Swap = Mass_Agent[k][j];
					Mass_Agent[k][j] = Mass_Agent[k][j + 1];
					Mass_Agent[k][j + 1] = Swap;
				}
			}
		}
	}
	int Count = 0, Max = -1, ID_Player_Max;
	for (int i = 0; i < Player_10; i++) {
		for (int j = 0; j < Month_12; j++) {
			if (Mass_Agent[i][j] != 100001){
				Count++;
			}
			else { break; }
		}
		if (Count % 2 == 0) {
			if (Max < (Mass_Agent[i][Count / 2 - 1] + Mass_Agent[i][Count / 2]) / 2) {
				Max = (Mass_Agent[i][Count / 2 - 1] + Mass_Agent[i][Count / 2]) / 2;
				ID_Player_Max = i;
			}
		}
		else {
			if (Max < Mass_Agent[i][Count / 2]) {
				Max = Mass_Agent[i][Count / 2];
				ID_Player_Max = i;
			}
		}
		Count = 0;
	}
	cout << "Агент №" << ID_Player_Max + 1 << endl;


	system("pause");
}