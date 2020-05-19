#include <iostream>
#include "Extention.hpp"
using namespace ext;
using namespace std;

char characterAt(char * pos, int n) {
	return pos[n - 1];
}

char *append(char* str, char symb) {
	int size = (sizeof(str) / sizeof(char)) + 2;
	char *temp = new char[size + 1];
	for (int i = 0; i < size + 1; ++i) {
		temp[i] = str[i];
	}
	temp[size - 1] = symb;
	temp[size] = '\0';
	return temp;
	delete temp;
}

char *concatenate(char *str1, char *str2) {
	int size1 = (sizeof(str1) / sizeof(char)) + 2, size2 = (sizeof(str2) / sizeof(char)) + 1;
	char *strFin = new char[size1 + size2];
	for (int i = 0; i < size1 - 1; ++i) {
		strFin[i] = str1[i];
	}
	for (int i = size1 - 1; i < size1 + size2 - 1; ++i) {
		strFin[i] = str2[i - size1 + 1];
	}
	strFin[size1 + size2 - 1] = '\0';
	return strFin;
	delete strFin;
}

char *substring(char *str, int start, int lenght) {
	char *str2 = new char[lenght - 1];
	int count = 0, ii = start - 1;
	for (int i = start - 1; i <  ii + lenght; ++i) {
		str2[count] = str[i];
		++count;
	}
	str2[lenght] = '\0';
	return str2;
	delete str2;
}

/*char *replacestring(char *str, char targ, char change[]) {
	int size1 = (sizeof(str) / sizeof(char)) + 1, temp = 0;
	char *tempChar = new char, null[] = "";
	for (int i = 0; i < size1; ++i) {
		if (str[i] == targ) {
			temp = i;
			for (int j = i; j < size1; ++j) {
				tempChar[j] = str[j];
				str[j] = null;
			}
			break;
		}
	}
	for (int i = temp; i < size1; ++i) {
		if (str[i] == targ) {
			temp = i;
			str[i] = *change;
			size1 = size1 + (sizeof(change) / sizeof(char));
			break;
		}
	}
	str[size1 - 1] = '\0';
	return str;
	delete str;
}*/

int main() {
	char *str = new char[5]{ 'H', 'e', 'l', 'l', 'o'};
	cout << "characterAt: " << characterAt(str, 5) << endl;

	char symbol = '!';
	char *temp = append(str, symbol);
	cout << "append: " << temp << endl;

	char *str2 = new char[5]{ 'W', 'o', 'r', 'l', 'd' };
	temp = concatenate(str, str2);
	cout << "concatenate: " << temp << endl;

	temp = substring(str2, 2, 2);
	cout << "substring: " << temp << endl;

	//char ho[] = "ho";
	//temp = replacestring(str, 'l', ho);
	//cout << "replaceString: " << temp << endl;
	delete str;
	delete str2;
	delete temp;
}