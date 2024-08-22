#include <iostream>

struct Node {
    int data;
    Node *prev;
    Node *next;
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtBeginning(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    void find(int value) {
        Node *current = head;
        while (current != nullptr) {
            if (current->data == value) {
                std::cout << value << " Found.\n";
                return;
            }

            current = current->next;
        }
        std::cout << value << " Not Found.\n";
    }

    void printList() {
        Node *current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }
};

int main()
{

    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    list.find(20);

    std::cout << "Doubly Linked List: ";
    list.printList();

    return 0;
}