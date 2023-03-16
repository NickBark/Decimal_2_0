#include "21_test.h"

// 0 - OK
// 1 - число слишком велико или равно бесконечности
// 2 - число слишком мало или равно отрицательной бесконечности
// 3 - деление на 0

START_TEST(mod_1) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("1", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mod_2) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("12341234123456789", &v1);
  convertStr2Dec("1234123412345", &v2);
  convertStr2Dec("6789", &check);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mod_3) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("15", &v1);
  convertStr2Dec("0", &v2);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 3);
}
END_TEST

START_TEST(mod_4) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("79228162514264337593543950334", &v1);
  convertStr2Dec("1", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 0);
}
END_TEST

START_TEST(mod_5) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("0", &v2);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 3);
}
END_TEST

START_TEST(mod_6) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("79228162514264337593543950334", &v1);
  convertStr2Dec("30000", &v2);
  convertStr2Dec("10334", &check);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mod_7) {
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

START_TEST(mod_8) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("79228162513759.439503", &v1);
  convertStr2Dec("13.456", &v2);
  convertStr2Dec("6.127503", &check);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 0);  // чекнуть "0"

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mod_9) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("-792281625142675935.439503", &v1);
  convertStr2Dec("-12", &v2);
  convertStr2Dec("-7.439503", &check);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mod_10) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("1422816251", &v1);
  convertStr2Dec("15434225.244", &v2);
  convertStr2Dec("2867528.552", &check);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mod_11) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("6.375", &v1);
  convertStr2Dec("150", &v2);
  convertStr2Dec("6.375", &check);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mod_12) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("0", &v1);
  convertStr2Dec("7922824174242.62736187284334", &v2);
  convertStr2Dec("0", &check);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mod_13) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};
  s21_decimal check = {};

  convertStr2Dec("12", &v1);
  convertStr2Dec("-79228217242.62", &v2);
  convertStr2Dec("12", &check);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 0);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(res.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(mod_14) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("1.2343253424523", &v1);
  convertStr2Dec("0", &v2);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 3);
}
END_TEST

START_TEST(mod_15) {
  s21_decimal v1 = {};
  s21_decimal v2 = {};
  s21_decimal res = {};

  convertStr2Dec("-792281625142643.37593543950335", &v1);
  convertStr2Dec("0", &v2);

  ck_assert_int_eq(s21_mod(v1, v2, &res), 3);
}
END_TEST

Suite *test_mod(void) {
  Suite *s = suite_create("\033[45m-=S21_MOD=-\033[0m");
  TCase *tc = tcase_create("test_mod_tc");

  tcase_add_test(tc, mod_1);
  tcase_add_test(tc, mod_2);
  tcase_add_test(tc, mod_3);
  tcase_add_test(tc, mod_4);
  tcase_add_test(tc, mod_5);
  tcase_add_test(tc, mod_6);
  tcase_add_test(tc, mod_7);
  tcase_add_test(tc, mod_8);
  tcase_add_test(tc, mod_9);
  tcase_add_test(tc, mod_10);
  tcase_add_test(tc, mod_11);
  tcase_add_test(tc, mod_12);
  tcase_add_test(tc, mod_13);
  tcase_add_test(tc, mod_14);
  tcase_add_test(tc, mod_15);

  suite_add_tcase(s, tc);
  return s;
}