#include <iostream>
using namespace std;
/*
void print(int data[], int size)
{
	int size = sizeof(data) / sizeof(int);
	for (int i = 0; i < size; i++)
	{
		cout << data[i] << endl;
	}
}
*/
const int DATA_SIZE = 8;
int main()
{
	int data[DATA_SIZE] = { 2,3,4,3,2,1,3,4 };
	for (int i = 0; i< DATA_SIZE-1-i; i++ )
	{
		bool hasSwap = false;
		for (int j=0; j< DATA_SIZE-1; j++)
		{
			if (data[j] > data[j + 1]) { int temp = data[j]; data[j] = data[j + 1]; data[j + 1] = temp; hasSwap = true; }
		}
		if (!hasSwap) { break; }
	}
	/*
	char data[5] = { 'h', 'e', 'l', 'l', 'o' };
	char name[] = "Hello";
	cout << data << endl; 
	cout << data + 1 << endl; 
	*/
	//print(data);
	/*
		int data[5] = {2,4,6,8,10};
	cout << *data << endl; //2
	cout << *(data + 1) << endl; //4
	int a=6;
	cout << ++a << endl; //7
	cout << a++ << endl; //6
	*/
	/*
	int* ptr_data = nullptr; 
	while (true)
	{
		ptr_data=new int[1000]; // режим х64 и компу кранты
		cout << "CHEATER NOOB! RIP PC :D ";
	}
	
	int data[DATA_SIZE];
	for (int i = 0; i < DATA_SIZE; i++)	
	{		
		cout << data[i] << endl;
	}
	*/
}