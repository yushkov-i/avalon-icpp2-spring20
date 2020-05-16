#pragma once
#include <iostream>
namespace ext
{
	struct Node
	{
		char symbol;
		Node * nextNode;
	};
	char characterAt(Node * mainNode, int index) {
		Node * currentNode = mainNode;
		int count = 1;
		while(count < index){
			currentNode = currentNode->nextNode;
			count++;
		}
		return currentNode->symbol;
	}

	void append(Node * mainNode, char symbol) {
		Node * newNode = new Node{ symbol, nullptr };
		Node * currentNode = mainNode;
		while (currentNode->nextNode != nullptr) {
			currentNode = currentNode->nextNode;
		}
		currentNode->nextNode = newNode;
	}
	
	void print(Node * mainNode) {
		Node * currentPtr = mainNode;
		do {
			std::cout << currentPtr->symbol;
			currentPtr = currentPtr->nextNode;
		} while (currentPtr != nullptr);
	}

	void removeChar(Node * mainNode, int index, int count) {//////////////////////
		int LocaleCount = 1;
		Node * currentNode = mainNode;
		Node * Save_currentNode = mainNode;
		if (index != 1) {
			while (LocaleCount < index - 1) {
				currentNode = currentNode->nextNode;
				LocaleCount++;
			}
			Save_currentNode = currentNode->nextNode;
			for (int i = 1; i < count; i++) {
				Save_currentNode = Save_currentNode->nextNode;
			}
			currentNode->nextNode = Save_currentNode->nextNode;
		}
		else {
			for (int i = 0; i < count; i++) {
				currentNode = currentNode->nextNode;
			}
			mainNode->nextNode = currentNode->nextNode;
			mainNode->symbol = currentNode->symbol;
		}
	}
	void concatenate(Node * FirstNode, Node* SecondNode) {
		while (FirstNode->nextNode != nullptr) {
			FirstNode = FirstNode->nextNode;
		}
		FirstNode->nextNode = SecondNode;
	}

	Node * substring(Node * str, int pos, int length) {
		Node * currentNode = str;
		for (int i = 1; i < pos; i++) {
			currentNode = currentNode->nextNode;
		}
		Node * newNode = new Node{ currentNode->symbol, currentNode->nextNode };
		currentNode = newNode;
		for (int i = 1; i < length; i++) {
			currentNode = currentNode->nextNode;
		}
		currentNode->nextNode = nullptr;
		return newNode;
	}
}