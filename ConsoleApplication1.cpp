
#include <iostream>
#include<limits>
using namespace std;
int main()
{
	setlocale(0, "");
	int c,b=2,v;
		long long int a;
		cout << ("Какой ISBN будете использовать") << endl << ("1.ISBN-13") << endl << ("2.ISBN-10")<<endl;
			cin >> c;
			cout << ("Вводите ISBN") << endl;
				cin >> a;
				v = a % 10;
				a = (a - a % 10) / 10;
				if (c == 1) {
					c = 0;
					if (a > 100000000000 && a < 1000000000000) {
						while (true) {
							if (b == 1) { c = c + a % 10; b = 2; }
							else if (b == 2) { c = c + a % 10 * 3; b = 1; }
							a = (a - a % 10) / 10;
							if (a == 0)break;
						}
						if ((v + c) % 10 == 0)cout << ("ISBN-13 действительный")<<endl;
						else cout << ("ISBN-13 не действительный") << endl;
					}
					else cout << ("ISBN-13 не действительный")<<endl;
				}
				else {
					c = 0;
					if (a > 10000000){
					while (true) {
					 c = c + a % 10 * b;++b; 
						a = (a - a % 10) / 10;
						if (a == 0)break;
					}
					if ((v + c) % 11 == 0)cout << ("ISBN-10 действительный")<<endl;
					else cout << ("ISBN-10 не действительный")<<endl;
					}
					else cout << ("ISBN-10 не действительный") << endl;
				}
				system("pause");
				return 0;
}