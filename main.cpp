#include <iostream>
#include "CharArray.hpp"
using namespace std;
using namespace ext;

int main()
{
	char* data = new char[6]{ 'h','e','l','l','o','\0' };
	char symbol = '!';

	char* newData = append(data, symbol); // "hello!"
	char* newnewData = append(newData, 'c');
	cout << newnewData << endl; // "hello!c"

	cout << characterAt(data, 2) << endl; // 'e'

	char* dataBad = new char{ '\0' };
	char* newDataBad = append(dataBad, '!');
	cout << newDataBad << endl;

	//concatenate
	char* data1 = new char[4]{ 'a', 'b','c', '\0' };
	char* data2 = new char[4]{ 'd', 'e','f', '\0' };
	char* newData1 = concatenate(data1, data2);
	cout << newData1 << endl;

	//substring
	char* data3 = new char[8]{ 'a','b','c','d','e','f','g', '\0' };
	char* newData2 = substring(data3, 3, 4);
	cout << newData2 << endl;

	//replaceString
	char* data4 = new char[9]{ 'a','b','c','d', 'a','b','e','e','\0'};
	char* targetString = new char[3]{ 'a','b','\0' };
	char* replacementText = new char[4]{ 'x','y','z','\0' };
	char* newData3 = replaceString(data4, targetString, replacementText);
	cout << newData3 << endl;
}