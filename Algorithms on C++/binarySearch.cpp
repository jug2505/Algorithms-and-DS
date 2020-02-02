// Нерикурсивный алгоритм
int BinarySearch (double* arr, int count, double element){
  int first = 0;
  int last = count; // Элемент в last не учитывается
  while (first < last){
    int mid = (first + last) / 2;
    if (element <= arr[mid])
      last = mid;
    else 
      first = mid + 1;  
  }
  return (first == count || arr[first] != element) ? -1 : first;
}