void selectionSort(int s[], int n){
  int i, j;
  int min;
  
  for (i = 0; i < n; ++i){
    min = i;
    for (j = i + 1; j < n; ++j)
      if (s[j] < s[min]) min = j;
    std::swap(&s[i], &s[min]);  
  }
}
