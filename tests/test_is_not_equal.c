#include "21_test.h"

// 0 - FALSE
// 1 - TRUE

START_TEST(not_equal_1) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("0", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 0);
}
END_TEST

START_TEST(not_equal_2) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("1234123412345678912345678901", &v1);
  convertStr2Dec("1234123412345678912345678901", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 0);
}
END_TEST

START_TEST(not_equal_3) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("15", &v1);
  convertStr2Dec("0", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 1);
}
END_TEST

START_TEST(not_equal_4) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("79228162514264337593543950334", &v1);
  convertStr2Dec("0", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 1);
}
END_TEST

START_TEST(not_equal_5) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("0", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 0);
}
END_TEST

START_TEST(not_equal_6) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("-123412341234567891234567890", &v1);
  convertStr2Dec("123412341234567891234567890", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 1);
}
END_TEST

START_TEST(not_equal_7) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("123412341234567891234567890", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 1);
}
END_TEST

START_TEST(not_equal_8) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("79228162514264337593543950334", &v1);
  convertStr2Dec("79228162514264337593543950334", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 0);
}
END_TEST

START_TEST(not_equal_9) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("-7922816251426433759354395.334", &v1);
  convertStr2Dec("-7922816251426433759354395.334", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 0);
}
END_TEST

START_TEST(not_equal_10) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("7922816251426.37593543950334", &v1);
  convertStr2Dec("7922816.25142643334", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 1);
}
END_TEST

START_TEST(not_equal_11) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("6.375", &v1);
  convertStr2Dec("7922816.25142643334", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 1);
}
END_TEST

START_TEST(not_equal_12) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("7922824174242.62736187284334", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 1);
}
END_TEST

START_TEST(not_equal_13) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("-7922824174242.627361872843", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 1);
}
END_TEST

START_TEST(not_equal_14) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("792281625142.337593543950335", &v1);
  convertStr2Dec("792281625142.337593543950335", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 0);
}
END_TEST

START_TEST(not_equal_15) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};

  convertStr2Dec("-1", &v1);
  convertStr2Dec("-792281625.4264337593543950335", &v2);

  ck_assert_int_eq(s21_is_not_equal(v1, v2), 1);
}
END_TEST

Suite *test_not_equal(void) {
  Suite *s = suite_create("\033[45m-=S21_NOT_EQUAL=-\033[0m");
  TCase *tc = tcase_create("test_not_equal_tc");

  tcase_add_test(tc, not_equal_1);
  tcase_add_test(tc, not_equal_2);
  tcase_add_test(tc, not_equal_3);
  tcase_add_test(tc, not_equal_4);
  tcase_add_test(tc, not_equal_5);
  tcase_add_test(tc, not_equal_6);
  tcase_add_test(tc, not_equal_7);
  tcase_add_test(tc, not_equal_8);
  tcase_add_test(tc, not_equal_9);
  tcase_add_test(tc, not_equal_10);
  tcase_add_test(tc, not_equal_11);
  tcase_add_test(tc, not_equal_12);
  tcase_add_test(tc, not_equal_13);
  tcase_add_test(tc, not_equal_14);
  tcase_add_test(tc, not_equal_15);

  suite_add_tcase(s, tc);
  return s;
}