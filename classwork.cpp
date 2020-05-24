#include <iostream>
#include <fstream>

using namespace std;

struct Point
{
	int x;
	int y;
};

const int POINT_DATA_SIZE = sizeof(Point); // сохраним размер структуры в константу

int main()
{
	Point p[5] = { {5,6},{7,8},{9,10},{11,12},{13,14} };
	ofstream fileOutBin;
	fileOutBin.open("point.bin", iostream::binary); // открываем файл для записи в бинарном режиме
	if (!fileOutBin.is_open())
	{
		cerr << "file did not open!";
	}

	fileOutBin.write(reinterpret_cast<const char*>(p), POINT_DATA_SIZE * 5); // записываем в файл массив Point, сразу все 5 элементов
	fileOutBin.close();

	Point newPoint = { 2,3 };
	fileOutBin.open("point.bin", iostream::binary | iostream::ate | iostream::in); // открываем файл в режиме для добавления / изменения
	cout << fileOutBin.tellp() << endl; // курсов после открытия установлен в конец файла
	fileOutBin.seekp(0); // устанавливаем курсор на начало файла
	cout << fileOutBin.tellp() << endl;

	fileOutBin.write(reinterpret_cast<const char*>(&newPoint), POINT_DATA_SIZE); // изменяем первую точку
	cout << fileOutBin.tellp() << endl;

	fileOutBin.seekp(0, iostream::end); // перемещаем курсор на конец файла
	fileOutBin.write(reinterpret_cast<const char*>(&newPoint), POINT_DATA_SIZE); // добавляем точку в конец файла
	cout << fileOutBin.tellp() << endl;

	cout << fileOutBin.tellp() / POINT_DATA_SIZE << endl; // так можно узнать количество записей в бинарном файле
	
	fileOutBin.close();

	ifstream fileInBin;
	fileInBin.open("point.bin", iostream::binary); // открываем файл для чтения в бинарном формате
	Point pp[5]; // сюда будем записывать результат чтения из файла
	
	fileInBin.read(reinterpret_cast<char*>(pp), POINT_DATA_SIZE * 5); // чтение из файла	
}
