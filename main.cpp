#include <iostream>
#include <fstream>
struct Triangle
{
	int a;
	int b;
	int c;
	double thickness;
};
using namespace std;
const string FILE_NAME = "triangle.bin";
void PrintTriangle(Triangle t) {
	cout << "a = " << t.a << "   b = "<< t.b << "   c = " << t.c << "   thickness = " << t.thickness << endl;
}

int main() {
	fstream file;
	file.open(FILE_NAME, iostream::out | iostream::binary | iostream::ate | iostream::in);
	if (!file.is_open()) {
		cerr << FILE_NAME << "not open" << endl;
	}
	int n = 0;
	Triangle t{};
	cout << "n = ";
	cin >> n;
	if ((1 <= n) & (n <= 1000000)) {
		file.seekg(sizeof(Triangle) * (n - 1), ios::beg);
		file.read(reinterpret_cast<char*>(&t), sizeof(Triangle));
		PrintTriangle(t);
	}
	file.close();
}