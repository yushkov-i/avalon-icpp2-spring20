#include <iostream>
#include "CharArray.hpp"

using namespace std;
using namespace ext;

int main()
{
	char * ptrStr = new char[6] {'H', 'e', 'l', 'l', 'o', '\0'};
	cout << ptrStr << endl;

	cout << characterAt(ptrStr, 2) << endl; // e
	cout << characterAt(ptrStr, 4) << endl; // l

	append(ptrStr, '!');
	cout << ptrStr << endl; // ptrStr = "Hello!"
	
	cout << impl::countLength(ptrStr) << endl; // 6
}
