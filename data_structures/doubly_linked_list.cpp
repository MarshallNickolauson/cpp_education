#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr) {}

    // ~ is the destructor operator. When "delete list" is called of type DoublyLinkedList, it will properly delete all nodes from heap memory.
    ~DoublyLinkedList() {
        Node* current = head;
        Node* nextNode;
        cout << endl;
        while(current != nullptr) {
            nextNode = current->next;
            cout << "Deleted Node: " << current << endl;
            delete current;
            current = nextNode;
        }
        cout << endl;
    }

    // insert at end, find, insert in middle, delete, display functions...

    void addFront(int value) {
        Node* newNode = new Node(value);
        cout << "New Node at: " << newNode << " -> " << newNode->data << endl;
        if(head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        //printHeadTail();
    }

    void append(int value) {
        Node* newNode = new Node(value);
        cout << "New Node at: " << newNode << " -> " << newNode->data << endl;
        if(head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        printHeadTail();
    }

    void printList() {
        Node* current = head;
        cout << endl;
        cout << "Linked List: ";
        while(current != nullptr) {
            cout << "|" << current->data << "| -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    void printHeadTail() {
        cout << "Head: " << head->data << endl;
        cout << "Tail: " << tail->data << endl;
    }
};

int main() {

    DoublyLinkedList* linkedList = new DoublyLinkedList();
    cout << endl;

    linkedList->addFront(1);
    linkedList->addFront(2);
    linkedList->addFront(3);

    linkedList->append(420);
    linkedList->append(421);
    linkedList->append(422);

    linkedList->printList();

    delete linkedList;
    
    return 0;
}