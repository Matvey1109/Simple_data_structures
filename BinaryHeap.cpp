#include <iostream>
#include <vector>

class HeapOnArray{
private:
    std::vector<int> heap;

    int get_parent(int index){
        return (index - 1) / 2;
    }

    void upHeapify(int index){
        if (index == 0){
            return;
        }

        int parent_index = get_parent(index);
        if (heap[parent_index] < heap[index]){
            std::swap(heap[parent_index], heap[index]);
            upHeapify(parent_index);
        }
    }

public:
    void insert(int data){
        heap.push_back(data);
        upHeapify(heap.size() - 1);
    }

    void print(){
        for (auto c : heap){
            std::cout << c << ' ';
        }
        std::cout << std::endl;
    }
};