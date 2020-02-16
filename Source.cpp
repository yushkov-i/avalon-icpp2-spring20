#include <iostream>
#include "Header.h"
using namespace std;
enum Grade
{
	F = 1,   // неявка
	D = 2,  // неудовлетворительно
	C = 3,  // удовлетворительно
	B = 4,  // хорошо
	A = 5,  // отлично      
};

struct Student
{
	int Id;
	Grade Mark;
	char Name[7];
};
int main() {
	Student students[100];
	for (int i = 0; i < 100; i++) {
		students[i].Id = ext::GetRandomValue(1, 1000);
		students[i].Mark = static_cast<Grade>(ext::GetRandomValue(1, 5));
		int length = ext::GetRandomValue(3, 6);
		for (int j = 0; j < length; j++) {
			students[i].Name[j] = ext::GetRandomValue('a', 'z');
		}
	}


	cout << "Сортровка студентов, введите 1 - для сортировки по id, 2 - по  mark, 3 -  по Name"


	return 0;
}
