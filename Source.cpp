
#include "NodeChar.h"
#include <iostream>
using namespace std;
using namespace ext;

struct Student {
	int id;
	int grade;

};
//struct Node {
//	Student Student;
//	Node * nextNode;
//};


int main() {
	//Hell
	Node * n1 = new Node{ 'H', nullptr };
	Node * n2 = new Node{ 'e', nullptr };
	Node * n3 = new Node{ 'l', nullptr };
	Node * n4 = new Node{ 'l', nullptr };
	Node * FirstList = n1;
	n1->nextNode = n2;
	n2->nextNode = n3;
	n3->nextNode = n4;
	cout << characterAt(FirstList, 2) << endl;

	append(FirstList, 'o');
	print(FirstList); // hello
	cout << endl;
	removeChar(FirstList, 3, 2); 
	print(FirstList);//heo
	cout  << endl;
	Node * nn1 = new Node{ 'W', nullptr };
	Node * nn2 = new Node{ 'o', nullptr };
	Node * nn3 = new Node{ 'r', nullptr };
	Node * nn4 = new Node{ 'l', nullptr };
	Node * nn5 = new Node{ 'd', nullptr };
	Node * mainPtr = nn1;
	nn1->nextNode = nn2;
	nn2->nextNode = nn3;
	nn3->nextNode = nn4;
	nn4->nextNode = nn5;
	concatenate(FirstList, mainPtr);
	print(FirstList); //heoWorld
	cout << endl;
	Node * subStr = substring(FirstList, 3,4);//oWor
	print(subStr);
}