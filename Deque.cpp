#include <iostream>

template<typename T>
class Deque{
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
    Deque() : head(nullptr), tail(nullptr) {}

    void push_back(T data){
        Node* newnode = new Node(data);
        if (head == nullptr){
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void push_front(T data){
        Node* newnode = new Node(data);
        if (head == nullptr){
            head = tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void pop_back(){
        if (head == nullptr){
            return;
        }
        Node* temp = tail;
        tail->prev->next = nullptr;
        tail = tail->prev;
        delete temp;
    }

    void pop_front(){
        if (head == nullptr){
            return;
        }
        Node* temp = head;
        head->next->prev = nullptr;
        head = head->next;
        delete temp;
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


class Deque2{
private:
    int arr[100];
    int head;
    int tail;

public:
    Deque2() : head(30), tail(30) {}

    void push_back(int data){
        arr[tail++] = data;
    }

    void push_front(int data){
        arr[--head] = data;
    }

    void pop_back(){
        tail--;
    }

    void pop_front(){
        head++;
    }

    void print(){
        int cur = head;
        while(cur != tail){
            std::cout << arr[cur] << ' ';
            cur++;
        }
        std::cout << std::endl;
    }
};
