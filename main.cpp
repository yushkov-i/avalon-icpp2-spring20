#include <iostream>
#include "CharArray.hpp"
using namespace std;
using namespace ext;
int main() {
	char* data = new char[6]{ 'h','e','l','l','o','\0' };
	char* data2 = new char[7]{ ' ','w','o','r','l','d','\0' };
	char symbol = '!';


	char* newData = append(data, symbol); // "hello!"	
	cout << newData << endl; 
	delete[] newData;

	cout << characterAt(data, 2) << endl; // 'e'


	char* dataBad = new char{ '\0' };
	char* newDataBad = append(dataBad, '!'); 
	cout << newDataBad << endl;			// '!'
	delete[] dataBad;
	delete[] newDataBad;


	char* newData2 = concatenate(data, data2); 
	cout << newData2 << endl;		// "hello world"
	delete[] newData2;

	char* newData3 = substring(data2, 3, 3);
	cout << newData3 << endl;		// "orl"
	
	char* data5 = new char[9]{ 'v','b','e','l','e','l','e','n','\0' };
	char* data3 = new char[3]{ 'e','l','\0' };
	char* data4 = new char[4]{ 'b','o','t' ,'\0' };
	char* newData4 = replaceString(data5, data3, data4);	// "vbBOTBOTen"
	cout << newData4 << endl;
	delete[] data;
	delete[] data2;

	delete[] data3;
	delete[] data4;
	delete[] data5;

	/*delete[] newData3;
	delete[] newData4;*/
	
	
	
}