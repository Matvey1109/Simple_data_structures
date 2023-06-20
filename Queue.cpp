#include <iostream>

template<typename T>
class Queue{
private:
    struct Node{
        T data;
        Node* next;

        Node(T data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    void push(T data){
        Node* newnode = new Node(data);
        if (head == nullptr){
            head = tail = newnode;
            return;
        }

        tail->next = newnode;
        tail = newnode;
    }

    void pop(){
        if (head == nullptr){
            return;
        } else if (head == tail){
            delete head;
            head = tail = nullptr;
        } else{
            Node* old_head = head;
            head = head->next;
            delete old_head;
        }
    }

    void print(){
        Node* current = head;
        while (current){
            std::cout << current->data << ' ';
            current = current->next;
        }
        std::cout << std::endl;
    }
};


class Queue2{
private:
    int arr[100];
    int head;
    int tail;

public:
    Queue2() : head(0), tail(0) {}

    void push(int data){
        arr[tail++] = data;
    }

    void pop(){
        if(head == tail){
            return;
        }
        head++;
    }

    void print(){
        int cur = head;
        while (cur != tail){
            std::cout << arr[cur] << ' ';
            cur++;
        }
        std::cout << std::endl;
    }
};