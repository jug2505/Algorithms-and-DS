#include <algorithm>

void insertionSort(int* arr, int n){
    for ( int i = 1; i < n; ++i)
        for (int j = i; j > 0 && arr[j] < arr[j-1]; --j)
            std::swap(arr[j], arr[j-1]);
}
