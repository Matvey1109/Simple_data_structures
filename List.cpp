#include <iostream>

template<typename T>
class List{
private:
    struct Node{
        T data;
        Node* next;
        Node* prev;

        Node(T data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}

    ~List(){
        while (head){
            Node* nxt = head->next;
            delete head;
            head = nxt;
        }
    }

    void add(T value){
        Node* newnode = new Node(value);
        if (head == nullptr){
            head = tail = newnode;
            return;
        }

        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void insert(int index, T value){
        Node* new_item = new Node(value);
        if (!head){
            head = tail = new_item;
        } else if (index == 0){
            head->prev = new_item;
            new_item->next = head;
            head = new_item;
        } else{
            Node* current = head;
            for (int i = 1; i < index && current; i++){
                current = current->next;
            }
            if(!current->next){
                tail = new_item;
            }
            new_item->next = current->next;
            current->next->prev = new_item;
            new_item->prev = current;
            current->next = new_item;
        }
    }

    void remove(int index){
        if (index == 0){
            Node* old_head = head;
            head = head->next;
            head->prev = nullptr;
            delete old_head;
            return;
        }

        Node* current = head;
        for(int i = 1; i < index && current; i++){
            current = current->next;
        }

        if(!current || !current->next){
            return;
        }

        Node* to_be_deleted = current->next;
        current->next = to_be_deleted->next;
        to_be_deleted->next->prev = current;
        delete to_be_deleted;
    }

    void print(){
        Node* current = head;
        while (current){
            std::cout << current->data << ' ';
            current = current->next;
        }
        std::cout << std::endl;
        delete current;
    }
};