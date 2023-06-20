#include <iostream>

template<typename T>
class Vector{
private:
    T* data;
    int sz;
    int cap;

public:
    Vector() : data(nullptr), sz(0), cap(0) {}

    ~Vector(){
        delete data;
    }

    void push_back(T val){
        if(sz >= cap){
            int newCap;
            if (cap == 0){
                newCap = 1;
            } else {
                newCap = cap * 2;
            }
            T* newData = new T[newCap];

            for (int i = 0; i < sz; i++){
                newData[i] = data[i];
            }
            delete data;

            data = newData;
            cap = newCap;
        }
        data[sz++] = val;
    }

    void pop(){
        if(empty()){
            std::cout << "Vector is empty";
            return;
        }
        sz--;
    }

    bool empty(){
        return sz == 0;
    }

    int size(){
        return sz;
    }

    int capacity(){
        return cap;
    }

    T operator[](int index){
        return data[index];
    }
};