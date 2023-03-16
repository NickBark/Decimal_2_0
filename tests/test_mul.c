#include "21_test.h"

// 0 - OK
// 1 - число слишком велико или равно бесконечности
// 2 - число слишком мало или равно отрицательной бесконечности
// 3 - деление на 0

START_TEST(mul_1) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("0", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mul_2) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("1234123412345678912", &v1);
  convertStr2Dec("2", &v2);
  convertStr2Dec("2468246824691357824", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mul_3) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("15", &v1);
  convertStr2Dec("0", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mul_4) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("79228162514264337593543950334", &v1);
  convertStr2Dec("0", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mul_5) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("121213243", &v1);
  convertStr2Dec("12132341", &v2);
  convertStr2Dec("1470600397791863", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mul_6) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("79228162514264337593543950334", &v1);
  convertStr2Dec("1", &v2);
  convertStr2Dec("79228162514264337593543950334", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mul_7) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("123412341234", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mul_8) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("79228162514264337593543950334", &v1);
  convertStr2Dec("79228162514264337593543950334", &v2);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 1);
}
END_TEST

START_TEST(mul_9) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("-79228162514264337593543950334", &v1);
  convertStr2Dec("79228162514264337593543950334", &v2);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 2);
}
END_TEST

START_TEST(mul_10) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("22816251426.3950334", &v1);
  convertStr2Dec("7.251426433", &v2);
  convertStr2Dec("165450368695.3348990966778622", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mul_11) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("6.375", &v1);
  convertStr2Dec("7922816.25142644", &v2);
  convertStr2Dec("50507953.60284355500", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mul_12) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("792242.62736187284334", &v2);
  convertStr2Dec("0.00000000000000", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mul_13) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("792242.62736187284334", &v2);
  convertStr2Dec("0.00000000000000", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mul_14) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("1", &v1);
  convertStr2Dec("792242.627361872843", &v2);
  convertStr2Dec("792242.627361872843", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mul_15) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("-1", &v1);
  convertStr2Dec("72242.62736187284334", &v2);
  convertStr2Dec("-72242.62736187284334", &check);

  ck_assert_int_eq(s21_mul(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

Suite *test_mul(void) {
  Suite *s = suite_create("\033[45m-=S21_MUL=-\033[0m");
  TCase *tc = tcase_create("test_mul_tc");

  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);
  tcase_add_test(tc, mul_4);
  tcase_add_test(tc, mul_5);
  tcase_add_test(tc, mul_6);
  tcase_add_test(tc, mul_7);
  tcase_add_test(tc, mul_8);
  tcase_add_test(tc, mul_9);
  tcase_add_test(tc, mul_10);
  tcase_add_test(tc, mul_11);
  tcase_add_test(tc, mul_12);
  tcase_add_test(tc, mul_13);
  tcase_add_test(tc, mul_14);
  tcase_add_test(tc, mul_15);

  suite_add_tcase(s, tc);
  return s;
}