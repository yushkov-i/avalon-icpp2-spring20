#include <iostream>

using namespace std;

struct Node {
    char symb;
    Node *Next;
};

int main() {
    Node *first = new Node {'h'};
    Node *second = new Node {'e'};
    first->Next = second;
    Node *third = new Node {'l'};
    second->Next = third;
    Node *fourth = new Node {'l'};
    third->Next = fourth;
    Node *fifth = new Node {'o'};
    fourth->Next = fifth;
    int num, count{};
    Node* curr = first;
    cin >> num;
    while(count != num) {
        if (count == num - 1) {
            cout << curr->symb;
        } else {
            curr = curr->Next;
        }
        count++;
    }
}
