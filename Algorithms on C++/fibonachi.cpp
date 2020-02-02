// Non-recursive algorithm
int Fibonachi( int n ){
  if (n == 0) return 1;
  int prev = 1; // F(0)
  int current = 1; // F(1)
  for (int i = 2; i <= n; ++i){
    int temp = current;
    current += prev; // F(i)
    prev = temp; // F(i-1)
  }
  return current;
}