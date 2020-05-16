#include <iostream>
using namespace std;

struct Student
{
	int id;
	int grade;
};

struct Node
{
	Student student;
	Node * nextNode;
	Node * prevNode;
};

void print(const Student& local)
{
	cout << "Id = " << local.id << "; " 
		<< "Grade = " << local.grade << endl;
}

Node * addToList(Node * oldNode, Student st)
{
	Node * newNode = new Node{ st, nullptr };

	newNode->nextNode = oldNode;

	return newNode;
}

Node * createList(Student data[], int size)
{
	Node * node = new Node{ data[0], nullptr };
	
	for (int i = 1; i < size; i++)
	{
		node = addToList(node, data[i]);
	}

	return node;
}

int main()
{
	Student students[3] =
		{ Student{ 2,4 },Student{ 3,5 },Student{ 4,3 } };
	
	Node * mainPtr = createList(students, 3);

	// для вывода
	Node * currentPtr = mainPtr;
	
	do
	{
		print(currentPtr->student);
		currentPtr = currentPtr->nextNode;
	} while (currentPtr != nullptr);
}