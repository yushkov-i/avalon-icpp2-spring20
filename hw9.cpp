#include <iostream>
#include <fstream>
using namespace std;
struct Triangle{
	int a;
	int b;
	int c;
	//double thickness;
};

const int TRIANGLE_SIZE = sizeof(Triangle);

int main()
{
	int N;
	cin >> N;
	ifstream input;
	input.open("triangle.bin", ios::binary);
	if (!input.is_open()){
		cerr << "triangle.bin File did not open!";
		return 1;
	}
	Triangle triangle;
	input.seekg(N * TRIANGLE_SIZE);
	input.read(reinterpret_cast<char*>(&triangle), sizeof(Triangle));
	input.close();
	cout << "a = " << triangle.a <<
	endl << "b = " << triangle.b << 
	endl<< "c = " << triangle.c << 
	endl << "thickness = " << triangle.thickness << endl;
}

