#include <iostream>
#include <fstream>

using namespace std;

struct Triangle {
	int a;
	int b;
	int c;
	double thickness;
};

const size_t TRIANGLE_DATA_SIZE = sizeof(Triangle);
const string TRIANGLE_NAME_FILE = "triangle.bin";

int main() {
	setlocale(LC_ALL, "Rus");
	ifstream file_in_bin;
	file_in_bin.open("triangle.bin", ios::binary);
	if (!file_in_bin.is_open()){
		cerr << TRIANGLE_NAME_FILE << " file did not open!";
		return 2;
	}
	/*задание 1*/
	size_t id;
	cout << TRIANGLE_DATA_SIZE << ' ';
	cout << "Введите порядковый номер треугольника (от 1 до 1000000): ";
	cin >> id;
	file_in_bin.seekg(id * TRIANGLE_DATA_SIZE);
	cout << file_in_bin.tellg() << endl;
	Triangle tmp[1];
	file_in_bin.read(reinterpret_cast<char*>(tmp), TRIANGLE_DATA_SIZE);
	cout << tmp[0].a << ' ' << tmp[0].b << ' ' << tmp[0].c << ' ' << tmp[0].thickness;
}
