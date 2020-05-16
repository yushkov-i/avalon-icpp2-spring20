#include <iostream>
#include "Node.hpp"

using namespace std;
using namespace ext;

int main()
{
	// Hell
	Node * n1 = new Node{ 'H', nullptr };
	Node * n2 = new Node{ 'e', nullptr };
	Node * n3 = new Node{ 'l', nullptr };
	Node * n4 = new Node{ 'l', nullptr };

	Node * firstList = n1;
	n1->nextNode = n2;
	n2->nextNode = n3;
	n3->nextNode = n4;

	cout << characterAt(firstList, 2) << endl; // e
	cout << characterAt(firstList, 4) << endl; // l

	append(firstList, 'o'); // mainPtr должен указывать на коллекцию Hello

	cout << firstList << endl;

	print(firstList); // Hello

	removeChars(firstList, 3, 2); // Heo


	Node * nn1 = new Node{ 'm', nullptr };
	Node * nn2 = new Node{ 'e', nullptr };
	Node * secondList = nn1;
	nn1->nextNode = nn2;

	concatenate(firstList, secondList); // firstList это 'Heome'

	Node * substr = substring(firstList, 3, 2);
}