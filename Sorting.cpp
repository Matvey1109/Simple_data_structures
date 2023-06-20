#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void shaker_sort(int arr[], int n){
    int left = 0, right = n - 1, k = n - 1;
    while (left < right){
        for (int i = right; i > left; i--){
            if (arr[i] < arr[i - 1]){
                swap(arr[i], arr[i - 1]);
                k = i;
            }
        }
        left = k;
        for (int i = left; i < right; i++){
            if (arr[i] > arr[i + 1]){
                swap(arr[i], arr[i + 1]);
                k = i;
            }
        }
        right = k;
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot){
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quicksort(int arr[], int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    quicksort(arr, 0, n-1);

    cout << "Sorted array: ";
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;

    int arr2[] = {10, 7, 8, 9, 1, 5};
    int n2 = 6;

    shaker_sort(arr2, n2);

    cout << "Sorted array: ";
    for (auto x : arr2) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
