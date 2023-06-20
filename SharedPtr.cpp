#include <iostream>

template<typename T>
class SharedPtr{
private:
    T* ptr;
    int* refCount;

public:
    SharedPtr() : ptr(nullptr), refCount(nullptr) {}

    SharedPtr(T* ptr) : ptr(ptr), refCount(new int(1)) {}

    SharedPtr(SharedPtr<T>& other) : ptr(other.ptr), refCount(other.refCount) {
        if(refCount){
            ++(*refCount);
        }
    }

    ~SharedPtr(){
        release();
    }

    SharedPtr<T>& operator=(SharedPtr<T>& other){
        if (other == this){
            return *this;
        }

        release();
        ptr = other.ptr;
        refCount = other.refCount;
        if(refCount){
            ++(*refCount);
        }
    }

    void release(){
        if(refCount){
            --(*refCount);
            if(refCount == 0){
                delete ptr;
                delete refCount;
            }
        }
    }

    T& operator*(){
        return *ptr;
    }

    T* operator->(){
        return ptr;
    }

    T* get(){
        return ptr;
    }
};