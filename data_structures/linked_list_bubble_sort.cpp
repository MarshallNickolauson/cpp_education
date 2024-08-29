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

    ~LinkedList() {
        Node* current = head;
        while(current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

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

    void deleteHead() {
        if (head == nullptr) {
            cout << "No head to delete." << endl;
        } else {
            head->next->prev = nullptr;
            delete head;
            head = head->next;
        }
        printHeadTail();
    }

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

    void bubbleSort() {
        // this bubble sort isn't swapping the addresses of the nodes, it's just swapping the data
        // inside the node. Technically less operations and no new heap memory required
        // although you could swap the addresses to and redo all their pointers
        Node* i = head;
        while (i != nullptr) {
            Node* j = head;
            while (j->next != nullptr) {
                if (j->data > j->next->data) {
                    int temp = j->data;
                    j->data = j->next->data;
                    j->next->data = temp;
                }
                j = j->next;
            }
            i = i->next;
        }
    }

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

    void printHeadTail() {
        cout << "Head: " << head->data;
        cout << " | Tail: " << tail->data << endl;
    }
};

int main() {

    LinkedList* linkedList = new LinkedList();

    linkedList->addTail(17);
    linkedList->addTail(9);
    linkedList->addTail(2);
    linkedList->addTail(5);
    linkedList->addTail(4);
    linkedList->addTail(8);
    linkedList->addTail(1);
    linkedList->addTail(6);

    linkedList->printList();

    linkedList->bubbleSort();

    linkedList->printList();

    return 0;
}