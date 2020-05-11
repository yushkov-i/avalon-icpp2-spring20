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
	fifth->Next = nullptr;
	delete sixth;
	cout << "Строка без исключённых символов: " << removeChars(first, 2, 3);
	cout << "Введите через пробел размеры двух строк: ";
	int m, n;
	cin >> n >> m;
	char* cust_str1 = new char[n];
	char* cust_str2 = new char[m];
	cout << "Введите две строки через клавишу Enter: ";
	cin >> cust_str1;
	cin >> cust_str2;
	NodeDoub* cust1 = new NodeDoub[n];
	NodeDoub* cust2 = new NodeDoub[m];
	for (int i = 0; i < n; i++) {
		cust1[i].symb = cust_str1[i];
		if (i != n - 1) {
			cust1[i].Next = &cust1[i + 1];
			cust1[i].Next->Prev = &cust1[i];
		}
		else {
			cust1[i].Next = nullptr;
		}
	}
	for (int i = 0; i < m; i++) {
		cust2[i].symb = cust_str2[i];
		if (i != m - 1) {
			cust2[i].Next = &cust2[i + 1];
			cust2[i].Next->Prev = &cust2[i];
		}
		else {
			cust2[i].Next = nullptr;
		}
	}
	NodeDoub* custom1 = &cust1[0];
	NodeDoub* custom2 = &cust2[0];
	NodeDoub* tmpp = concatenate(custom1, custom2);
	custom1 = tmpp;
	while (custom1 != nullptr) {
		cout << custom1->symb;
		custom1 = custom1->Next;
	}
}
