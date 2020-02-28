#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long n, isbn;
	int k, i, sum, N; 
	cout << "N = ";
	cin >> N;
	for (k = 1; k <= N; k++)
	{
		sum = 0;
		cout << k << ") ISBN = ";
		cin >> isbn;
		for (i = 1; i < 13; i++)
		{
			n = isbn / pow(10, (13 - i));
			n = n % 10;
			n = n * pow(3, ((i - 1) % 2));
			sum = sum + n;
		}
		sum = 10 - sum % 10;
		n = isbn % 10;
		if (n == sum)
			cout << "Valid" << endl;
		else
			cout << "Invalid" << endl;
	}
}
