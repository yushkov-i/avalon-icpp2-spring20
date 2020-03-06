#include <iostream>
#include "Extention.h"
using namespace std;
using namespace ext;


int main() 
{
	const int n=10;//Count of agents	
	int  ag[n][12];
	cout << "\t"<<" ";
	for (int i = 0; i < 12; i++) {
		cout <<"___"<< i+1 << "\t"<<"|";
	}
	cout << endl<<" 1)"<<"\t";
	for (int i = 0; i < n; i++) {
		switch (GetRandomValue(1, 3)) {
		case 1: {
			for (int g = 0; g < 12; g++) {
				ag[i][g] = GetRandomValue(1000, 100000);

				cout << ag[i][g] << "\t" << "|";

			}
			break; }
		case 2: {
			int del;
			del = GetRandomValue(1, 11);
			for (int g = 0; g < 12 - del; g++) {
				ag[i][g] = GetRandomValue(1000, 100000);

				cout << ag[i][g] << "\t" << "|";
			}
			for (int g = 12 - del; g < 12; g++) {
				ag[i][g] = -1;

				cout << ag[i][g] << "\t" << "|";
			}
			break; }
		case 3: {int del;
			del = GetRandomValue(1, 11);
			for (int g = 0; g < del; g++) {
				ag[i][g] = -1;

				cout << ag[i][g] << "\t" << "|";
			}
			for (int g = del; g < 12 ; g++) {
				ag[i][g] = GetRandomValue(1000, 100000);

				cout << ag[i][g] << "\t" << "|";
			}
			  }
		}
		cout << endl;
		if (i + 1 < n) {
			if (i < 10) {
				cout << " ";
			}
			cout << i + 2 << ")" << "\t";
		}
	}
	cout << endl << "SORTED" << endl;
	int count;
	
	int sort[12];
	cout << endl << "1)" << "\t";
	for (int i = 0; i < n; i++) {
		for (int g = 0; g < 12; g++) {
			sort[g] = ag[i][g];
		}	
		count = 0;
	do
	{

		int mem;
		if (sort[count] > sort[count + 1]) {
			mem = sort[count];
				sort[count] = sort[count + 1];
				sort[count + 1] = mem;
				count = 0;
		}
		else {
			count++;
		}
	
	} while (count<11);
	
	for (int g = 0; g < 12; g++) {
		ag[i][g] = sort[g];
		cout << ag[i][g] << "\t" << "|";
	}if (i < n-1) {
		cout << endl << i + 2 << ")" << "\t";
	}
	}
	int ans, ansnum;
	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int g = 0; g < 12; g++) {
			if (g > 0) {
				ans = 12 - g - 1;
				if (ans % 2 == 0) {
					ans = ans / 2;
					ans = (ag[i][ans] + ag[i][ans]) / 2;
					if (ans > max) {
						max = ans;
						ansnum = 1 + i;
					}
				}
				else {
					ans = (ans + 1) / 2;
					if (ag[i][ans] > max) {
						ansnum = i + 1;
					}
				}
			}
		}
	}
	cout <<endl<< "ANSWER: " << ansnum;
}