#include "21_test.h"

// 0 - OK
// 1 - число слишком велико или равно бесконечности
// 2 - число слишком мало или равно отрицательной бесконечности
// 3 - деление на 0

START_TEST(div_1) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("1", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_div(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(div_2) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("800000000000000000", &v1);
  convertStr2Dec("500000000", &v2);
  convertStr2Dec("1600000000", &check);

  ck_assert_int_eq(s21_div(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(div_3) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("15", &v1);
  convertStr2Dec("0", &v2);

  ck_assert_int_eq(s21_div(v1, v2, &res), 3);
}
END_TEST

START_TEST(div_4) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("79228162514264337593543950334", &v1);
  convertStr2Dec("1", &v2);
  convertStr2Dec("79228162514264337593543950334", &check);

  ck_assert_int_eq(s21_div(v1, v2, &res), 0);
}
END_TEST

START_TEST(div_5) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("0", &v2);

  ck_assert_int_eq(s21_div(v1, v2, &res), 3);
}
END_TEST

START_TEST(div_6) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("-1234123412345678", &v1);
  convertStr2Dec("2", &v2);
  convertStr2Dec("-617061706172839", &check);

  ck_assert_int_eq(s21_div(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(div_7) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("79228162514264337593543950334", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(div_8) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("1", &v1);
  convertStr2Dec("79228162514264337593543950334", &v2);

  ck_assert_int_eq(s21_div(v1, v2, &res), 0);  // чекнуть "0"
}
END_TEST

START_TEST(div_9) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("-1", &v1);
  convertStr2Dec("79228162514264337593543950334", &v2);

  ck_assert_int_eq(s21_div(v1, v2, &res), 0);  // чекнуть "0"
}
END_TEST

START_TEST(div_10) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("1422816251", &v1);
  convertStr2Dec("15434225.244", &v2);
  convertStr2Dec("92.18579024905151889592314414", &check);

  ck_assert_int_eq(s21_div(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(div_11) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("6.375", &v1);
  convertStr2Dec("150", &v2);
  convertStr2Dec("0.0425", &check);

  ck_assert_int_eq(s21_div(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(div_12) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("7922824174242.62736187284334", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_div(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(div_13) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("-79228217242.627361872843", &v2);
  convertStr2Dec("-0", &check);

  ck_assert_int_eq(s21_div(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(div_14) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("1.2343253424523", &v1);
  convertStr2Dec("0", &v2);

  ck_assert_int_eq(s21_div(v1, v2, &res), 3);
}
END_TEST

START_TEST(div_15) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("-792281625142643.37593543950335", &v1);
  convertStr2Dec("0", &v2);

  ck_assert_int_eq(s21_div(v1, v2, &res), 3);
}
END_TEST

Suite *test_div(void) {
  Suite *s = suite_create("\033[45m-=S21_DIV=-\033[0m");
  TCase *tc = tcase_create("test_div_tc");

  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_5);
  tcase_add_test(tc, div_6);
  tcase_add_test(tc, div_7);
  tcase_add_test(tc, div_8);
  tcase_add_test(tc, div_9);
  tcase_add_test(tc, div_10);
  tcase_add_test(tc, div_11);
  tcase_add_test(tc, div_12);
  tcase_add_test(tc, div_13);
  tcase_add_test(tc, div_14);
  tcase_add_test(tc, div_15);

  suite_add_tcase(s, tc);
  return s;
}