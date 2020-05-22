#include <fstream>
#include <iostream>
#include <string>
using namespace std;
const string TICKETS_FILE_NAME = "tickets.txt";
const string LUCKY_FILE_NAME = "lucky.txt";
const string UNLUCKY_FILE_NAME = "unlucky.txt";
const int tickets_count = 1000;
int main()
{
	ifstream ticketsFile;
	ticketsFile.open(TICKETS_FILE_NAME);
	ofstream LuckyFile;
	LuckyFile.open(LUCKY_FILE_NAME);
	ofstream UnluckyFile;
	UnluckyFile.open(UNLUCKY_FILE_NAME);
	if (!ticketsFile.is_open())
	{
		cerr << TICKETS_FILE_NAME << " did not open\n";
		return 1;
	}
	if (!LuckyFile.is_open())
	{
		cerr << LUCKY_FILE_NAME << " did not open\n";
		return 2;
	}
	if (!UnluckyFile.is_open())
	{
		cerr << UNLUCKY_FILE_NAME << " did not open\n";
		return 3;
	}
	int tickets[tickets_count];
	for (int i = 0; i < tickets_count; i++)
	{
		ticketsFile >> tickets[i];
		ticketsFile.ignore(std::numeric_limits<int>::max(), '\n');
	}
	ticketsFile.close();
	int count_lucky = 0, count_unlucky = 0;
	for (int i = 0; i < tickets_count; i++)
	{
		int sum1_3 = 0, sum4_6 = 0, number, num = tickets[i];
		for (int i = 0; i < 3; i++)
		{
			number = num % 10;
			num /= 10;
			sum1_3 += number;
		}
		for (int i = 0; i < 3; i++)
		{
			number = num % 10;
			num /= 10;
			sum4_6 += number;
		}
		if (sum1_3 == sum4_6)
		{
			LuckyFile << tickets[i] << endl;
			count_lucky++;
		}
		else
		{
			UnluckyFile << tickets[i] << endl;
			count_unlucky++;
		}
	}
	LuckyFile.close();
	UnluckyFile.close();
	cout << "Count of lucky numbers: " << count_lucky << endl;
	cout << "Count of unlucky numbers: " << count_unlucky << endl;
	return 0;
}
