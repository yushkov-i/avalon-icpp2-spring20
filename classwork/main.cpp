#include <vector>

using namespace std;

struct Student
{
	int id;
	int grade;
};

struct Vector
{
	Student * ptr; // 0x80
	int size; // 4
	int capacity; // 4
};

int main()
{
	Vector data{ 0x80, 4,4 };
	Student student{ 5, 4 };

	if (data.size + 1 < data.capacity)
	{
		Student * newPtr = new Student[data.size * 2];
		for (int i = 0; i < data.size; ++i)
		{
			newPtr[i] = data.ptr[i];
		}
	}
	
	newPtr[data.size] = student;
	delete[] data.ptr;

	data.ptr = newPtr;
	data.size = data.size + 1;
	data.capacity = data.capacity * 2;

	vector<Student> data2 = { {1,3},{2,4},{3,5},{4,5} };
	data2.push_back(student); // size = 8
	
}