#include<iostream>
#include<string>
#include<limits>
#include<fstream>

using namespace std;

struct Triangle
{
	int a;
	int b;
	int c;
	double thickness;
};

const int NUMBER_OF_TRIANGLES = 1000000;
const string TRIANGLE_FILE_NAME = "triangle.bin";

int main() {
	ifstream trianglesFile;
	trianglesFile.open(TRIANGLE_FILE_NAME);
	if (!trianglesFile.is_open()) {
		cerr << TRIANGLE_FILE_NAME << " did'nt open\n";
		return 1;
	}

	int N = 0;
	cin >> N;
	while (N > 1000000 || N < 1) {
		cout << "input 1 <= N <= 1000000" << endl;
		cin >> N;
	}

	Triangle triangle;
	trianglesFile.seekg(N * sizeof(Triangle));
	trianglesFile.read(reinterpret_cast<char*>(&triangle), sizeof(Triangle));
	trianglesFile.close();
	cout << "info: " << endl;
	cout << "a: " << triangle.a << endl;
	cout << "b: " << triangle.b << endl;
	cout << "c: " << triangle.c << endl;
	cout << "Thickness: " << triangle.thickness << endl;

}