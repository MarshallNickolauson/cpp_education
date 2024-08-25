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
    Node* findByAddress(Node* address) {
        Node* current = head;
        while(current != nullptr) {
            if (current == address) {
                return current;
            } else {
                current = current->next;
            }
        }
        return nullptr;
    }

    // find by value
    Node* findByValue(int value) {
        Node* current = head;
        while(current != nullptr) {
            if (current->data == value) {
                return current;
            } else {
                current = current->next;
            }
        }
        return nullptr;
    }

    // insert after address
    void insertAfter(Node* address, int value) {
        Node* newNode = new Node(value);
        Node* current = head;
        while(current != nullptr) {
            if (current == address) {
                newNode->next = current->next;
                newNode->prev = current;
                current->next->prev = newNode;
                current->next = newNode;
                return;
            } else {
                current = current->next;
            }
        }
        cout << "Couldn't find Node: " << address << endl;
    }

    // insert after value (could be used for sorting)
    void insertAfterValue(int valueAfter, int value) {
        Node* newNode = new Node(value);
        Node* current = head;

        while(current != nullptr) {
            if (current->data == valueAfter) {
                newNode->next = current->next;
                newNode->prev = current;
                current->next->prev = newNode;
                current->next = newNode;
                return;
            } else {
                current = current->next;
            }
        }
        cout << "Couldn't find Node with value: " << valueAfter << endl;
    }

    // delete by address
    void deleteByAddress(Node* address) {
        Node* current = head;
        while (current != nullptr) {
            if (current == address) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {  // If not, update the head
                    head = current->next;
                }

                if (current->next != nullptr) { 
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Couldn't find Node: " << address << endl;
    }

    // delete by value
    void deleteByValue(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else { 
                    head = current->next;
                }

                if (current->next != nullptr) { 
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Couldn't find Node with value: " << value << endl;
    }

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
    linkedList->addTail(420);
    linkedList->addTail(5);
    linkedList->addTail(6);
    linkedList->addTail(7);

    cout << endl;

    linkedList->deleteHead();
    linkedList->deleteTail();

    Node* foundNodeAddress = linkedList->findByValue(420);
    
    linkedList->printList();
    linkedList->insertAfter(foundNodeAddress, 69);

    linkedList->printList();
    linkedList->insertAfterValue(69, 690);

    linkedList->printList();
    linkedList->deleteByAddress(foundNodeAddress);

    linkedList->printList();
    linkedList->deleteByValue(6);

    linkedList->printList();
    delete linkedList;

    return 0;
}