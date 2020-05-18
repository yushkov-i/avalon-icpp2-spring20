#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int TICKETS_COUNT = 1000;
const string TICKETS_FILE_NAME = "tickets.txt";
const string LUCKY_FILE_NAME = "lucky.txt";
const string UNLUCKY_FILE_NAME = "unlucky.txt";

int main() {
	setlocale(LC_ALL, "Rus");
	ifstream tickets_file;
	ofstream lucky;
	ofstream unlucky;
	tickets_file.open("tickets.txt", ios::in);
	lucky.open("lucky.txt", ios::out);
	unlucky.open("unlucky.txt", ios::out);
	if (!tickets_file.is_open())
	{
		cerr << TICKETS_FILE_NAME << " did not open\n";
		return 1;
	}
	if (!lucky.is_open())
	{
		cerr << LUCKY_FILE_NAME << " did not open\n";
		return 2;
	}
	if (!unlucky.is_open())
	{
		cerr << UNLUCKY_FILE_NAME << " did not open\n";
		return 3;
	}
	int tickets[1000];
	int summ_left, summ_right, tmp;
	for (int i = 0; i < TICKETS_COUNT; i++) {
		tickets_file >> tickets[i];
		tmp = tickets[i];
		summ_left = 0;
		summ_right = 0;
		for (int j = 0; j < 3; j++) {
			summ_right += tmp % 10;
			tmp = (tmp - tmp % 10) / 10;
		}
		for (int j = 0; j < 3; j++) {
			summ_left += tmp % 10;
			tmp = (tmp - tmp % 10) / 10;
		}
		if (summ_left == summ_right) {
			lucky << tickets[i] << endl;
		}
		else {
			unlucky << tickets[i] << endl;
		}
	}
	tickets_file.close();
	lucky.close();
	unlucky.close();
	cout << "Проверка выполнена, проверьте файлы 'lucky.txt' и 'unlucky.txt'";
	return 0;
}