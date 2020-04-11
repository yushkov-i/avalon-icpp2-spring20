#include <iostream>
using namespace std;

const char * STROKA = "Hello";

int main()
{
	const char *data = new char[2]{ 'a','b' };
	delete[] data;


	int a = 0;
	
	int * ptr = nullptr;

	ptr = new int[100];
	
	for (int i = 0; i < 100; ++i)
	{
		ptr[i] = i * i;
	}
	
	for (int i = 0; i < 100; ++i)
	{
		cout << ptr << endl;
	}

	int * ptr2 = ptr;

	delete[] ptr;
	ptr = nullptr;

	//много кода

	delete[] ptr2;

	ptr = new int[200];
	delete[] ptr;

	double * ptrD = new double{};
	*ptrD = 10.2;
	cout << *ptrD << endl;

	delete ptrD;
}
