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
	int fromN;
	int toN;
	inputValue("from = ", fromN);
	inputValue("to = ", toN);

	fstream fileIn;
	fileIn.open(FILENAME, iostream::in | iostream::binary);
	if (!fileIn.is_open())
	{
		cerr << FILENAME << " did not open\n";
		return 1;
	}

	int triangleCount = toN - fromN;
	Triangle * trianglePtr = new Triangle[triangleCount];
	int offset = TRIANGLE_DATA_SIZE * (fromN - 1);
	fileIn.seekg(offset);

	fileIn.read(reinterpret_cast<char*>(trianglePtr),
		TRIANGLE_DATA_SIZE * triangleCount);
	fileIn.close();

	for (int i = 0; i < triangleCount; ++i)
	{
		cout << fromN + i << ": "
			<< trianglePtr[i].a << " "
			<< trianglePtr[i].b << " "
			<< trianglePtr[i].c << '\n';
	}
	cout.flush();

	delete[] trianglePtr;
}