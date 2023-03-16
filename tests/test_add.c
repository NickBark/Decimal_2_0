#include "21_test.h"

// 0 - OK
// 1 - число слишком велико или равно бесконечности
// 2 - число слишком мало или равно отрицательной бесконечности
// 3 - деление на 0

START_TEST(add_1) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("0", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_add(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(add_2) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("1234123412345678912345678901", &v1);
  convertStr2Dec("1234123412345678912345678901", &v2);
  convertStr2Dec("2468246824691357824691357802", &check);

  ck_assert_int_eq(s21_add(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(add_3) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("15", &v1);
  convertStr2Dec("0", &v2);
  convertStr2Dec("15", &check);

  ck_assert_int_eq(s21_add(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(add_4) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("79228162514264337593543950334", &v1);
  convertStr2Dec("0", &v2);
  convertStr2Dec("79228162514264337593543950334", &check);

  ck_assert_int_eq(s21_add(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(add_5) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("0", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_add(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(add_6) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("-123412341234567891234567890", &v1);
  convertStr2Dec("123412341234567891234567890", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_add(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(add_7) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("123412341234567891234567890", &v2);
  convertStr2Dec("123412341234567891234567890", &check);

  ck_assert_int_eq(s21_add(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(add_8) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("79228162514264337593543950334", &v1);
  convertStr2Dec("79228162514264337593543950334", &v2);

  ck_assert_int_eq(s21_add(v1, v2, &res), 1);
}
END_TEST

START_TEST(add_9) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("-79228162514264337593543950334", &v1);
  convertStr2Dec("-79228162514264337593543950334", &v2);

  ck_assert_int_eq(s21_add(v1, v2, &res), 2);
}
END_TEST

START_TEST(add_10) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("7922816251426.37593543950334", &v1);
  convertStr2Dec("7922816.25142643334", &v2);
  convertStr2Dec("7922824174242.62736187284334", &check);

  ck_assert_int_eq(s21_add(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(add_11) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("6.375", &v1);
  convertStr2Dec("7922816.25142643334", &v2);
  convertStr2Dec("7922822.62642643334", &check);

  ck_assert_int_eq(s21_add(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(add_12) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("7922824174242.62736187284334", &v2);
  convertStr2Dec("7922824174242.62736187284334", &check);

  ck_assert_int_eq(s21_add(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(add_13) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("-7922824174242.627361872843", &v2);
  convertStr2Dec("-7922824174242.627361872843", &check);

  ck_assert_int_eq(s21_add(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(add_14) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("1", &v1);
  convertStr2Dec("79228162514264337593543950335", &v2);

  ck_assert_int_eq(s21_add(v1, v2, &res), 1);
}
END_TEST

START_TEST(add_15) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("-1", &v1);
  convertStr2Dec("-79228162514264337593543950335", &v2);

  ck_assert_int_eq(s21_add(v1, v2, &res), 2);
}
END_TEST

Suite *test_add(void) {
  Suite *s = suite_create("\033[45m-=S21_ADD=-\033[0m");
  TCase *tc = tcase_create("test_add_tc");

  tcase_add_test(tc, add_1);
  tcase_add_test(tc, add_2);
  tcase_add_test(tc, add_3);
  tcase_add_test(tc, add_4);
  tcase_add_test(tc, add_5);
  tcase_add_test(tc, add_6);
  tcase_add_test(tc, add_7);
  tcase_add_test(tc, add_8);
  tcase_add_test(tc, add_9);
  tcase_add_test(tc, add_10);
  tcase_add_test(tc, add_11);
  tcase_add_test(tc, add_12);
  tcase_add_test(tc, add_13);
  tcase_add_test(tc, add_14);
  tcase_add_test(tc, add_15);

  suite_add_tcase(s, tc);
  return s;
}