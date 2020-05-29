#include<iostream>
#include"Header.hpp"

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

CharNode* listForEdit()
{
	CharNode* first = new CharNode{ 'i', nullptr };
	CharNode* second = new CharNode{ 'n', nullptr };
	CharNode* third = new CharNode{ 'f', nullptr };
	CharNode* forth = new CharNode{ 'o', nullptr };
	CharNode* fifth = new CharNode{ 'r', nullptr };
	CharNode* sixth = new CharNode{ 'm', nullptr };

	first->nextNode = second;
	second->nextNode = third;
	third->nextNode = forth;
	forth->nextNode = fifth;
	fifth->nextNode = sixth;

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
	CharNode* mainPtr = createLinkedList();
	CharNode* editionalPtr = listForEdit();
	printLinkedList(mainPtr);
	cout << endl;

	cout << characterAt(mainPtr, 2) << endl; 
	cout << characterAt(mainPtr, 5) << endl;

	removeChars(mainPtr, 2, 2); 
	printLinkedList(mainPtr); 
	cout << endl;

	append(mainPtr, '4'); 
	printLinkedList(mainPtr); //hlo4
	cout << endl;

	concatenate(mainPtr, editionalPtr);
	printLinkedList(mainPtr); //hlo4inform
	cout << endl;

	CharNode*ptr = substring(editionalPtr, 2, 3);//nfo
	printLinkedList(ptr);
	cout << endl;
	
}
