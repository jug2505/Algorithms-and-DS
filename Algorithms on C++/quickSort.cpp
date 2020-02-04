#include <algorithm>

// Сортировка Хоара (Split quick sort)
// Пивот-первый элемент. Указатель на последний элемент
// Лучший случай - split делит массив в соотношении 1:1 - O(nlog(n))
// Самый плохой случай - упорядоченный массив делится 1:n-1 - O(n^2)
void quickSort (int *a, int n){
  int i = 0;
  int j = n - 1; 
  bool side = 0; // 0 - пивот в i, 1 - пивот в j
  while (i != j) {
    if (a[i] > a[j]) {
      std::swap(a[i], a[j]);
      side = !side;
    }
    side ? ++i : --j;
  }
  if (i > 1) quickSort(a, i);
  if (n > i + 1) quickSort(a + (i+1), n - (i+1));
}