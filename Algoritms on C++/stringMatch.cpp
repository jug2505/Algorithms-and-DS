int findmatch(char* p, char* t){
  int i,j;
  int m,n;
  
  m = std::strlen(p);
  n = std::strlen(t);
  
  for (i = 0; i <= (n - m); ++i){
    j = 0;
    while((j < m) && (t[i+j] == p[j]))
      ++j;
    if (j == m) return(i);
  }
  return(-1);
}
