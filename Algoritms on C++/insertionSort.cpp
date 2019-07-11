void insertionSort(int* arr, int n){
    int key;
    int i, j;
    for (j = 1; j < n; ++j){
        key = arr[j];
        // Insert arr[j] into the sorted sequence
        i = j - 1;
        while (i >= 0 && arr[i] > key){
            arr[i + 1] = arr [i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}
