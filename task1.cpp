#include <iostream>
#include <fstream>
using namespace std;
bool LuckyTicket(int t) {
	if (((t / 100000) + ((t / 10000) % 10) + ((t / 1000) % 10)) == ((t % 10) + ((t / 10) % 10) + ((t / 100) % 10))) { return true; }
	else { return false; }
}
int main() {
	ifstream file;
	file.open("tickets.txt"); // open or create
	if (!file.is_open())
	{
		cout << "tickets.txt file did not open!" << endl;
		return 1;
	}
	ofstream lucky;
	lucky.open("lucky.txt"); // open or create
	if (!lucky.is_open())
	{
		cout << "lucky.txt file did not open!" << endl;
		return 1;
	}
	ofstream unlucky;
	unlucky.open("unlucky.txt"); // open or create
	if (!unlucky.is_open())
	{
		cout << "unlucky.txt file did not open!" << endl;
		return 1;
	}


	int ticket = 0, countl=0,countu=0;
	for (int i = 0; i < 1000; ++i)
	{
		file >> ticket;
		file.ignore(std::numeric_limits<int>::max(), '\n');
		if (LuckyTicket(ticket)) {
			lucky << ticket<<endl;
			countl += 1;
		}
		else {
			unlucky << ticket<<endl;
			countu += 1;
		}
	}
	cout << "lucky = "<<countl<< endl;
	cout << "unlucky = " << countu << endl;
	file.close();
	lucky.close();
	unlucky.close();
}