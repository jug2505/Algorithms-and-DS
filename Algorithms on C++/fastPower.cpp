// Быстрое возведение в степень
double Power (double a, int n){
  double result = 1; // Для хранения результата
  double aInPowerOf2 = a; // Текущее значение ((a^2)^2...)^2
  while (n > 0){
    // Добавляем нужную степень двойки к результату,
    // если она есть в разложении n в двоичной форме
    if (n & 1 == 1) result *= aInPowerOf2;
    aInPowerOf2 *= aInPowerOf2;
    n = n >> 1; // n делить на 2
  }
  return result;
}