#include <iostream>
#include "Extention.hpp"
using namespace std;
using namespace ext;
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
	Student student;
	student.Id = GetRandomValue(1, 1000);
	student.Mark = static_cast<Grade>(GetRandomValue(1,5));
	int length = GetRandomValue(3, 6);
	for (int i = 0; i < length; i++)
	{
		student.Name[i] = GetRandomValue('a', 'z');
	}
	student.Name[length] = '\0';
}
