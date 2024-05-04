#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

// Structure for key-value pair
struct KeyValuePair {
    string key;
    int value;
    
    KeyValuePair(string k, int v) : key(k), value(v) {}
};

// Hash table class
class HashTable {
private:
    vector<list<KeyValuePair>> table;
    int capacity;
    
    // Hash function to map keys to indices
    int hashFunction(const string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += ch;
        }
        return hash % capacity;
    }

public:
    // Constructor
    HashTable(int size) : capacity(size) {
        table.resize(capacity);
    }

    // Insert key-value pair into the hash table
    void insert(const string& key, int value) {
        int index = hashFunction(key);
        table[index].push_back(KeyValuePair(key, value));
    }

    // Find the value associated with a key
    int find(const string& key) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.key == key) {
                return pair.value;
            }
        }
        return -1; // Key not found
    }

    // Delete a key-value pair from the hash table
    void remove(const string& key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;
    
    HashTable dictionary(size);
    
    while (true) {
        cout << "\n1. Insert a key-value pair\n";
        cout << "2. Find the value by key\n";
        cout << "3. Remove a key-value pair\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string key;
                int value;
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                dictionary.insert(key, value);
                cout << "Key-value pair inserted successfully.\n";
                break;
            }
            case 2: {
                string key;
                cout << "Enter key: ";
                cin >> key;
                int value = dictionary.find(key);
                if (value != -1)
                    cout << "Value of " << key << ": " << value << endl;
                else
                    cout << "Key not found.\n";
                break;
            }
            case 3: {
                string key;
                cout << "Enter key to remove: ";
                cin >> key;
                dictionary.remove(key);
                cout << "Key-value pair removed successfully.\n";
                break;
            }
            case 4: {
                cout << "Exiting...\n";
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
