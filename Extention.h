#pragma once

#include <iostream>
#include <limits>

namespace ext
{
	struct CharNode
	{
		char value;
		CharNode* nextNode;
	};

	namespace impl
	{
		CharNode* getCharNode(CharNode* mainPtr, int pos= INT_MAX)
		{
			CharNode* currentNode = mainPtr;
			for(int currentPos = 1; currentPos!= pos && currentNode->nextNode!=nullptr; ++currentPos)
			{
				currentNode = currentNode->nextNode;
			}
			return currentNode;
		}

		CharNode * newChar(char symbol, CharNode*nextNode=nullptr)
		{
			CharNode* newChar = new CharNode;
			newChar->value = symbol;
			newChar->nextNode = nextNode;
			return newChar;
		}
	}

	char characterAt(CharNode* mainPtr, int pos)
	{
		 return (impl::getCharNode(mainPtr, pos))->value;
	}

	void append(CharNode*& mainPtr, char symbol)
	{
		CharNode* lastChar = impl::newChar(symbol);
		
		(impl::getCharNode(mainPtr))->nextNode = lastChar;
	}


	void removeChars(CharNode*& mainPtr, int pos, int count)
	{
		CharNode* currentNode = impl::getCharNode(mainPtr, pos);
		CharNode* nextNode;

		for (int i = 1; i <= count; i++)
		{
			nextNode = currentNode->nextNode;
			delete[] currentNode;
			currentNode = nextNode;
		}

		(impl::getCharNode(mainPtr, pos - 1))->nextNode = currentNode;
	}

	void concatenate(CharNode* firstList, CharNode* secondList)
	{
		(impl::getCharNode(firstList))->nextNode = secondList;
	}

	CharNode* NewNode(int lenth, int n = 1)
	{
		if (lenth == n) return impl::newChar('\0', nullptr);
		return impl::newChar('\0', NewNode(lenth, n + 1));
	}

	CharNode* substring(CharNode* firstList, int pos, int length)
	{
		CharNode* newNode =  NewNode(length);
		CharNode* retnewNode = newNode;

		CharNode* currentNode = impl::getCharNode(firstList, pos);

		for (int i = 1; i <= length; i++)
		{
			newNode->value = currentNode->value;
			newNode = newNode->nextNode;
			currentNode = currentNode->nextNode;
		}

		return retnewNode;
	}
}