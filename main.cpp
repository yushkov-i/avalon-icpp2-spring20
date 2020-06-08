
#include "Extention.h"
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

	cout << endl;
}

int main()
{
	CharNode* mainNode = createLinkedList();
	CharNode* mainNode_ = createLinkedList();

	printLinkedList(mainNode);

	cout << characterAt(mainNode, 2)<<endl;
	
	append(mainNode, '!');
	printLinkedList(mainNode);

	removeChars(mainNode, 2, 3);
	printLinkedList(mainNode);

	concatenate(mainNode, mainNode_);
	printLinkedList(mainNode);

	mainNode_ = substring(mainNode_, 2, 3);
	printLinkedList(mainNode_);
}