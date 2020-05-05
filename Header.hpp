#pragma once

namespace ext

{
	struct Node {
		char symb;
		Node* Next;
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
}
