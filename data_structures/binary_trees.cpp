#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

class Node {
private:
    string value;
    Node* left;
    Node* right;

public:
    int key;

    Node(int key, string value) : key(key), value(value), left(nullptr), right(nullptr) {}

    string getValue() {
        return value;
    }

    Node* getLeft() {
        return left;
    }

    Node* getRight() {
        return right;
    }

    void setValue(string val) {
        value = val;
    }

    void setLeft(Node* node) {
        left = node;
    }

    void setRight(Node* node) {
        right = node;
    }
};

class BinaryTree {
private:
    Node* root;

    void put(Node* current, Node* newNode) {
        //recursive
        if (newNode->key == current->key) { // if newNode key == current key
            current->setValue(newNode->getValue()); // overwrite value of current key
        } else if (newNode->key < current->key) {
            if (current->getLeft() != nullptr) {  // is present
                put(current->getLeft(), newNode); // recursion
            } else {                              // is not present
                current->setLeft(newNode);        // set left node to new node
            }
        } else {
            if (current->getRight() != nullptr) {
                put(current->getRight(), newNode);
            } else {
                current->setRight(newNode);
            }
        }
    }

    void findMinimum(Node* current) {
        if (current->getLeft() != nullptr) {
            findMinimum(current->getLeft());
        } else {
            cout << "Minimum node is " << current->key << ": " << current->getValue() << endl;
        }
    }

    void findMaximum(Node* current) {
        if (current->getRight() != nullptr) {
            findMaximum(current->getRight());
        } else {
            cout << "Maximum node is " << current->key << ": " << current->getValue() << endl;
        }
    }

    void printTree(Node* node, const string& prefix = "", bool isLeft = true) {
        if (node != nullptr) {
            cout << prefix;
            cout << (isLeft ? "L-- " : "R-- ");
            cout << "Node: " << node->key << " -> " << node->getValue() << endl;
            string newPrefix = prefix + (isLeft ? "|   " : "    ");
            printTree(node->getLeft(), newPrefix, true);
            printTree(node->getRight(), newPrefix, false);
        }
    }
public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        if (root != nullptr) {
            std::queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                Node* node = q.front();
                int tempInt = node->key;
                delete node;
                std::cout << "Deleted node: " << tempInt << endl;
                q.pop();
                if (node->getLeft() != nullptr) q.push(node->getLeft());
                if (node->getRight() != nullptr) q.push(node->getRight());
            }
        }
    }

    void insert(int key, string value) {
        Node* newNode = new Node(key, value);
        if (root == nullptr) {
            root = newNode;
        } else {
            put(root, newNode);
        }
    }

    void findMinimum() {
        if (root != nullptr) {
            findMinimum(root);
        }
    }

    void findMaximum() {
        if (root != nullptr) {
            findMaximum(root);
        }
    }

    void print() {
        printTree(root);
    }

    void breadthFirstSearch() {
        if (root != nullptr) {
            std::queue<Node*> q;
            q.push(root);
            while (!q.empty()) {
                int level = q.size();
                for (int i = 0; i < level; i++) {
                    Node* node = q.front();
                    std::cout << node->key << " ";
                    q.pop();
                    if (node->getLeft() != nullptr) q.push(node->getLeft());
                    if (node->getRight() != nullptr) q.push(node->getRight());
                }
                cout << endl;
            }
        }
    }

    void depthFirstSearch() {
        if (root != nullptr) {
            std::stack<Node*> s;
            s.push(root);
            while(!s.empty()) {
                Node* node = s.top();
                s.pop();
                std::cout << node->key << " ";
                if (node->getRight() != nullptr) s.push(node->getRight());
                if (node->getLeft() != nullptr) s.push(node->getLeft());
            }
        }
    }
};

int main() {

    BinaryTree* binaryTree = new BinaryTree();

    binaryTree->insert(7, "Marshall");
    binaryTree->insert(5, "Morgan");
    binaryTree->insert(9, "Hope");
    binaryTree->insert(12, "Avery");
    binaryTree->insert(3, "Harper");
    binaryTree->insert(15, "Elijah");
    binaryTree->insert(8, "Noah");
    binaryTree->insert(1, "Scarlett");
    binaryTree->insert(20, "Olivia");
    binaryTree->insert(6, "Liam");
    binaryTree->insert(18, "Ethan");
    binaryTree->insert(11, "Sophia");
    binaryTree->insert(2, "James");
    binaryTree->insert(2, "Jain"); // changes node 2 value to be Jane (no duplicates)

    binaryTree->print();
    cout << endl;

    binaryTree->findMinimum();
    binaryTree->findMaximum();
    cout << endl;

    binaryTree->breadthFirstSearch();
    cout << endl;

    binaryTree->depthFirstSearch();
    cout << endl;
    cout << endl;

    delete binaryTree;
    return 0;
}