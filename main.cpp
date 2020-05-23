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
	cout << "Введите порядковый номер треугольника (от 0 до 999999): ";
	cin >> id;
	file_in_bin.seekg(id * TRIANGLE_DATA_SIZE / 2, ios::beg);
	Triangle tmp[1];
	file_in_bin.read(reinterpret_cast<char*>(tmp), TRIANGLE_DATA_SIZE);
	cout << "Длины сторон треугольника с индексом " << id << ": " << tmp[0].a << ", " << tmp[0].b << ", " << tmp[0].c << "; толщина: " << tmp[0].thickness << '.' << endl;
	/*задание 2*/
	cout << "Введите периметр искомого треугольника: ";
	int perimetr, l = 0, r = 999999, mid;
	cin >> perimetr;
	bool flag = 0;
	while ((l <= r) && (flag == 0)) {
		mid = (l + r) / 2;
		file_in_bin.seekg(0);
		file_in_bin.seekg(mid * TRIANGLE_DATA_SIZE / 2, ios::beg);
		file_in_bin.read(reinterpret_cast<char*>(tmp), TRIANGLE_DATA_SIZE);
		if (tmp[0].a + tmp[0].b + tmp[0].c == perimetr) {
			flag = 1;
			break;
		}
		if (tmp[0].a + tmp[0].b + tmp[0].c > perimetr) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	if (flag == 1) {
		cout << "Длины сторон искомого треугольника: " << tmp[0].a << ", " << tmp[0].b << ", " << tmp[0].c << "; толщина: " << tmp[0].thickness << '.' << endl;
	}
	else {
		cout << "Треугольник с заданными параметрами не найден.";
	}
	file_in_bin.close();
	return 0;
}
