#include "21_test.h"

// 0 - OK
// 1 - число слишком велико или равно бесконечности
// 2 - число слишком мало или равно отрицательной бесконечности
// 3 - деление на 0

START_TEST(sub_1) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("0", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(sub_2) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("1234123412345678912345678901", &v1);
  convertStr2Dec("1234123412345678912345678901", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(sub_3) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("15", &v1);
  convertStr2Dec("0", &v2);
  convertStr2Dec("15", &check);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(sub_4) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("79228162514264337593543950334", &v1);
  convertStr2Dec("1", &v2);
  convertStr2Dec("79228162514264337593543950333", &check);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(sub_5) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("0", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(sub_6) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("-1234123412345678912", &v1);
  convertStr2Dec("12341234123456789", &v2);
  convertStr2Dec("-1246464646469135701", &check);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(sub_7) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("123412341234567891234567890", &v2);
  convertStr2Dec("-123412341234567891234567890", &check);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(sub_8) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("79228162514264337593543950334", &v1);
  convertStr2Dec("-79228162514264337593543950334", &v2);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 1);
}
END_TEST

START_TEST(sub_9) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("-79228162514264337593543950334", &v1);
  convertStr2Dec("79228162514264337593543950334", &v2);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 2);
}
END_TEST

START_TEST(sub_10) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("7922816251426.37593543950334", &v1);
  convertStr2Dec("7922816.25142643334", &v2);
  convertStr2Dec("7922808328610.12450900616334", &check);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(sub_11) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("6.375", &v1);
  convertStr2Dec("7922816.25142643334", &v2);
  convertStr2Dec("-7922809.87642643334", &check);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(sub_12) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("7922824174242.62736187284334", &v2);
  convertStr2Dec("-7922824174242.62736187284334", &check);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(sub_13) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("-7922824174242.627361872843", &v2);
  convertStr2Dec("7922824174242.627361872843", &check);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(sub_14) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("-1", &v1);
  convertStr2Dec("-79228162514264337593543950335", &v2);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 0);
}
END_TEST

START_TEST(sub_15) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("1", &v1);
  convertStr2Dec("-79228162514264337593543950335", &v2);

  ck_assert_int_eq(s21_sub(v1, v2, &res), 1);
}
END_TEST

Suite *test_sub(void) {
  Suite *s = suite_create("\033[45m-=S21_SUB=-\033[0m");
  TCase *tc = tcase_create("test_sub_tc");

  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_3);
  tcase_add_test(tc, sub_4);
  tcase_add_test(tc, sub_5);
  tcase_add_test(tc, sub_6);
  tcase_add_test(tc, sub_7);
  tcase_add_test(tc, sub_8);
  tcase_add_test(tc, sub_9);
  tcase_add_test(tc, sub_10);
  tcase_add_test(tc, sub_11);
  tcase_add_test(tc, sub_12);
  tcase_add_test(tc, sub_13);
  tcase_add_test(tc, sub_14);
  tcase_add_test(tc, sub_15);

  suite_add_tcase(s, tc);
  return s;
}