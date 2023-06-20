// OPEN-ADDRESSING
#include <iostream>

template<typename KeyType, typename ValueType>
class HashTable{
private:
    struct Node{
        KeyType key;
        ValueType value;
        Node* next;

        Node(KeyType key, ValueType value) : key(key), value(value), next(nullptr) {}
    };
    static const int table_size = 100;
    Node* table[table_size];

public:
    HashTable(){
        for (int i = 0; i < table_size; ++i) {
            table[i] = nullptr;
        }
    }

    int hash(KeyType key){
        return key % table_size;
    }

    void insert(KeyType key, ValueType value){
        Node* newnode = new Node(key, value);
        int index = hash(key);

        if (table[index] == nullptr){
            table[index] = newnode;
        } else {
            Node* curr = table[index];
            while (curr != nullptr){
                curr = curr->next;
            }
            curr = newnode;
        }
    }

    void remove(KeyType key){
        int index = hash(key);

        Node* curr = table[index];
        Node* prev = nullptr;

        while (curr != nullptr && curr->key != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != nullptr) {
            if (prev == nullptr) {
                table[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
        }
    }

    ValueType find(KeyType key){
        int index = hash(key);
        Node* curr = table[index];

        while (curr != nullptr) {
            if (curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }
    }
};