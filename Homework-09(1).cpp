#include <iostream>
#include <fstream>

using namespace std;
struct Triangle{
	int a;
	int b;
	int c;
	double thickness;
};

int main() {
	cout << "Enter the triangle number: ";
	int Num_T;
	cin >> Num_T;
	ifstream Triangle_Num;
	Triangle_Num.open("triangle.bin", iostream::binary);
	if (!Triangle_Num.is_open()) {
		cerr << "File didn't open!";
		return 1;
	}
	Triangle_Num.seekg(sizeof(Triangle)*Num_T);
	Triangle triangle;
	Triangle *ptr_triangle = &triangle;
	Triangle_Num.read(reinterpret_cast<char*>(&triangle), sizeof(Triangle));
	Triangle_Num.close();
	cout << "a = " << triangle.a << endl;
	cout << "b = " << triangle.b << endl;
	cout << "c = " << triangle.c << endl;
	cout << "thickness = " << triangle.thickness << endl;
}