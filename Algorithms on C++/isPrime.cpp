// Проверка числа на простоту
// Проверяются все числа от 2 до sqrt(n)
// [Если два делителя больше sqrt(n), то число больше n] 
bool IsPrime (int n){
  if (n == 1) return false;

  for ( int i = 2; i * i <= n; ++i){
    if (n % i == 0) return false;
  }
  return true;
}