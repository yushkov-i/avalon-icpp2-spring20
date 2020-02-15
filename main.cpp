#include<iostream>

using namespace std;


using namespace std;
int a;
long long ISBN13check(long long numb)
{
	long long numb1 = numb;
	 long long masOfNum[13];
	int i = 0;
	while (numb1 > 0)
	{
		masOfNum[i++] = numb1 % 10;
		numb1 /= 10;
	}
	if(masOfNum[0] == 10 - (masOfNum[12] + masOfNum[11] * 3 + masOfNum[10] + masOfNum[9] * 3 + masOfNum[8] + masOfNum[7] * 3 + masOfNum[6] + masOfNum[5] * 3 + masOfNum[4] + masOfNum[3] * 3 + masOfNum[2] + masOfNum[1] * 3) % 10)
    return a = 1;
}


int main()
{
	int n; long long numbISBN;
	cin >> n;
	while (n != 0)
	{
		cin >> numbISBN;
		ISBN13check(numbISBN);
		if (a == 1)
		{
			cout << "Valid";
			n -= 1;
		}
		else
		{
			cout << "Invalid";
			n -= 1;
		}
	}

}

