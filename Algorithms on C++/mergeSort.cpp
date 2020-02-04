#include <cstddef>
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

// Нисходящая сортировка слиянием
void mergeSortDown (int* data, int size){
    int* buffer = new int [size];
    merge_sort_buffer(data, size, buffer);
    delete(buffer);
}

// Восходящая сортировка слиянием
void mergeSortUp (int *data, size_t size, int *buffer){
    for (size_t chunk_size = 1; chunk_size < size; chunk_size *= 2){
        size_t offset = 0;
        for (; offset + chunk_size < size; offset += 2 * chunk_size){
            size_t right_size = chunk_size;
            if (offset + chunk_size + right_size > size){
                right_size = size - offset - chunk_size;
            }
            merge(
                &data[offset], chunk_size,
                &data[offset + chunk_size], right_size,
                &buffer[offset]);
        }
        for (size_t pos = 0; pos < size; ++pos){
            data[pos] = buffer[pos];
        }    
    }
}