/**
* Слияние 2х упорядоченных массивов
*/
void merge(int* a, int a_len, int* b, int b_len, int* c){
    int i = 0; int j = 0;
    while (i < a_len and j < b_len){
        if (a[i] < b[j]) {
            c[i+j] = a[i];
            ++i;
        }
        else{
            c[i+j] = b[j];
            ++j;
        }
    }
    if (i == a_len){
        for( ;j < b_len; ++j){ c[i+j] = b[j]; }
    }
    else{
        for( ;i < a_len; ++i){ c[i+j] = a[i]; }
    }
}


void merge_sort_buffer(int *data, int size, int *buffer) {
    if (size < 2) return;
    merge_sort_buffer(data, size / 2, buffer);
    merge_sort_buffer(&data[size / 2], size - size / 2, buffer);

    merge(&data[0], size / 2, &data[size/2], size - size / 2, buffer);

    for (size_t pos = 0; pos < size; ++pos){
        data[pos] = buffer[pos];
    }
}

void mergeSort (int* data, int size){
    int* buffer = new int [size];
    merge_sort_buffer(data, size, buffer);
    delete(buffer);
}

