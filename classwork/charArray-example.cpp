#include <iostream>
#include "CharArray.hpp"
//using namespace std;
using namespace std;
using namespace ext;

int main()
{
	char * data = new char[6]{ 'h','e','l','l','o','\0' };
	char symbol = '!';

	char * newData = append(data, symbol); // "hello!"
	char * newnewData = append(newData, 'c');
	cout << newnewData << endl; // "hello!c"
	
	cout << characterAt(data, 2) << endl; // 'e'

	char * dataBad = new char{'\0'};
	char * newDataBad = append(dataBad, '!');

	cout << newDataBad << endl;

	delete[] data;
	delete[] newData;
	delete[] newnewData;
	delete[] dataBad;
	delete[] newDataBad;
}
