#include <algorithm>

// Операция вставки в кучу
// Происходит сравнение с предком
// T = O(log(n))
void heap_insert(int* a, int n, int x){
  a[n+1] = x;
  for (int i = n + 1; i > 1;){
    if (a[i] > a[i/2]){
      std::swap(a[i], a[i/2]);
      i = i / 2;
    } else {
      break;
    }
  }
}

// Операция извлечения из кучи
// Индексация с 1 похоже; поменять на 0, когда понадобится
void heap_pop (int* a, int n){
  std::swap(a[n], a[1]);

  for (int i = 1; 2 * i < n;){
    i *= 2;
    if (i+1 < n && a[i] < a[i+1]){
      i += 1;
    }
    if (a[i/2] < a[i]){
      std::swap(a[i/2], a[i]);
    }
  }
}

void heap_sort (int* data, int n){
  int* buff = new int[n+1];
  
  for (int i = 0; i < n; ++i){
    heap_insert(buff, i, data[i]);
  }
  for (int i = 0; i < n; ++i){
    data[n-1-i] = buff[1];
    heap_pop(buff, n - i);
  }
  
  delete [] buff;
}

void heap_make (int *a, int n){
  for (int i = n / 2; i >= 1; --i){
    for (int j = i; j <= n / 2;){
      int k = j * 2;
      if (k + 1 <= n and a[k] < a[k+1]){
        ++k;
      }
      if (a[j] < a[k]){
        std::swap(a[k], a[j]);
        j = k;
      } else {
        break;
      }
    }
  }
}