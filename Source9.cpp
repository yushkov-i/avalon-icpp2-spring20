#include <iostream>
#include <fstream>
#include <limits>
using namespace std;
struct Triangle
{
	int a;
	int b;
	int c;
	double thickness;
};
const int t = sizeof(Triangle);
int main()
{
	setlocale(0, "");
	int N;
	cin >> N;
	ifstream fin("triangle.bin");
	Triangle tr;
	fin.seekg((N - 1) * t);
	fin.read(reinterpret_cast<char*>(&tr), sizeof(Triangle));
	fin.close();
	cout << "Информация о треугольнике N:" << endl;
	cout << "a = " << tr.a << endl;
	cout << "b = " << tr.b << endl;
	cout << "c = " << tr.c << endl;
	cout << "thickness = " << tr.thickness << endl;
}