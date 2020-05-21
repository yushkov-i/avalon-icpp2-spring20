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

CharNode * createLinkedList2()
{
	CharNode * first = new CharNode{ 'W', nullptr };
	CharNode * second = new CharNode{ 'o', nullptr };
	CharNode * third = new CharNode{ 'r', nullptr };
	CharNode * forth = new CharNode{ 'l', nullptr };
	CharNode * fifth = new CharNode{ 'd', nullptr };

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
	printLinkedList(mainPtr); // Hello
	cout << endl;
	
	//characterAt
	cout << characterAt(mainPtr, 2) << endl; // e
	cout << characterAt(mainPtr, 5) << endl; // o

	//append
	CharNode * secondPtr = createLinkedList();
	append(secondPtr, '!'); // Hello!
	printLinkedList(secondPtr); // Hello!
	cout << endl;

	//concatenate
	CharNode *str1 = createLinkedList();
	CharNode *str2 = createLinkedList2();
	concatenate(str1, str2); // HelloWorld
	printLinkedList(str1); // HelloWorld
	cout << endl;

	//subString
	CharNode *subStr = createLinkedList();
	subStr = substring(subStr, 2, 3); // ell
	printLinkedList(subStr); // ell
	cout << endl;

	//removeChars
	removeChars(mainPtr, 2, 2); // Hlo
	printLinkedList(mainPtr); // Hlo
	cout << endl;

	removeChars(mainPtr, 1, 2); // o
	printLinkedList(mainPtr); // o
	cout << endl;

}