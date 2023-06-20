#include <iostream>

template<typename T>
class ForwardList{
private:
    struct Node{
        T data;
        Node* next;

        Node(T data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    ForwardList() : head(nullptr), tail(nullptr) {}

    ~ForwardList(){
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
        tail = newnode;
    }

    void insert(int index, T value) {
        Node* new_item = new Node(value);
        if (!head) {
            head = tail = new_item;
        } else if (index == 0) {
            new_item->next = head;
            head = new_item;
        } else {
            Node* current = head;
            for(int i = 1; i < index && current; i++)
                current = current->next;
            if (!current->next)
                tail = new_item;
            new_item->next = current->next;
            current->next = new_item;
        }
    }

    void remove(int index) {
        if (index == 0) {
            Node* old_head = head;
            head = head->next;
            delete old_head;
            return;
        }

        Node* current = head;
        for (int i = 1; i < index && current; i++) {
            current = current->next;
        }

        if (!current || !current->next) {
            return;
        }

        Node* to_be_deleted = current->next;
        current->next = to_be_deleted->next;
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