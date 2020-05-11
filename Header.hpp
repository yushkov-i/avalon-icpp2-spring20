#pragma once

namespace ext

{
	struct Node {
		char symb;
		Node* Next;
	};

	struct NodeDoub {
		char symb;
		NodeDoub* Next;
		NodeDoub* Prev;
	};

	char characterAt(Node* head, int pos) {
		int count{};
		Node* curr = head;
		while (count != pos) {
			if (count == pos - 1) {
				return curr->symb;
			}
			else {
				curr = curr->Next;
			}
			count++;
		}
	}


	Node* append(Node* tmp, char symbb) {
		Node* tail = new Node{symbb};
		return tail;
	}

	int countSize(Node* tmp) {
		int size{};
		Node* curr = tmp;
		while (curr != nullptr) {
				size++;
				curr = curr->Next;
		}
		return size;
	}

	char* removeChars(Node* head, int a, int cost) {
		int size_was = countSize(head);
		int size = size_was - cost;	
		char x;
		char* tmp = new char[size + 1];
		Node* curr_pos = head;
		int count = 0;
		for (int i = 0; i < size_was; i++) {
			if ((i >= a - 1) && (i < a - 1 + cost)) {
				curr_pos = curr_pos->Next;
			}
			else {
				x = curr_pos->symb;
				tmp[count] = x;
				curr_pos = curr_pos->Next;
				count++;
			}
		}
		tmp[size] = '\0';
		return tmp;
	}

	NodeDoub* concatenate(NodeDoub* a, NodeDoub* b) {
		NodeDoub* tmp = a;
		while (tmp->Next != nullptr) {
			tmp->Next->Prev = tmp;
			tmp = tmp->Next;
		}
		if (tmp->Next == nullptr) {
			tmp->Next = b;
		}
		while (tmp != a->Next) {
			tmp = tmp->Prev;
		}
		tmp = tmp->Prev;
		return tmp;
	}
}
