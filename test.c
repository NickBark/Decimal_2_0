#include <check.h>
#include <stdio.h>

#include "s21_decimal.h"
#include "support.h"

START_TEST(is_less) {
    s21_decimal ppp1 = {{12, 11, 10, 0x00000000}};
    s21_decimal ppp2 = {{11, 11, 10, 0x80000000}};
    ppp1.pat.exp = 7;
    ppp2.pat.exp = 7;

    ck_assert_int_eq(s21_is_less(ppp1, ppp2), 0);

    ppp1.bits[0] = 12;
    ppp1.bits[1] = 11;
    ppp1.bits[2] = 10;
    ppp1.bits[3] = 0x80000000;
    ppp1.pat.exp = 7;

    ppp2.bits[0] = 11;
    ppp2.bits[1] = 11;
    ppp2.bits[2] = 10;
    ppp2.bits[3] = 0x80000000;
    ppp2.pat.exp = 7;

    ck_assert_int_eq(s21_is_less(ppp1, ppp2), 1);

    ppp1.bits[0] = 12;
    ppp1.bits[1] = 11;
    ppp1.bits[2] = 10;
    ppp1.bits[3] = 0x80000000;
    ppp1.pat.exp = 8;

    ppp2.bits[0] = 11;
    ppp2.bits[1] = 11;
    ppp2.bits[2] = 10;
    ppp2.bits[3] = 0x80000000;
    ppp2.pat.exp = 7;

    ck_assert_int_eq(s21_is_less(ppp1, ppp2), 0);
}
END_TEST

START_TEST(add1) {
    s21_decimal ppp1 = {{12, 11, 10, 0x00000000}};
    s21_decimal ppp2 = {{11, 11, 10, 0x00000000}};
    ppp1.pat.exp = 7;
    ppp2.pat.exp = 7;
    s21_decimal res = {{3, 3, 3, 3}};
    s21_decimal check = {{23, 22, 20, 0x00000000}};
    check.pat.exp = 7;

    ck_assert_int_eq(s21_add(ppp1, ppp2, &res), 0);

    for (int i = 0; i < 4; i++) {
        ck_assert_int_eq(res.bits[i], check.bits[i]);
    }
}
END_TEST

START_TEST(add2) {
    s21_decimal ppp1 = {{12, 11, 10, 0x00000000}};
    s21_decimal ppp2 = {{11, 11, 10, 0x80000000}};
    ppp1.pat.exp = 7;
    ppp2.pat.exp = 7;
    s21_decimal res = {{3, 3, 3, 3}};
    s21_decimal check = {{1, 0, 0, 0x00000000}};
    check.pat.exp = 7;

    ck_assert_int_eq(s21_add(ppp1, ppp2, &res), 0);

    for (int i = 0; i < 4; i++) {
        ck_assert_int_eq(res.bits[i], check.bits[i]);
    }
}
END_TEST

START_TEST(add3) {
    s21_decimal ppp1 = {{12, 11, 10, 0x00000000}};
    s21_decimal ppp2 = {{11, 11, 10, 0x80000000}};
    ppp1.pat.exp = 7;
    ppp2.pat.exp = 7;
    s21_decimal res = {{3, 3, 3, 3}};
    s21_decimal check = {{1, 0, 0, 0x00000000}};
    check.pat.exp = 7;

    ck_assert_int_eq(s21_add(ppp1, ppp2, &res), 0);

    for (int i = 0; i < 4; i++) {
        ck_assert_int_eq(res.bits[i], check.bits[i]);
    }
}
END_TEST

START_TEST(add4) {
    s21_decimal ppp1 = {{12, 11, 10, 0x00000000}};
    s21_decimal ppp2 = {{11, 11, 10, 0x00000000}};
    ppp1.pat.exp = 3;
    ppp2.pat.exp = 7;
    s21_decimal res = {{3, 3, 3, 3}};
    s21_decimal check = {{120011, 110011, 100010, 0x00000000}};
    check.pat.exp = 7;

    ck_assert_int_eq(s21_add(ppp1, ppp2, &res), 0);

    for (int i = 0; i < 4; i++) {
        ck_assert_int_eq(res.bits[i], check.bits[i]);
    }
}
END_TEST

START_TEST(mul1) {
    s21_decimal v1 = {};
    s21_decimal v2 = {};
    s21_decimal res = {};
    s21_decimal check = {};

    convertStr2Dec("123452345", &v1);
    convertStr2Dec("12545", &v2);
    convertStr2Dec("1548709668025", &check);

    ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

    for (int i = 0; i < 4; i++) {
        ck_assert_int_eq(res.bits[i], check.bits[i]);
    }
}
END_TEST

START_TEST(mul2) {
    s21_decimal v1 = {};
    s21_decimal v2 = {};
    s21_decimal res = {};
    s21_decimal check = {};

    convertStr2Dec("0", &v1);
    convertStr2Dec("-123412341234", &v2);
    convertStr2Dec("-0", &check);

    ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

    for (int i = 0; i < 4; i++) {
        ck_assert_int_eq(res.bits[i], check.bits[i]);
    }
}
END_TEST

START_TEST(div1) {
    s21_decimal v1 = {};
    s21_decimal v2 = {};
    s21_decimal res = {};
    s21_decimal check = {};

    convertStr2Dec("12345.2345", &v1);
    convertStr2Dec("125.45", &v2);
    convertStr2Dec("98.40760860900757273814268633", &check);

    ck_assert_int_eq(s21_div(v1, v2, &res), 0);

    for (int i = 0; i < 4; i++) {
        ck_assert_int_eq(res.bits[i], check.bits[i]);
    }
}
END_TEST

START_TEST(div2) {
    s21_decimal v1 = {};
    s21_decimal v2 = {};
    s21_decimal res = {};
    s21_decimal check = {};

    convertStr2Dec("77777777777777777777777777777", &v1);
    convertStr2Dec("77777777777777777777777777777", &v2);
    convertStr2Dec("1", &check);

    ck_assert_int_eq(s21_div(v1, v2, &res), 0);

    for (int i = 0; i < 4; i++) {
        ck_assert_int_eq(res.bits[i], check.bits[i]);
    }
}
END_TEST

Suite *s21_decimal_suite(void) {
    Suite *suite = suite_create("s21_decimal");
    // Набор разбивается на группы тестов, разделённых по каким-либо критериям.
    TCase *tcase_core = tcase_create("Core of s21_decimal");

    // Добавление теста в группу тестов.
    tcase_add_test(tcase_core, is_less);
    tcase_add_test(tcase_core, add1);
    tcase_add_test(tcase_core, add2);
    tcase_add_test(tcase_core, add3);
    tcase_add_test(tcase_core, add4);
    tcase_add_test(tcase_core, mul1);
    tcase_add_test(tcase_core, mul2);
    tcase_add_test(tcase_core, div1);
    tcase_add_test(tcase_core, div2);

    // Добавление теста в тестовый набор.
    suite_add_tcase(suite, tcase_core);

    return suite;
}

int main() {
    int failed_count = 0;
    Suite *suite = s21_decimal_suite();
    SRunner *suite_runner = srunner_create(suite);

    srunner_run_all(suite_runner, CK_NORMAL);
    // Получаем количество проваленных тестов.
    failed_count = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    if (failed_count != 0) {
        // Сигнализируем о том, что тестирование прошло неудачно.
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
