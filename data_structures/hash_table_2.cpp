#include <iostream>
#include <vector>

using namespace std;

class HashTable {
private:
    std::vector<int> table;
    int capacity;
    int size;

    int hashFunction(int key) {
        return key % capacity;
    }
public:
    HashTable(int cap) : capacity(cap), size(0) {
        table.resize(capacity, -1);
    }

    bool insert(int key) {
        if (size == capacity) {
            cout << "Hash table is Full" << endl;
            return false;
        }

        int hashIndex = hashFunction(key);
        int startIndex = hashIndex;

        while (table[hashIndex] != -1) {
            hashIndex = (hashIndex + 1) % capacity;
            if (hashIndex == startIndex) {
                cout << "Hash table is full" << endl;
                return false; 
            }
        }

        table[hashIndex] = key;
        size++;
        return true;
    }

    int search(int key) {
        int hashIndex = hashFunction(key);
        int startIndex = hashIndex;

        while(table[hashIndex] != -1) {
            if (table[hashIndex] == key) {
                return hashIndex;
            }

            hashIndex = (hashIndex + 1) % capacity;

            if (hashIndex == startIndex) {
                return -1;
            }
        }

        return -1;
    }

    bool remove(int key) {
        int hashIndex = search(key);
        if (hashIndex == -1) {
            cout << "Key not found" << endl;
            return false;
        }

        table[hashIndex] = -1;
        size--;
        return true;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            if (table[i] != -1) {
                std::cout << i << " --> " << table[i] << std::endl;
            } else {
                std::cout << i << " --> " << "Empty" << std::endl;
            }
        }
    }
};

int main() {
    HashTable ht(7);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(32);

    ht.display();

    int searchKey = 15;
    int index = ht.search(searchKey);
    if (index != -1) {
        std::cout << "Key " << searchKey << " found at index " << index << std::endl;
    } else {
        std::cout << "Key " << searchKey << " not found" << std::endl;
    }

    ht.remove(15);
    ht.display();

    return 0;
}