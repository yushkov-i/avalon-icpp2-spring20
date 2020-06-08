#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const string ticketsFile = "tickets.txt";
const string luckyFile = "lucky.txt";
const string unluckyFile = "unlucky.txt";
const int ticketsSum = 1000;

bool IsTickets(int tickets)
{
	int lhs = 0, rhs = 0;

	while (tickets > 999)
	{
		lhs += tickets % 10;
		tickets /= 10;
	}
	while (tickets > 0)
	{
		rhs += tickets % 10;
		tickets /= 10;
	}
	return lhs == rhs;
}

int main()
{
	ifstream tickets;
	tickets.open(ticketsFile);

	ofstream lucky;
	lucky.open(luckyFile);
	
	ofstream unlucky;
	unlucky.open(unluckyFile);

	int curTicket;
	for (int tic = 1; tic <= ticketsSum; tic++)
	{
		tickets >> curTicket;
		if (IsTickets(curTicket)) lucky << curTicket<< '\n';
		else unlucky << curTicket << '\n';
	}
	tickets.close();
	lucky.close();
	unlucky.close();
}