#include <iostream>
#include <fstream>

using namespace std;

struct Data
{
	static const int BUFFER_SIZE = 20;
	//char Value[BUFFER_SIZE];
	int Length;
	char * Value;
};

const int DATA_SIZE = 3;

int main()
{
	//Data data = { 'h','e','l','l','o' }; // data.Value => "hello/0/0/0/0/0/0/0/0..."

	Data data[DATA_SIZE] = {
		13, new char[13] {"Hello world!"},
		18, new char[18] {"And hello to you!"},
		12, new char[12] {"But not you"}
	};

	fstream fileOut;
	fileOut.open("filename.bin", iostream::out | iostream::binary);

	for (int i = 0; i < DATA_SIZE; ++i)
	{
		fileOut.write(reinterpret_cast<char*>(&data[i].Length), sizeof(int));
		fileOut.write(reinterpret_cast<char*>(data[i].Value), strlen(data[i].Value) + 1);
	}

	fileOut.close();

	for (int i = 0; i < DATA_SIZE; ++i)
	{
		delete[] data[i].Value;
	}

	Data inputData[DATA_SIZE];
	fstream fileIn;
	fileIn.open("filename.bin", iostream::in | iostream::binary);

	for (int i = 0; i < DATA_SIZE; ++i)
	{
		fileIn.read(reinterpret_cast<char*>(&inputData[i].Length), sizeof(int));
		inputData[i].Value = new char[inputData[i].Length];
		fileIn.read(reinterpret_cast<char*>(inputData[i].Value), inputData[i].Length);
	}
	
	fileIn.close();
}