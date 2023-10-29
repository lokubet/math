#ifndef MATH_S21_MATH_H_
#define MATH_S21_MATH_H_

#define S21_M_PI 3.14159265358979323846264338327950288
#define S21_M_E 2.71828182845904523536028747135266250
#define S21_EPS 1e-20
#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0

// MATH.H FUNCTIONS
int s21_abs(int x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);
long double s21_pow(double base, double exp);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
long double s21_floor(double x);
long double s21_ceil(double x);

// SUPPORT FUNCTIONS
void s21_pi(double* x);
int arcCheck(double x);
int minusSign(int pow);
long double s21_factorial(int x);
long double s21_simple_pow(double x, int n);
long double s21_pow_check(double base, double exp);

#endif  // MATH_S21_MATH_H_
