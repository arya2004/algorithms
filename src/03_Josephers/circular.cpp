#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};


Node* createCircularLinkedList(int n) {
    Node* head = new Node{1, nullptr};
    Node* prev = head;
    
    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node{i, nullptr};
        prev->next = newNode;
        prev = newNode;
    }
    
    prev->next = head; 
    return head;
}


int josephus(int n, int k) {
    Node* head = createCircularLinkedList(n);
    Node* prev = head;
    
    // Move prev to the last node
    while (prev->next != head) {
        prev = prev->next;
    }

    while (head->next != head) { 
        for (int i = 1; i < k; i++) {
            prev = head;
            head = head->next;
        }

        prev->next = head->next;
        delete head;
        head = prev->next;
    }
    
    int survivor = head->data;
    delete head;
    return survivor;
}

int main() {
    int n = 25, k = 2;
    cout << "Survivor: " << josephus(n, k) << endl;
    return 0;
}
