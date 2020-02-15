#include <iostream>

using namespace std;

int main() {
	int N, checked{}, current_num, summ;
	char isbn;
	char isbn13[14];
	char isbn10[11];
	setlocale(LC_ALL, "Rus");
	cout << "Выберите тип номера. Введите 1 - для ISBN-13, 2 - для ISBN-10: ";
	cin >> isbn;
	cout << "Введите количество номеров, которые Вы хотите проверить: ";
	cin >> N;
	if (isbn == '1') {
		while (checked != N + 1) {
			current_num = -1;
			summ = 0;
			cout << "Введите номер книги в нужном формате: ";
			cin >> isbn13;
			while (current_num != 11) {
				current_num++;
				if (current_num % 2 == 0) {
					summ += (isbn13[current_num] - '0');
				}
				else {
					summ += (isbn13[current_num] - '0') * 3;
				}				
			}
			summ %= 10;
			if (isbn13[12] - '0' == 10 - summ) {
				cout << "valid" << endl;
			}
			else {
				cout << "invalid" << endl;
			}
			checked++;
			if (checked == N) {
				break;
			}
		}
	}
	else {
		while (checked != N + 1) {
			current_num = -1;
			summ = 0;
			cout << "Введите номер книги в нужном формате: ";
			cin >> isbn10;
			while (current_num != 8) {
				current_num++;
				summ += (isbn10[current_num] - '0') * (10 - current_num);
			}
			summ %= 11;
			if (isbn10[9] - '0' == 11 - summ) {
				cout << "valid" << endl;
			}
			else {
				cout << "invalid" << endl;
			}
			checked++;
			if (checked == N) {
				break;
			}
		}
	}
	return 0;
}