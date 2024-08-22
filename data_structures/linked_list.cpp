#include <iostream>

struct Node
{
    int data; // Data in the node
    Node* next; // Pointer to the next node
};

class LinkedList
{
private:
    Node* head; // Points to the first node;

public:
    LinkedList() : head(nullptr) {}     // Constructor initializes head to nullptr

    // Insert new node at the beginning
    void insertAtBeginning(int value)
    {
        Node* newNode = new Node();     // Create a new node
        newNode->data = value;          // Set the node's data
        newNode->next = head;           // Point the new node to the current head
        head = newNode;                 // Update the head to be the new node
    }

    // Insert new node at the end
    void insertAtEnd(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) 
        {
            head = newNode;
        }
        else 
        {
            Node* current = head;
            while(current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void find(int value)
    {
        Node* current = head;
        while(current != nullptr)
        {
            if(current->data == value) 
            {
                std::cout << value << " Found.\n";
                return;
            }

            current = current->next;
        }
        std::cout << value << " Not Found.\n";
    }

    // Print the linked list
    void printList()
    {
        Node* current = head;
        while(current != nullptr)                   // Traverse the list
        {
            std::cout << current->data << " -> ";   // Print data
            current = current->next;                // Move to the next node
        }
        std::cout << "nullptr\n";                   // End of the list
    }
};

int main()
{

    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtEnd(60);

    list.find(40);

    std::cout << "Linked List: ";
    list.printList();

    return 0;
}