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
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    //dequeue
    Node* dequeue() {
        if (tail != nullptr) {
            Node* nodeToReturn = tail;

            if (tail->prev != nullptr) { // more than 1 node in the queue
                tail = tail->prev;
                tail->next = nullptr;
            } else { // if ony one node is in the queue
                head = tail = nullptr;
            }

            nodeToReturn->prev = nullptr; // disconnect the dequeued node
            return nodeToReturn;
        } else {
            cout << "Nothing in the queue" << endl;
            return nullptr;
        }
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

    Node* dequeued1 = queue->dequeue();

    delete dequeued1;

    queue->print();

    delete queue;

    return 0;
}