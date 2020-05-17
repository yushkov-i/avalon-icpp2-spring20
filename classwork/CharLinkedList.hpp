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

	void append(CharNode * & mainPtr, char symbol);

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

	void concatenate(CharNode * firstList, CharNode * secondList);

	CharNode * substring(CharNode * firstList, int pos, int length);
}