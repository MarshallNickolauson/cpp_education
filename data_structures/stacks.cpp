#include <iostream>
#include <optional>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node (int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* top;
public:
    LinkedList() : top(nullptr) {}

    ~LinkedList() {
        Node* current = top;
        while(current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            cout << "Deleted: " << toDelete << " - " << toDelete->data << endl;
            delete toDelete;
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        if (top != nullptr) {
            newNode->next = top;
        }
        top = newNode;
    }

    std::optional<int> pop() {
        if (top != nullptr) {
            Node* nodeToReturn = top;
            int valueToReturn = nodeToReturn->data;
            top = top->next;
            nodeToReturn->next = nullptr;
            delete nodeToReturn;
            return valueToReturn;
        }
        return std::nullopt;
    }

    void printStack() {
        Node* current = top;
        while(current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {

    LinkedList* stack = new LinkedList();

    stack->push(1);
    stack->push(2);
    stack->push(3);

    stack->printStack();

    std::optional<int> popped1 = stack->pop();
    std::optional<int> popped2 = stack->pop();
    std::optional<int> popped3 = stack->pop();

    cout << popped1.value() << endl;
    cout << popped2.value() << endl;
    cout << popped3.value() << endl;

    delete stack;

    return 0;
}