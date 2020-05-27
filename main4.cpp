#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Data
{
	static const int BUFFER_SIZE = 20;
	char Value[BUFFER_SIZE];	
};

const int DATA_SIZE = 3;

int main()
{
	//Data data = { 'h','e','l','l','o' }; // data.Value => "hello\0\0\0..."

	Data data[DATA_SIZE] = {
		{"Hello-world!"},
		{"And-hello-to-you!"},
		{"But-not-you"}
	};

	char stringToFind[Data::BUFFER_SIZE];
	cin >> stringToFind;
	cin.ignore(numeric_limits<int>::max(), '\n');

	Data * currentPtr = nullptr;
	for (int i = 0; i < DATA_SIZE; ++i)
	{
		/*	0 => если равны
			меньше нуля => если левая строка меньше правой (<)
			больше нуля => если левая строка больше правой (>)
		*/
		if (strcmp(data[i].Value, stringToFind) == 0) 
		{
			//Data temp = data[i]; // temp.Value = data[i].Value
			//data[i] = data[i + 1];
			//data[i + 1] = data[i];

			currentPtr = &data[i];
			break;
		}
	}

	if (currentPtr != nullptr)
	{
		cout << currentPtr->Value << endl;
	}	
}