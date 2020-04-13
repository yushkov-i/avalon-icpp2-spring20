#include <iostream>
#include "ex1(hpp).h"
using namespace std;
using namespace ext;

int main() {
	//append
	char *data = new char[6]{ 'h','e','l','l','o', '\0' };
	char symbol = '!';
	char * newData = append(data, symbol);
	cout << newData << endl; // "hello!"
	char * dataBad = new char{ '\0' };
	char * newDataBad = append(dataBad, symbol);
	cout << newDataBad << endl;
	cout << characterAt(data, 2) << endl; // 'e'
	//concatenate 
	char *data_con1 = new char[7]{ 'h','e','l','l','o', ' ', '\0' };
	char *data_con2 = new char[6]{ 'g','r','e','a','t', '\0' };
	char *data_con3 = concatenate(data_con1, data_con2);
	cout << data_con3 << endl;
	//substring
	char *data_substring = new char[12]{ 'h','e','l','l','o', ' ', 'W','o','r','l','d', '\0' };
	int first = 3;
	int length = 5;
	char * newData_substring = substring(data_substring, first, length);
	cout << newData_substring << endl;
	//replaceString 
	char *data_rep_main = new char[9]{ 'h','b','c','d','g', 'b', 'c', 'd','\0' };
	char *data_rep_find = new char[4]{ 'b', 'c', 'd', '\0' };
	char *data_rep_change = new char[3]{ 'e','a', '\0' };
	char * newData_replaceString = replaceString(data_rep_main, data_rep_find, data_rep_change);
	cout << newData_replaceString << endl;

	delete[] data;
	delete[] newData;
	delete[] dataBad;
	delete[] newDataBad;
	delete[] data_con1;
	delete[] data_con2;
	delete[] data_con3;
	delete[] data_substring;
	delete[] data_rep_main;
	delete[] data_rep_find;
	delete[] data_rep_change;
	delete[] newData_replaceString;

}
