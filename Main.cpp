#include<iostream>
#include"Header.hpp"

using namespace std;
using namespace ext;
int main()
{
	char b = '&';

	char * str1 = new char[6]{'H','e','l','l','o','\0'};

	char * str2 = new char[7]{'p','r','i','v','e','t','\0'};

	char* str3 = new char[17]{ 'l','o','o','k','i','n','g',' ','f','o','r',' ','y','o','u','.','\0' };

	cout << append(str1, b) << endl;

	cout << concatenate(str1, str2) << endl;
	
	cout << substring(str3, 3, 7) << endl;
}
