#include <iostream>
#include "CharLinkedList.hpp"

using namespace std;
using namespace ext;

CharNode* createLinkedList()
{
	CharNode* first = new CharNode{ 'H', nullptr };
	CharNode* second = new CharNode{ 'e', nullptr };
	CharNode* third = new CharNode{ 'l', nullptr };
	CharNode* forth = new CharNode{ 'l', nullptr };
	CharNode* fifth = new CharNode{ 'o', nullptr };

	first->nextNode = second;
	second->nextNode = third;
	third->nextNode = forth;
	forth->nextNode = fifth;

	return first;
}

CharNode* createLinkedList2()
{
	CharNode* first = new CharNode{ 'a', nullptr };
	CharNode* second = new CharNode{ 'b', nullptr };
	CharNode* third = new CharNode{ 'c', nullptr };

	first->nextNode = second;
	second->nextNode = third;

	return first;
}

CharNode* createLinkedList3()
{
	CharNode* first = new CharNode{ 'd', nullptr };
	CharNode* second = new CharNode{ 'e', nullptr };
	CharNode* third = new CharNode{ 'f', nullptr };

	first->nextNode = second;
	second->nextNode = third;

	return first;
}

CharNode* createLinkedList4()
{
	CharNode* first = new CharNode{ 'a', nullptr };
	CharNode* second = new CharNode{ 'b', nullptr };
	CharNode* third = new CharNode{ 'c', nullptr };
	CharNode* forth = new CharNode{ 'd', nullptr };
	CharNode* fith = new CharNode{ 'e', nullptr };
	CharNode* sixth = new CharNode{ 'f', nullptr };
	CharNode* seventh = new CharNode{ 'g', nullptr };

	first->nextNode = second;
	second->nextNode = third;
	third->nextNode = forth;
	forth->nextNode = fith;
	fith->nextNode = sixth;
	sixth->nextNode = seventh;

	return first;
}

void printLinkedList(CharNode* mainPtr)
{
	if (mainPtr == nullptr)
	{
		return;
	}
	CharNode* currentPtr = mainPtr;
	do
	{
		char currentChar = currentPtr->value;
		cout << currentChar;
		currentPtr = currentPtr->nextNode;
	} while (currentPtr != nullptr);
}

int main()
{
	CharNode* mainPtr = createLinkedList(); // Hello
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

	//append
	CharNode* mainPtr2 = createLinkedList();
	char symbol = '!';
	append(mainPtr2, symbol);
	printLinkedList(mainPtr2);
	cout << endl;

	//concatenate
	CharNode* Ptr1 = createLinkedList2();
	CharNode* Ptr2 = createLinkedList3();
	concatenate(Ptr1, Ptr2);
	printLinkedList(Ptr1);
	cout << endl;

	//substring
	CharNode* Ptr = createLinkedList4();
	CharNode* SubstringPtr = substring(Ptr, 3, 4);
	printLinkedList(SubstringPtr);
	cout << endl;
}