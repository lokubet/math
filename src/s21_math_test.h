#ifndef SRC_S21_MATH_TEST_H_
#define SRC_S21_MATH_TEST_H_

#include <check.h>

#include "math.h"
#include "s21_math.h"

void case_test(Suite *s, int *fail);
Suite *cos_suite(void);
Suite *sin_suite(void);
Suite *acos_suite(void);
Suite *asin_suite(void);
Suite *atan_suite(void);
Suite *sqrt_suite(void);
Suite *fabs_suite(void);
Suite *floor_suite(void);
Suite *ceil_suite(void);
Suite *abs_suite(void);
Suite *tan_suite(void);
Suite *exp_suite(void);
Suite *log_suite(void);
Suite *fmod_suite(void);
Suite *pow_suite(void);

#endif  // SRC_S21_MATH_TEST_H_
