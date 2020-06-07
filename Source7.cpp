#include <iostream>

using namespace std;
namespace ext
{
	struct CharNode
	{
		char value;
		CharNode* nextNode;
	};

	namespace impl
	{
		CharNode* getCharNodeAt(CharNode* mP, int p)
		{
			int cP = 1;
			CharNode* cN = mP;
			while (cP < p)
			{
				cN = cN->nextNode;
				++cP;
			}

			return cN;
		}
	}

	char characterAt(CharNode* mP, int p)
	{
		CharNode* c = impl::getCharNodeAt(mP, p);
		return c->value;
	}

	void append(CharNode*& mP, char sl)
	{
		CharNode* Ptr = mP;
		CharNode* End_Part = new CharNode{ sl,nullptr };

		while (Ptr->nextNode != nullptr)
			Ptr = Ptr->nextNode;

		Ptr->nextNode = End_Part;
	}

	void removeChars(CharNode*& mP, int p, int c)
	{
		if (p == 1)
		{
			removeChars(mP, 2, c - 1);
			CharNode* a = mP;
			mP = mP->nextNode;
			delete a;
			return;
		}

		CharNode* predNode = impl::getCharNodeAt(mP, p - 1);

		int deleteCount = 0;

		while (deleteCount != c)
		{
			CharNode* nodeToDelete = predNode->nextNode;
			predNode->nextNode = nodeToDelete->nextNode;
			delete nodeToDelete;
			++deleteCount;
		}
	}

	void concatenate(CharNode* fL, CharNode* sL)
	{
		while (fL->nextNode != nullptr) {
			fL = fL->nextNode;
		}
		fL->nextNode = sL;
	}

	CharNode* substring(CharNode* fL, int p, int l)
	{
		CharNode* flc = fL;

		for (int i = 1; i < p; i++)
		{
			flc = flc->nextNode;
		}

		CharNode* sl = new CharNode{ flc->value , flc->nextNode };
		flc = sl;

		for (int i = 1; i < l; ++i)
		{
			flc = flc->nextNode;
		}

		flc->nextNode = nullptr;

		return sl;
	}
}
using namespace ext;
CharNode* createLinkedList()
{
	CharNode* f1 = new CharNode{ 'H', nullptr };
	CharNode* f2 = new CharNode{ 'e', nullptr };
	CharNode* f3 = new CharNode{ 'l', nullptr };
	CharNode* f4 = new CharNode{ 'l', nullptr };
	CharNode* f5 = new CharNode{ 'o', nullptr };

	f1->nextNode = f2;
	f2->nextNode = f3;
	f3->nextNode = f4;
	f4->nextNode = f5;

	return f1;
}

void printLinkedList(CharNode* mP)
{
	if (mP == nullptr)
	{
		return;
	}
	CharNode* cP = mP;
	do
	{
		char cC = cP->value;
		cout << cC;
		cP = cP->nextNode;
	} while (cP != nullptr);
}

int main()
{
	//characterAt
	CharNode* characterAt_ptr = createLinkedList(); 
	cout << "characterAt: " << characterAt(characterAt_ptr, 2) << endl<<endl; 

	//apend
	cout << "append: ";
	CharNode* append_ptr = createLinkedList();
	append(append_ptr, '!');
	printLinkedList(append_ptr);

	cout << endl << endl;

	//removeChars
	cout << "removeChars: ";
	CharNode* removeChars_ptr = createLinkedList();
	removeChars(removeChars_ptr, 2, 2); 
	printLinkedList(removeChars_ptr); 

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