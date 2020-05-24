#include <iostream>
#include <fstream>
using namespace std;
struct Triangle
{
	int a;
	int b;
	int c;
	double thickness;
};
const double TRIANGLE_DATA_SIZE = sizeof(Triangle);
int main()
{
	int N;
	cout << "Enter N" << endl;
	cin >> N;
	fstream triangleFile;
	triangleFile.open("triangle.bin", iostream::binary | iostream::ate | iostream::in);
	if (!triangleFile.is_open())
	{
		cerr << "file did not open!";
		return 1;
	}
	Triangle triangle;
	triangleFile.seekg(N * TRIANGLE_DATA_SIZE);
	triangleFile.read(reinterpret_cast<char*>(&triangle), sizeof(Triangle));
	triangleFile.close();
	cout << "Information about a triangle N:" << endl;
	cout << "a = " << triangle.a << endl;
	cout << "b = " << triangle.b << endl;
	cout << "c = " << triangle.c << endl;
	cout << "thickness = " << triangle.thickness << endl;
}