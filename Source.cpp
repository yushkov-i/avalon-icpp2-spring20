#include <iostream>
#include "Header.h"
using namespace std;
enum Grade
{
	F = 1,   // ������
	D = 2,  // �������������������
	C = 3,  // �����������������
	B = 4,  // ������
	A = 5,  // �������      
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


	//cout << "��������� ���������, ������� 1 - ��� ���������� �� id, 2 - ��  mark, 3 -  �� Name"


	return 0;
}
