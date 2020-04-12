#include <iostream>
#include "Extantion.hpp"
using namespace std;
using namespace ext;
int Mid(int arr[], int lngth)
{
	int count;
	float chetn = 0;
	for (int i = 0; i < 12; i++)
	{
		count = 0;
		for (int k = 0; k < 12; k++)
		{
			if ((arr[i] > arr[k]) and (arr[i] != -1) and (arr[k] != -1))
				count = count + 1;
		}
		if (((12 - lngth) % 2 == 1) and (count == (12 - lngth) / 2))
			return arr[i];
		else if (((12 - lngth) % 2 == 0) and (count == (12 - lngth) / 2 - 1))
			chetn =  chetn + arr[i];
		else if (((12 - lngth) % 2 == 0) and (count == (12 - lngth) / 2))
			chetn = chetn + arr[i];

	}
	return chetn / 2;
}
int main()
{
	int zarp[10][12];
	int vacMonth, vacLength, LocMid, MaxMid, count;
	MaxMid = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << "Worker " << i + 1 << endl;
		vacMonth = GetRandomValue(0, 11);
		vacLength = GetRandomValue(1, 12 - vacMonth);
		for (int k = 0; k < 12; k++)
		{
			if ((k < vacMonth) or (k > vacMonth + vacLength - 1))
			{
				zarp[i][k] = GetRandomValue(1000, 100000);
			}
			else
			{
				zarp[i][k] = -1;
			}
			cout << k + 1 << ") " << zarp[i][k] << ", ";
		};
		LocMid = Mid(zarp[i], vacLength);
		cout << endl << "Mid = " << LocMid << endl;
		if (LocMid > MaxMid)
			MaxMid = LocMid;
	};
	cout << "Maximum = " << MaxMid;
}