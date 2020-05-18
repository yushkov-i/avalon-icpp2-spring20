#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string TICKETS_FILE_NUMBER = "tickets.txt";
const string LUCKY_FILE_NUMBER = "lucky.txt";
const string UNLUCKY_FILE_NUMBER = "unlucky.txt";
const int NUMBER_OF_TICKETS = 1000;

int main() {
	ifstream Tickets_ifstream;
	Tickets_ifstream.open(TICKETS_FILE_NUMBER);
	if (!Tickets_ifstream.is_open()) {
		cout << "File " << TICKETS_FILE_NUMBER << " didn't open!";
		return 1;
	}
	ofstream Lucky_ofstream;
	Lucky_ofstream.open(LUCKY_FILE_NUMBER);
	if (!Lucky_ofstream.is_open()) {
		cout << "File " << LUCKY_FILE_NUMBER << " didn't open!";
		return 2;
	}
	ofstream Unlucky_ofstream;
	Unlucky_ofstream.open(UNLUCKY_FILE_NUMBER);
	if (!Unlucky_ofstream.is_open()) {
		cout << "File " << UNLUCKY_FILE_NUMBER << " didn't open!";
		return 3;
	}
	int Number_Tikets = 0, Save_for_cout_Number_Tikets = 0;
	int Summa_First = 0, Summa_Second = 0;
	int Count_Lucky = 0, Count_Unlucky = 0;
	for (int i = 0; i < NUMBER_OF_TICKETS; i++) {
		Tickets_ifstream >> Number_Tikets;
		Save_for_cout_Number_Tikets = Number_Tikets;
		for (int j = 1; j < 7; j++) {
			if (j < 4) {
				Summa_First = Summa_First + (Number_Tikets % 10);
				Number_Tikets = Number_Tikets / 10;
			}
			if (j > 3) {
				Summa_Second = Summa_Second + (Number_Tikets % 10);
				Number_Tikets = Number_Tikets / 10;
			}
		}
		if (Summa_First == Summa_Second) {
			Lucky_ofstream << Save_for_cout_Number_Tikets << '\n';
			Count_Lucky++;
		}
		else {
			Unlucky_ofstream << Save_for_cout_Number_Tikets << '\n';
			Count_Unlucky++;
		}
		Summa_First = 0;
		Summa_Second = 0;
	}
	Tickets_ifstream.close();
	Lucky_ofstream.close();
	Unlucky_ofstream.close();
	cout << "Number of unlucky numbers - " << Count_Lucky << endl;
	cout << "Number of lucky numbers - " << Count_Unlucky << endl;
}