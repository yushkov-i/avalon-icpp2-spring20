#include <iostream>
#include "CharArray.hpp"

using namespace std;
using namespace ext;

int main()
{
	char* string = new char[6]{ 'H','e','l','l','o', '\0' };
	char sign = '!';

	cout << "characterAt: " << characterAt(string, 2) << endl;
		
    char* newString = append(string, sign);
	cout << "append: " << newString << endl;

	char* addedString = concatenate(string, newString);
	cout << "concatenate: " << addedString << endl;

	
	char* croppedString = substring(string, 2, 4);
	cout  << croppedString << endl;

	char* replace_string = new char[9] {'a', 'b', 'c', 'd', 'a', 'b', 'c', 'd', '\0'};
	
	char* one = new char[3]{ 'b', 'c','\0' };
	char* two = new char[2]{ 'o', '\0' };
    
	cout << "replacestrng: " << endl;
	char* new_string = replacestring(replace_string, one, two);
	cout << "input: " << replace_string<<endl;
	cout << "result: " << new_string<<endl;
}
