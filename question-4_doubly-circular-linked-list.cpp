#include <iostream>
using namespace std;

//Doubly linked list 
struct Node {
    int data;
    Node* prev;
    Node* next;
};
 
class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node{val, nullptr, head};
        if (head) head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node{val, nullptr, nullptr};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteAtBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        Node* temp = head;
        if (!temp->next) {
            delete temp;
            head = nullptr;
            return;
        }
        while (temp->next) temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

//Circular linked list
struct CNode {
    int data;
    CNode* next;
};

class CircularLinkedList {
    CNode* tail;
public:
    CircularLinkedList() : tail(nullptr) {}

    void insertAtBeginning(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (!tail) {
            newNode->next = newNode;
            tail = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode{val, nullptr};
        if (!tail) {
            newNode->next = newNode;
            tail = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtBeginning() {
        if (!tail) return;
        CNode* head = tail->next;
        if (head == tail) {
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
    }

    void deleteAtEnd() {
        if (!tail) return;
        CNode* head = tail->next;
        if (head == tail) {
            delete tail;
            tail = nullptr;
        } else {
            CNode* temp = head;
            while (temp->next != tail) temp = temp->next;
            temp->next = tail->next;
            delete tail;
            tail = temp;
        }
    }

    void display() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }
        CNode* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to head)\n";
    }
};

//Main function
int main() {
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtEnd(20);
    dll.insertAtBeginning(5);
    dll.display();
    dll.deleteAtEnd();
    dll.display();

    CircularLinkedList cll;
    cll.insertAtEnd(1);
    cll.insertAtEnd(2);
    cll.insertAtBeginning(0);
    cll.display();
    cll.deleteAtBeginning();
    cll.display();

    return 0;
}
