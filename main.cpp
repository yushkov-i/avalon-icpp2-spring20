#include <iostream>
#include "Header.hpp"

using namespace std;
using namespace ext;

int main() {
	setlocale(LC_ALL, "Rus");
	char x;
	Node* first = new Node{ 'h' };
	Node* second = new Node{ 'e' };
	first->Next = second;
	Node* third = new Node{ 'l' };
	second->Next = third;
	Node* fourth = new Node{ 'l' };
	third->Next = fourth;
	Node* fifth = new Node{ 'o' };
	fourth->Next = fifth;
	fifth->Next = nullptr;
	int num, count{};
	cout << "Введите номер символа, который хотите получить из строки: ";
	cin >> num;
	cout << "Символ под номером " << num << ": " << characterAt(first, num) << endl;
	cout << "Введите символ, который хотите добавить в конец строки: ";
	cin >> x;
	cout << "Готовая строка: \"";
	Node* sixth = append(first, x);
	fifth->Next = sixth;
	sixth->Next = nullptr;
	Node* tmp = first;
	while (tmp != nullptr) {
		cout << tmp->symb;
		tmp = tmp->Next;
	}
	cout << "\"" << endl;
}
