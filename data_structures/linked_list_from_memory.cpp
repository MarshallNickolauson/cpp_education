#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    //~ delete all
    ~LinkedList() {
        Node* current = head;
        cout << "Deleted: ";
        while(current != nullptr) {
            delete current;
            cout << "|" << current << "| ";
            current = current->next;
        }
        cout << endl;
        cout << endl;
    }

    // add front
    void addHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        printHeadTail();
    }

    // delete front
    void deleteHead() {
        if (head == nullptr) {
            cout << "No head to delete." << endl;
        } else {
            head->next->prev = nullptr; // next node's previous = nullptr
            delete head;
            head = head->next;
        }
        printHeadTail();
    }

    // add end
    void addTail(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        printHeadTail();
    }

    // delete end
    void deleteTail() {
        if (tail == nullptr) {
            cout << "No tail to delete." << endl;
        } else {
            tail->prev->next = nullptr; // previous node's next = nullptr
            delete tail;
            tail = tail->prev;
        }
        printHeadTail();
    }

    // find by address

    // find by value

    // insert by address

    // insert by value (could be used for sorting)

    // delete by address

    // delete by value

    // print list
    void printList() {
        Node* current = head;
        cout << endl;
        cout << "Linked List: ";
        while(current != nullptr) {
            cout << "|" << current->data << "| -> ";
            current = current->next;
        }
        cout << " nullptr" << endl;
        cout << endl;
    }

    // print head tail
    void printHeadTail() {
        cout << "Head: " << head->data;
        cout << " | Tail: " << tail->data << endl;
    }
};

int main() {

    LinkedList* linkedList = new LinkedList();

    linkedList->addHead(1);
    linkedList->addHead(2);
    linkedList->addHead(3);

    linkedList->addTail(4);
    linkedList->addTail(5);
    linkedList->addTail(6);

    cout << endl;

    linkedList->deleteHead();
    linkedList->deleteTail();

    linkedList->printList();
    delete linkedList;

    return 0;
}