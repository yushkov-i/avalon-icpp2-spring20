#include <fstream>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

struct Triangle
{
	int a;
	int b;
	int c;	
};

const int TRIANGLE_DATA_SIZE = sizeof(Triangle);
const string FILENAME = "triangle.bin";

void inputValue(string valueInfo, int& value)
{
	cout << valueInfo;
	cin >> value;
	cin.ignore(numeric_limits<int>::max(), '\n');	
}

int main()
{
	fstream fileIn;
	fileIn.open(FILENAME, iostream::in | iostream::binary);
	if (!fileIn.is_open())
	{
		cerr << FILENAME << " did not open\n";
		return 1;
	}

	int N;
	inputValue("N = ", N);

	int offset = TRIANGLE_DATA_SIZE * (N - 1);
	fileIn.seekg(offset);
	
	Triangle tr; // &tr => 0x80
	fileIn.read(reinterpret_cast<char*>(&tr), TRIANGLE_DATA_SIZE);
	fileIn.close();

	cout << tr.a << " " << tr.b << " " << tr.c << endl;

	cout << "Input new values:" << endl;

	inputValue("a = ", tr.a);
	inputValue("b = ", tr.b);
	inputValue("c = ", tr.c);

	fstream fileOut;
	fileOut.open(FILENAME, 
		iostream::out | iostream::binary | iostream::ate | iostream::in);
	if (!fileOut.is_open())
	{
		cerr << FILENAME << " did not open\n";
		return 1;
	}

	fileOut.seekg(offset);
	fileOut.write(reinterpret_cast<char*>(&tr), TRIANGLE_DATA_SIZE);
	fileOut.close();
}