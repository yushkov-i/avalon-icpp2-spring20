#include <iostream>
#include "Extention.hpp"
#include <iomanip>

using namespace std;
using namespace ext;

int main() {
	setlocale(LC_ALL, "Rus");
	const int N = 10;
	float x;
	int u;
	bool sort = 0;
	bool worked_with_first[N]; //0 - не работал с начала(только взятие на работу), 1 - работал (только увольнение)
	bool worked[N]; //0 - не работает сейчас, 1 - работает сейчас
	int no_work[N]{};
	int money[N][12];
	for (int i = 0; i < N; i++) {
		cout << "Агент №" << (i + 1) << ": ";
		for (int j = 0; j < 12; j++) {
			if (j == 0) {
				if ((static_cast <float> (rand()) / (static_cast <float> (RAND_MAX))) > 0.2) {
					worked_with_first[i] = 1;
					worked[i] = 1;
				}
				else {
					worked_with_first[i] = 0;
					worked[i] = 0;
				}
				if (worked_with_first[i] == 1) {
					money[i][j] = GetRandomValue(1000, 100000);
				}
				else {
					money[i][j] = -1;
				}
			}
			else {
				if (worked_with_first[i] == 1 && worked[i] == 1) {
					if ((static_cast <float> (rand()) / (static_cast <float> (RAND_MAX))) > 0.2) {
						worked[i] = 1;
					}
					else {
						worked[i] = 0;
					}
				}
				if (worked_with_first[i] == 0 && worked[i] == 0) {
					if ((static_cast <float> (rand()) / (static_cast <float> (RAND_MAX))) > 0.2) {
						worked[i] = 1;
					}
					else {
						worked[i] = 0;
					}
				}
				if (worked[i] == 1) {
					money[i][j] = GetRandomValue(1000, 100000);
				}
				else {
					money[i][j] = -1;
				}
			}
			if (j == 0 && i == 9) {
				cout << setw(6) << money[i][j];
			}
			else {
				cout << setw(7) << money[i][j];
			}
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 0; i < N; i++) {	
		sort = 0;
		while (sort == 0) {
			sort = 1;
			for (int j = 11; j > 0; j--) {
				if (money[i][j - 1] < money[i][j]) {
						u = money[i][j];
						money[i][j] = money[i][j - 1];
						money[i][j - 1] = u;
						sort = 0;
				}
			}		
		}
	}
	for (int i = 0; i < N; i++) {
		//cout << "Агент №" << (i + 1) << ": ";
		for (int j = 0; j < 12; j++) {
			/*if (j == 0 && i == 9) {
				cout << setw(6) << money[i][j];
			}
			else {
				cout << setw(7) << money[i][j];
			}*/
			if (money[i][j] == -1) {
				no_work[i]++;
			}
		}
		//cout << endl;
	}
	// сортированный лист заработка
	for (int i = 0; i < N; i++) {
		if (no_work[i] % 2 == 0) {
			cout << "Медиана агента №" << i + 1 << " равна: " << (money[i][(12 - no_work[i]) / 2 - 1] + money[i][(12 - no_work[i]) / 2]) / 2 << endl;
		}
		else {
			cout << "Медиана агента №" << i + 1 << " равна: " << money[i][(12 - no_work[i]) / 2] << endl;
		}
	}
}
