
#include "Extention.hpp";
using namespace std;
using namespace ext;

int main()
{
	setlocale(0, "rus");
	
	char* str1 = new char[100];
	char* str2 = new char[100];
	char* str3 = new char[100];
	int position, len;
	char symbol;

	cout << "¬вод позиции символа дл€ вывода"<<endl;
	cout << "строка: ";
	cin >> str1;
	cout << "позици€: ";
	cin >> position;
	cout <<characterAt(str1, position)<<endl;
	cout << endl;

	cout << "ƒобавление символа" << endl;
	cout << "строка: ";
	cin >> str1;
	cout << "символ: ";
	cin >> symbol;
	cout << append(str1, symbol)<<endl;
	cout << endl;

	cout << "ƒобавление одной сторки в другую" << endl;
	cout << "перва€ строка: ";
	cin >> str1;
	cout << "втора€ строка: ";
	cin >> str2;
	cout << concatenate(str1, str2)<<endl;
	cout << endl;

	cout << "¬ывод подстроки" << endl;
	cout << "оригинальна€ строка: ";
	cin >> str1;
	cout << "начальна€ позици€: ";
	cin >> position;
	cout << "длина подстроки: ";
	cin >> len;
	cout << substring(str1, position, 3) << endl;
	cout << endl;

	cout << "«амена подстроки" << endl;
	cout << "оригинальна€ строка: ";
	cin >> str1;
	cout << "искома€ строка: ";
	cin >> str2;
	cout << "замен€юща€ строка: ";
	cin >> str3;
	cout << replaceString(str1, str2, str3) << endl;

}