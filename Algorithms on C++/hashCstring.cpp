// Хеш-функция строки
// Параметр хеш-функции
int Hash (const char* str, int m, const int a){
  int hash = 0;
  for ( ; *str != 0; ++str){
    hash = ( hash * a + *str) % m;
  }
  return hash;
}