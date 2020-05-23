#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const string TICKETS_FILE_NAME = "tickets.txt";
const string LUCKY_FILE_NAME = "lucky.txt";
const string UNLUCKY_FILE_NAME = "unlucky.txt";
const int NUMBER_OF_TICKETS = 1000;


int main() {
	ifstream ticketsFile;
	ofstream luckyFile;
	ofstream unluckyFile;
	ticketsFile.open(TICKETS_FILE_NAME);
	luckyFile.open(LUCKY_FILE_NAME);
	unluckyFile.open(UNLUCKY_FILE_NAME);
	if (!ticketsFile.is_open()) {
		cerr << TICKETS_FILE_NAME << " didn't open\n";
		return 1;
	 }
	if (!luckyFile.is_open()) {
		cerr << LUCKY_FILE_NAME << " didn't open\n";
		return 2;
	}
	if (!unluckyFile.is_open()) {
		cerr << UNLUCKY_FILE_NAME << " didn't open\n";
		return 3;
	}

	int luckyCount = 0, unluckyCount = 0;
	int *ticketsArr = new int[NUMBER_OF_TICKETS];
	for (int i = 0; i < NUMBER_OF_TICKETS; ++i)
	{
		ticketsFile >> ticketsArr[i];
		ticketsFile.ignore(std::numeric_limits<int>::max(), '\n');
	}
	ticketsFile.close();

	 //следующее я хотел в функцию перенести, но тогда снова надо было бы файл в ней открывать?
	int leftSum = 0, rightSum = 0, ticket = 0;
	for (int i = 0; i < NUMBER_OF_TICKETS; ++i) {
		ticket = ticketsArr[i];
		do {
			rightSum = rightSum + ticket % 10;
			ticket = ticket / 10;
		} while (ticket / 10 > 1000);
		do {
			leftSum = leftSum + ticket % 10;
			ticket = ticket / 10;
		} while (ticket / 10 > 1);
		if (rightSum == leftSum) {
			luckyCount++;
			luckyFile << ticketsArr[i] << endl;
		}
		else {
			unluckyCount++;
			unluckyFile << ticketsArr[i] << endl;
		}
		leftSum = 0;
		rightSum = 0;
	}
	cout << "count of lucky tickets " << luckyCount << endl;
	cout << "count of unlucky tickets " << unluckyCount << endl;
	luckyFile.close();
	unluckyFile.close();
}