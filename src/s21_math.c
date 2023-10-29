#include "s21_math.h"

void s21_pi(double* x) {
  while (*x > S21_M_PI || *x < -S21_M_PI) {
    if (*x > S21_M_PI)
      *x += -2 * S21_M_PI;
    else
      *x += 2 * S21_M_PI;
  }
}

long double s21_factorial(int n) {
  long double fact[n + 1];
  fact[0] = fact[1] = 1;
  for (int elem = 2; elem < n + 1; elem++) fact[elem] = fact[elem - 1] * elem;
  return fact[n];
}

int s21_abs(int x) { return x < 0 ? x * -1 : x; }

long double s21_fabs(double x) { return x < 0 ? x * -1 : x; }

long double s21_fmod(double x, double y) {
  if (s21_fabs(x) == S21_INF || y == 0) return S21_NAN;
  if (s21_fabs(y) == S21_INF) return x;
  if (x < y) return x;
  long long int integerPart = x / y;
  return x - y * integerPart;
}

long double s21_acos(double x) {
  long double result = S21_NAN;
  if (x < 1 && x >= 0) result = s21_atan(s21_sqrt(1 - x * x) / x);
  if (x < 0 && x > -1) result = S21_M_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  if (x == 1) result = 0;
  if (x == -1) result = S21_M_PI;
  return result;
}

long double s21_asin(double x) {
  long double result = S21_NAN;
  if (x > 1 || x < -1) return result;
  if (x == 1 || x == -1) result = S21_M_PI / (2 * x);
  if (x > -1 && x < 1) result = S21_M_PI / 2 - s21_acos(x);
  return result;
}

long double s21_atan(double x) {
  if (x == S21_INF) return S21_M_PI / 2;
  if (x == -S21_INF) return -S21_M_PI / 2;
  if (x != x) return S21_NAN;
  if (s21_fabs(x) == 1.0) {
    long double result = 0.7853981634;
    return x < 0 ? -result : result;
  }
  int is_in_range = (x > -1 && x < 1);
  long double result = is_in_range ? x : 1.0 / x;
  for (int i = 1; i < 20; i++) {
    double a = s21_simple_pow(-1, i);
    double b = s21_simple_pow(x, (1 + 2 * i) * (is_in_range ? 1 : -1));
    double c = 1 + 2 * i;
    result += a * b / c;
  }
  if (!is_in_range) result = (S21_M_PI * s21_fabs(x) / (2 * x)) - result;
  return result;
}

long double s21_cos(double x) {
  if (s21_fabs(x) == S21_INF || x == S21_NAN) return S21_NAN;
  return s21_sin(S21_M_PI / 2.0 - x);
}

long double s21_sin(double x) {
  if (s21_fabs(x) == S21_INF) return S21_NAN;
  s21_pi(&x);
  long double result = x, cur = 1;
  int n = 2;
  while (s21_fabs(cur) > S21_EPS) {
    cur = minusSign(n + 1) *
          (s21_simple_pow(x, 2 * n - 1) / s21_factorial(2 * n - 1));
    result += cur;
    n++;
  }
  return result;
}

long double s21_tan(double x) {
  if (s21_fabs(x) == S21_INF) return S21_NAN;
  s21_pi(&x);
  return s21_sin(x) / s21_cos(x);
}

long double s21_pow(double base, double exp) {
  if (exp == 0) return 1;
  long double check = s21_pow_check(base, exp);
  if (check != 2) return check;
  int sign = base < 0 ? -1 : 1;
  long double result = s21_exp(exp * s21_log(base * sign));
  if (s21_fmod(exp, 2) == 1) result *= sign;
  return result;
}

long double s21_exp(double x) {
  if (x == S21_INF || x > 709) return S21_INF;
  if (x == -S21_INF) return 0;
  long double result = 1 + x, cur = 1;
  int n = 2;
  while (s21_fabs(cur) > S21_EPS) {
    cur = s21_simple_pow(x, n) / s21_factorial(n);
    result += cur;
    n++;
  }
  return result;
}

long double s21_log(double x) {
  if (x < 0) return S21_NAN;
  if (x == 0) return -S21_INF;
  if (x == S21_INF) return x;
  long double result = 0;
  int e_repeat = 0;
  for (; x >= S21_M_E; e_repeat++) x /= S21_M_E;
  for (int i = 0; i < 100; i++)
    result += 2 * (x - s21_exp(result)) / (x + s21_exp(result));
  result += e_repeat;
  return result;
}

long double s21_sqrt(double x) {
  if (x != x || x < 0) return S21_NAN;
  if (S21_INF == x || x == 0) return (double)x;
  return s21_pow(x, 0.5);
}

long double s21_floor(double x) {
  if (x != x || x == -S21_INF || x == S21_INF) return x;
  x = x < 0 && x - (int)x ? x - 1 : x;
  return (int)x;
}

long double s21_ceil(double x) {
  if (x != s21_floor(x)) x += (1 - (x - s21_floor(x)));
  return x;
}

long double s21_simple_pow(double x, int n) {
  int flag = 0;
  if (n < 0) flag = 1;
  n = s21_abs(n);
  long double pow[n + 1];
  pow[0] = 1;
  for (int elem = 1; elem < n + 1; elem++) pow[elem] = x * pow[elem - 1];
  return flag ? 1 / pow[n] : pow[n];
}

int minusSign(int pow) { return pow % 2 == 0 ? 1 : -1; }

long double s21_pow_check(double base, double exp) {
  long double check = 2;
  if ((base < 0 && s21_fmod(exp, 1) != 0) || exp != exp) check = S21_NAN;
  if (exp == -S21_INF && s21_fabs(base) > 1) check = 0;
  if (exp == S21_INF && s21_fabs(base) < 1) check = 0;
  if (exp == -S21_INF && s21_fabs(base) < 1) check = S21_INF;
  if (exp == S21_INF && s21_fabs(base) > 1) check = S21_INF;
  return check;
}
