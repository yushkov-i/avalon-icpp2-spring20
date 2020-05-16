#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Point
{
	int x;
	int y;
};

struct Colour
{
	int id;
	string name;
};

int main()
{
	Point point;
	point.x; point.y;

	int data[5];
	Colour colourData[5];

	

	ifstream fileInput;
	fileInput.open("data.txt"); // open or create
	if (!fileInput.is_open())
	{
		cout << "data.txt file did not open!" << endl;
		return 1;
	}
	for (int i = 0; i < 5; ++i)
	{
		//fileInput >> colourData[i].id;
		//fileInput >> colourData[i].name;
		//fileInput.ignore(256, '\n');
		fileInput >> data[i];
		fileInput.ignore(std::numeric_limits<int>::max(), '\n');
	}

	fileInput.close();

	bool flag = fileInput.good();
	
	ofstream fileOutput;
	fileOutput.open("output.txt", iostream::app);
	if (!fileOutput.is_open())
	{
		cout << "output.txt file did not open!" << endl;
		return 2;
	}

	int num = 10;
	fileOutput << "Hello World!\n";
	fileOutput << num;
	flag = fileInput.good();
	fileOutput.flush();
	data[0]++;
	//fileOutput.flush();

//	int num;
//	fileInput >> num;
//	int * data = new int[num];

	string colour = "red";
	string filename = "triangle-" + colour + ".txt";
	ofstream file;
	file.open(filename);
}
