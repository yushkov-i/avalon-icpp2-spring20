#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "rus");

	int znach = 0, isbn;
	bool valid;

	cout << "введете год ISBN: ";
	cin >> isbn;
	isbn = (isbn >= 2008) ? 13 : 10;
	char* uk = new char[isbn];
	cout << "введете ISBN: ";
	cin >> uk;

	if (isbn == 13)
	{
		for (int i = 0; i < 11; i += 2)
			znach += static_cast<int>(*(uk + i)) - 48;
		for (int i = 1; i <= 11; i += 2)
			znach += (static_cast<int>(*(uk + i)) - 48) * 3;
		valid = !((10 - znach % 10) - atoi(uk + isbn - 1));
	}
	else
	{
		for (int i = 0; i <= 8; i++)
			znach += (static_cast<int>(*(uk + i)) - 48)* (10 - i);
		valid = !((11 - znach % 11) - atoi(uk + isbn - 1));
	}

	if (valid) cout << "valid";
	else cout << "invalid";
	cout << endl;
	system("pause");
}