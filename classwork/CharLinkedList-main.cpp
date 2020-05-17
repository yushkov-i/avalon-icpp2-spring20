#include <iostream>
#include "CharLinkedList.hpp"

using namespace std;
using namespace ext;

CharNode * createLinkedList()
{
	CharNode * first = new CharNode{ 'H', nullptr };
	CharNode * second = new CharNode{ 'e', nullptr };
	CharNode * third = new CharNode{ 'l', nullptr };
	CharNode * forth = new CharNode{ 'l', nullptr };
	CharNode * fifth = new CharNode{ 'o', nullptr };

	first->nextNode = second;
	second->nextNode = third;
	third->nextNode = forth;
	forth->nextNode = fifth;

	return first;
}

void printLinkedList(CharNode * mainPtr)
{
	if (mainPtr == nullptr)
	{
		return;
	}
	CharNode * currentPtr = mainPtr;
	do
	{
		char currentChar = currentPtr->value;
		cout << currentChar;
		currentPtr = currentPtr->nextNode;
	} while (currentPtr != nullptr);
}

int main()
{
	CharNode * mainPtr = createLinkedList(); // Hello
	printLinkedList(mainPtr);
	cout << endl;

	cout << characterAt(mainPtr, 2) << endl; // e
	cout << characterAt(mainPtr, 5) << endl; // o

	removeChars(mainPtr, 2, 2); // Hlo
	printLinkedList(mainPtr); // Hlo
	cout << endl;

	removeChars(mainPtr, 1, 2); // o
	printLinkedList(mainPtr); // o
	cout << endl;
}