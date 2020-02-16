#include <iostream>
using namespace std;

int main()
{
	int N;
	cout << "Enter N" << endl;
	cin >> N;
	cout << "ISBN-13:" << endl;
	for (int i = 0; i < N; i++) {
		int long long isbn, isbn1, isbn2;
		int k = 0, end, sum = 0, number, remains, num;
		cin >> isbn;
		isbn1 = isbn;
		end = isbn % 10;
		isbn /= 10;
		isbn2 = isbn * 10;
		do {
			number = isbn % 10;
			isbn /= 10;
			if (k % 2 == 0)
				sum += number * 3;
			else
				sum += number * 1;
			k++;
		} while (isbn >= 1);
		remains = sum % 10;
		num = 10 - remains;
		isbn2 += num;
		if (isbn2 == isbn1)
			cout << "valid" << endl;
		else
			cout << "invalid" << endl;
	}
	return 0;
}
