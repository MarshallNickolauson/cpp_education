#include <iostream>

struct Node {
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList {
private:
    Node *head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertFront(int value) {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int value) {
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

    void insertAfter(Node *nextNode, int value) {
        Node *newNode = new Node();
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
        } else if (nextNode != nullptr) {
            // Insert the new node after the nextNode
            newNode->next = nextNode->next;
            newNode->prev = nextNode;

            if (nextNode->next != nullptr) {
                nextNode->next->prev = newNode;
            }

            nextNode->next = newNode;
        } else {
            std::cout << "The specified node was not found." << std::endl;
        }
    }

    void deleteFront() {
        if (head != nullptr) {
            Node *currentHead = head;
            head = currentHead->next;
            delete currentHead;
        } 
    }

    void deleteEnd() {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->prev->next = nullptr;
        delete current;
    }

    Node* find(int value) {
        Node *current = head;
        while (current != nullptr) {
            if (current->data == value) {
                std::cout << value << " Found.\n";
                return current;
            }

            current = current->next;
            std::cout << current << std::endl;
        }
        std::cout << value << " Not Found.\n";
        return nullptr;
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

    DoublyLinkedList list;

    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);

    list.insertEnd(420);

    std::cout << std::endl;
    std::cout << "Doubly Linked List: ";
    list.printList();

    list.deleteFront();
    list.deleteFront();
    list.deleteFront();

    Node* foundNode = list.find(420);
    if (foundNode != nullptr) {
        list.insertAfter(foundNode, 69);
        list.insertAfter(foundNode, 69);
    }

    list.deleteEnd();

    std::cout << "Doubly Linked List: ";
    list.printList();
    std::cout << std::endl;

    return 0;
}