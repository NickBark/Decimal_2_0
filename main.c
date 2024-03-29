#include <stdio.h>
#include <stdlib.h>

// #include "s21_decimal.h"
#include "support.h"

int will_overflow(int a, int b) {
    if (a == 0 || b == 0) {
        // переполнение не может произойти, если один из операндов равен нулю
        return 0;
    }

    if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
        // знаки операндов совпадают, переполнение может произойти
        int max_value = INT_MAX / a;
        if (max_value < b) {
            return 1;
        }
    }

    return 0;
}

int main() {
    s21_decimal v1 = {};
    s21_decimal v2 = {};
    s21_decimal res = {};
    s21_decimal check = {};

    convertStr2Dec("79228162513759.439503", &v1);
    convertStr2Dec("13.456", &v2);
    convertStr2Dec("6.127503", &check);

    s21_mod(v1, v2, &res);
    printBit(res);

    // s21_decimal v1 = {};
    // s21_decimal v2 = {};
    // s21_decimal result = {};

    // convertStr2Dec("77777777777777777777777777777", &v1);
    // convertStr2Dec("77777777777777777777777777777", &v2);

    // s21_div(v1, v2, &result);

    // printBit(result);
    // printf("\n\n\n");

    // s21_decimal a = {};
    // s21_decimal b = {};
    // s21_decimal r = {};

    // convertStr2Dec("12345.2345", &a);
    // convertStr2Dec("125.45", &b);

    // printBit(a);
    // printBit(b);

    // s21_div(a, b, &r);

    // printBit(r);

    // s21_decimal ppp1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0x00000000}};
    // s21_decimal ppp2 = {{15000, 0x00000000, 0x00000000, 0x00000000}};
    // s21_decimal res = {};
    // // s21_decimal rem = {};
    // ppp1.pat.exp = 0;
    // ppp2.pat.exp = 0;

    // printf("ppp1:");
    // printBit(ppp1);

    // printf("ppp2:");
    // printBit(ppp2);

    // printf("res: %u\n", s21_div(ppp1, ppp2, &res));
    // // printf("%u\n", res.pat.mnt1);
    // printf("rest:");
    // printBit(res);
    // printf("exp of res: %u\n", res.pat.exp);

    // // printf("result: %d\n", s21_add(ppp1, ppp2, &res));

    // // printf("%d\n", mntMulOverflow(ppp1, ppp2));
    // // s21_add(ppp1, ppp2, &res);

    // for (int i = 0; i < 3; i++) {
    //     printf("%u\n", res.bits[i]);
    // }

    return 0;
}
