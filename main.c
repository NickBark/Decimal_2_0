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
    s21_decimal ppp1 = {{23, 0, 0, 0x00000000}};
    s21_decimal ppp2 = {{2, 0x00000000, 0x00000000, 0x00000000}};
    s21_decimal res = {};
    s21_decimal rem = {};
    ppp1.pat.exp = 0;
    ppp2.pat.exp = 0;

    printf("ppp1:");
    printBit(ppp1);

    printf("ppp2:");
    printBit(ppp2);

    printf("res: %u\n", s21_div(ppp1, ppp2, &res));

    printf("rest:");
    printBit(res);

    // printf("result: %d\n", s21_add(ppp1, ppp2, &res));

    // // printf("%d\n", mntMulOverflow(ppp1, ppp2));
    // // s21_add(ppp1, ppp2, &res);

    // for (int i = 0; i < 3; i++) {
    //     printf("%u\n", res.bits[i]);
    // }

    return 0;
}
