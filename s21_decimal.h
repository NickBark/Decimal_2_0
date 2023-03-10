#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

//--- удалить позже
#include <stdio.h>
//---

#include <limits.h>
#include <math.h>
#include <stdint.h>  // для максимальных, минимальных значений и для типов (uint)
#include <stdlib.h>

#define S21_NAN 0.0 / 0.0
#define S21_INF 1.0 / 0.0
#define S21_MINF -1.0 / 0.0

// typedef struct s21_decimal { // промежуточный этап, нуежен по тз или нет ?
//     int bits[4];
// } s21_decimal;

typedef struct BitPattern {
    uint32_t mnt1 : 32;
    uint32_t mnt2 : 32;
    uint32_t mnt3 : 32;
    uint16_t null1 : 16;
    uint8_t exp : 8;
    uint16_t null2 : 7;
    uint32_t sgn : 1;
} BitPattern;

typedef union s21_decimal {
    unsigned int bits[4];
    BitPattern pat;
} s21_decimal;

//Операторы сравнение
int s21_is_less(s21_decimal val1, s21_decimal val2);
int s21_is_less_or_equal(s21_decimal val1, s21_decimal val2);
int s21_is_greater(s21_decimal val1, s21_decimal val2);
int s21_is_greater_or_equal(s21_decimal val1, s21_decimal val2);
int s21_is_equal(s21_decimal val1, s21_decimal val2);
int s21_is_not_equal(s21_decimal val1, s21_decimal val2);

//Арифметические операторы
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

#endif  // S21_DECIMAL_H
