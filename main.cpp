#include <iostream>
using namespace std;

enum Grade
{
	F = 1,   // неявка
	D = 2,  // неудовлетворительно
	C = 3,  // удовлетворительно
	B = 4,  // хорошо
	A = 5,  // отлично      
};
int main()
{
	Grade mark = Grade::B;
	cout << mark << endl;
	int temp;
	cin >> temp;
	mark = static_cast<Grade> (temp);
}