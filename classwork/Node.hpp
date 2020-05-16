#pragma once
#include <iostream>

namespace ext
{
	struct Node
	{
		char symbol;
		Node * nextNode;
	};

	char characterAt(Node * mainNode, int index)
	{
		Node * currentNode = mainNode;
		int count = 1;
		while (count < index)
		{
			currentNode = currentNode->nextNode;
			++count;
		}

		return currentNode->symbol;
	}

	void append(Node * mainNode, char symbol)
	{
		Node * newNode = new Node{ symbol, nullptr };

		Node * currentNode = mainNode;
		while (currentNode->nextNode != nullptr)
		{
			currentNode = currentNode->nextNode;
		}

		currentNode->nextNode = newNode;
	}

	void print(Node * mainNode)
	{
		Node * currentPtr = mainNode;

		do
		{
			std::cout << currentPtr->symbol;
			currentPtr = currentPtr->nextNode;
		} while (currentPtr != nullptr);
	}

	void removeChars(Node * mainNode, int index, int count)
	{

	}

	void concatenate(Node * firstNode, Node * secondNode)
	{

	}

	Node * substring(Node * str, int pos, int length)
	{
		return nullptr;
	}
}