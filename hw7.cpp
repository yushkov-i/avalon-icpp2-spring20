
#include <iostream>
#include "Header.h"
using namespace std;
using namespace ext;
using namespace impl;
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
	CharNode* first =createLinkedList();
	//cout << characterAt(first, 2);

	append(first, '1');

	cout << impl::getCharNodeAt(first, 5);
}

