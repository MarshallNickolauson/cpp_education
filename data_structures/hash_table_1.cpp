#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

struct Person {
    string firstName;
    string lastName;
    int id;

    Person(string first, string last, int idNum) : firstName(first), lastName(last), id(idNum) {}
};

class HashTable {
private:
    std::vector<list<Person>> table;
    int hashFunction(char firstLetter) {
        return firstLetter - 'A';
    }
public:
    HashTable() {
        table.resize(26);
    }

    void insert(Person person) {
        int index = hashFunction(person.firstName[0]);
        table[index].push_back(person); //what is push back coming from??
    }

    bool search(string firstName, string lastName, int id) {
        int index = hashFunction(firstName[0]);
        for (auto &person : table[index]) {
            if (person.firstName == firstName && person.lastName == lastName && person.id == id) {
                return true;
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < 26; i++) {
            cout << char(i + 'A') << ": ";
            for (const auto &person : table[i]) {
                cout << person.firstName << " " << person.lastName << " (ID: " << person.id << ") -> ";
            }
            cout << "nullptr" << endl;
        }
    }
};

int main() {
    HashTable hashTable;
    hashTable.insert(Person("Andy", "Smith", 1));
    hashTable.insert(Person("Andy", "Johnson", 2));
    hashTable.insert(Person("Bob", "Brown", 3));
    
    hashTable.display();
    
    cout << "Searching for Andy Smith (ID: 1): " << (hashTable.search("Andy", "Smith", 1) ? "Found" : "Not Found") << endl;
    cout << "Searching for Andy Johnson (ID: 2): " << (hashTable.search("Andy", "Johnson", 2) ? "Found" : "Not Found") << endl;
    cout << "Searching for Charlie Brown (ID: 4): " << (hashTable.search("Charlie", "Brown", 4) ? "Found" : "Not Found") << endl;

    /* 

    A: Andy Smith (ID: 1) -> Andy Johnson (ID: 2) -> nullptr
    B: Bob Brown (ID: 3) -> nullptr
    C: nullptr
    D: nullptr
    E: nullptr
    F: nullptr
    G: nullptr
    H: nullptr
    I: nullptr
    J: nullptr
    K: nullptr
    L: nullptr
    M: nullptr
    N: nullptr
    O: nullptr
    P: nullptr
    Q: nullptr
    R: nullptr
    S: nullptr
    T: nullptr
    U: nullptr
    V: nullptr
    W: nullptr
    X: nullptr
    Y: nullptr
    Z: nullptr
    Searching for Andy Smith (ID: 1): Found
    Searching for Andy Johnson (ID: 2): Found
    Searching for Charlie Brown (ID: 4): Not Found
    
    */
    
    return 0;
}