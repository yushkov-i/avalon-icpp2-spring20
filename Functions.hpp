#pragma once
#pragma once

namespace ext
{
	struct CharNode
	{
		char value;
		CharNode* nextNode;
	};

	namespace impl
	{
		CharNode* getCharNodeAt(CharNode* mainPtr, int pos)
		{
			int currentPos = 1;
			CharNode* currentNode = mainPtr;
			while (currentPos < pos)
			{
				currentNode = currentNode->nextNode;
				++currentPos;
			}

			return currentNode;
		}
	}

	char characterAt(CharNode* mainPtr, int pos)
	{
		CharNode* charNodeAt = impl::getCharNodeAt(mainPtr, pos);
		return charNodeAt->value;
	}

	void append(CharNode*& mainPtr, char symbol)
	{
		CharNode* Ptr = mainPtr;
		CharNode* End_Part = new CharNode{ symbol,nullptr };

		while (Ptr->nextNode != nullptr)
			Ptr = Ptr->nextNode;

	   Ptr->nextNode = End_Part;
	}

	void removeChars(CharNode*& mainPtr, int pos, int count)
	{
		if (pos == 1)
		{
			removeChars(mainPtr, 2, count - 1);
			CharNode* temp = mainPtr;
			mainPtr = mainPtr->nextNode;
			delete temp;
			return;
		}

		CharNode* predNode = impl::getCharNodeAt(mainPtr, pos - 1);

		int deleteCount = 0;

		while (deleteCount != count)
		{
			CharNode* nodeToDelete = predNode->nextNode;
			predNode->nextNode = nodeToDelete->nextNode;
			delete nodeToDelete;
			++deleteCount;
		}
	}

	void concatenate(CharNode* firstList, CharNode* secondList)
	{
		while (firstList->nextNode != nullptr) {
			firstList = firstList->nextNode;
		}
		firstList->nextNode = secondList;
	}

	CharNode* substring(CharNode* firstList, int pos, int length)
	{
		CharNode* first_list_copy = firstList;
		
		for (int i = 1; i < pos; i++)
		{
			first_list_copy = first_list_copy->nextNode;
		}

		CharNode* second_list = new CharNode{ first_list_copy->value , first_list_copy->nextNode };
		first_list_copy = second_list;

		for (int i = 1; i < length; ++i)
		{
			first_list_copy = first_list_copy->nextNode;
		}

		first_list_copy->nextNode = nullptr;

		return second_list;
	}
}
