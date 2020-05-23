#include <iostream>
#include "Functions.hpp"

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
    //characterAt
	CharNode* characterAt_ptr = createLinkedList(); // Hello
	cout << "characterAt: " << endl <<characterAt(characterAt_ptr, 2) << endl; // e
	
	cout << endl << endl;

	//apend
	cout << "append: ";
	CharNode* append_ptr = createLinkedList();
	append(append_ptr, '!');
	printLinkedList(append_ptr);

	cout << endl << endl;

	//removeChars
	cout << "removeChars: ";
	CharNode* removeChars_ptr = createLinkedList();
	removeChars(removeChars_ptr, 2, 2); // Hlo
	printLinkedList(removeChars_ptr); // Hlo
	
	cout << endl << endl;

	//concatenate
	cout << "concatenate: ";
	CharNode* concatenate_ptr = createLinkedList();
	concatenate(concatenate_ptr, append_ptr);
	printLinkedList(concatenate_ptr);

	cout << endl << endl;

	//substring
	cout << "substring: ";
	CharNode* substring_ptr = createLinkedList();
	printLinkedList(substring(substring_ptr, 2, 3));
	
}
