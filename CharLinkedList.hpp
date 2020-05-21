#pragma once

namespace ext
{
	struct CharNode
	{
		char value;
		CharNode * nextNode;
	};

	namespace impl
	{
		CharNode * getCharNodeAt(CharNode * mainPtr, int pos)
		{
			int currentPos = 1;
			CharNode * currentNode = mainPtr;
			while (currentPos < pos)
			{
				currentNode = currentNode->nextNode;
				++currentPos;
			}

			return currentNode;
		}
	}

	char characterAt(CharNode * mainPtr, int pos)
	{
		CharNode * charNodeAt = impl::getCharNodeAt(mainPtr, pos);
		return charNodeAt->value;
	}

	void append(CharNode * & mainPtr, char symbol) {
		CharNode* Node = mainPtr;
		CharNode* EndNode = new CharNode{ symbol, nullptr };
		while (Node->nextNode != nullptr)
		{
			Node = Node->nextNode;
		}
		Node->nextNode = EndNode;
	}

	void removeChars(CharNode * & mainPtr, int pos, int count)
	{
		if (pos == 1)
		{
			removeChars(mainPtr, 2, count - 1);
			CharNode * temp = mainPtr;
			mainPtr = mainPtr->nextNode;
			delete temp;
			return;
		}

		CharNode * predNode = impl::getCharNodeAt(mainPtr, pos - 1);

		int deleteCount = 0;

		while (deleteCount != count)
		{
			CharNode * nodeToDelete = predNode->nextNode;
			predNode->nextNode = nodeToDelete->nextNode;
			delete nodeToDelete;
			++deleteCount;
		}
	}

	void concatenate(CharNode * firstList, CharNode * secondList) {
		while (firstList->nextNode != nullptr) {
			firstList = firstList->nextNode;
		}
		firstList->nextNode = secondList;
	}

	CharNode * substring(CharNode * firstList, int pos, int length) {
		for (int i = 1; i < pos; ++i) {
			firstList = firstList->nextNode;
		}
		CharNode *finList = new CharNode{ firstList->value, firstList->nextNode };
		firstList = finList;
		for (int i = 1; i < length; ++i) {
			firstList = firstList->nextNode;
		}
		firstList->nextNode = nullptr;
		return finList;
	}
}
