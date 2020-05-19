#include <iostream>
#include <fstream>

using namespace std;

struct Point
{
	int x;
	int y;
};

const int POINT_DATA_SIZE = sizeof(Point);

int main()
{
	Point p[5] = { {5,6},{7,8},{9,10},{11,12},{13,14} };
	ofstream fileOutBin;
	fileOutBin.open("point.bin", iostream::binary);
	if (!fileOutBin.is_open())
	{
		cerr << "file did not open!";
	}

	fileOutBin.write(reinterpret_cast<const char*>(p), sizeof(Point) * 5);
	fileOutBin.close();

	Point newPoint = { 2,3 };
	fileOutBin.open("point.bin", iostream::binary | iostream::ate | iostream::in);
	cout << fileOutBin.tellp() << endl;
	fileOutBin.seekp(0);
	cout << fileOutBin.tellp() << endl;

	fileOutBin.write(reinterpret_cast<const char*>(&newPoint), POINT_DATA_SIZE);
	cout << fileOutBin.tellp() << endl;

	fileOutBin.seekp(0, iostream::end);
	fileOutBin.write(reinterpret_cast<const char*>(&newPoint), POINT_DATA_SIZE);
	cout << fileOutBin.tellp() << endl;

	cout << fileOutBin.tellp() / POINT_DATA_SIZE << endl;
	fileOutBin.seekp(0);
	fileOutBin.close();

	fileOutBin.seekp(0); // возвращает курсор
	fileOutBin.write(reinterpret_cast<const char*>(&newPoint), sizeof(Point));
	fileOutBin.seekp(0, iostream::end);
	fileOutBin.seekp(-POINT_DATA_SIZE, iostream::end);
	fileOutBin.write(reinterpret_cast<const char*>(&newPoint), sizeof(Point));
	fileOutBin.close();

	ifstream fileInBin;
	fileInBin.open("point.bin", iostream::binary);
	Point pp[5];
	
	fileInBin.read(reinterpret_cast<char*>(pp), sizeof(Point) * 5);	

	
}