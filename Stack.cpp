#include <iostream>

template<typename T>
class Stack{
private:
    struct Node{
        T data;
        Node* next;

        Node(T data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    Stack() : head(nullptr), tail(nullptr) {}

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
        } else {
            Node* current = head;
            while (current->next != tail){
                current = current->next;
            }
            current->next = nullptr;
            delete tail;
            tail = current;
        }
    }

    void print(){
        Node* current = head;
        while(current){
            std::cout << current->data << ' ';
            current = current->next;
        }
        std::cout << std::endl;
    }
};


class Stack2{
private:
    int arr[100];
    int head;
    int tail;

public:
    Stack2() : head(0), tail(0) {}

    void push(int data){
        arr[tail++] = data;
    }

    void pop(){
        if(head == tail){
            return;
        }
        tail--;
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