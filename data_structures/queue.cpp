#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class Queue {
private:
    Node* head;
    Node* tail;
public:
    //constructor
    Queue() : head(nullptr), tail(nullptr) {}

    //destructor
    ~Queue() {
        Node* current = head;
        while(current != nullptr) {
            Node* node = current;
            cout << "Deleted: " << node << endl;
            current = current->next;
            delete node;
        }
    }

    //enqueue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        newNode->prev = tail;
        if (tail != nullptr) {
            tail->next = newNode;
        }
        if (head == nullptr) {
            head = newNode;
        }
        tail = newNode;
    }

    //dequeue
    int dequeue() {
        if (head != nullptr) {
            Node* nodeToReturn = head;
            head = head->next;
            head->prev = nullptr;
            int valueToReturn = nodeToReturn->data;
            delete nodeToReturn;
            return valueToReturn;
        }
        return 0;
    }

    //print
    void print() {
        Node* current = head;
        while(current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {

    Queue* queue = new Queue();

    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);

    queue->print();

    int dequeued1 = queue->dequeue();

    cout << dequeued1 << endl;

    queue->print();

    delete queue;

    return 0;
}