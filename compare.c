#include "s21_decimal.h"
#include "support.h"

int s21_is_less(s21_decimal val1, s21_decimal val2) {
    int res = 0;
    int neg = 0;
    int comp = 0;
    bigDecimal v1 = {};
    bigDecimal v2 = {};

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    mntCpyStd2Big(&val1, &v1);
    mntCpyStd2Big(&val2, &v2);

    neg = val1.pat.sgn && val2.pat.sgn ? 1 : 0;
    comp = mnt_comp(val1, val2);

    if (!val1.pat.mnt1 && !val1.pat.mnt2 && !val1.pat.mnt3 && !comp) {
        res = 0;
    } else if (val1.pat.sgn && !val2.pat.sgn) {
        res = 1;
    } else if (!val1.pat.sgn && val2.pat.sgn) {
        res = 0;
    } else if (!comp) {
        if (val1.pat.exp > val2.pat.exp)
            res = neg ? 0 : 1;
        else if (val1.pat.exp < val2.pat.exp)
            res = neg ? 1 : 0;
        else
            res = 0;
    } else if (val1.pat.exp == val2.pat.exp) {
        res = (comp == 2) ? 1 : 0;
        if (neg && comp != 0) res = !res;
    } else {
        bigNormalization(&v1, &v2);
        comp = mntBigComp(v1, v2);
        res = (comp == 2) ? 1 : 0;
        if (neg && comp != 0) res = !res;
    }

    return res;
}

int s21_is_less_or_equal(s21_decimal val1, s21_decimal val2) {
    int res = 0;
    int neg = 0;
    int comp = 0;

    bigDecimal v1 = {};
    bigDecimal v2 = {};

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    mntCpyStd2Big(&val1, &v1);
    mntCpyStd2Big(&val2, &v2);

    neg = val1.pat.sgn && val2.pat.sgn ? 1 : 0;
    comp = mnt_comp(val1, val2);

    if (!val1.pat.mnt1 && !val1.pat.mnt2 && !val1.pat.mnt3 && !comp) {
        res = 1;
    } else if (val1.pat.sgn && !val2.pat.sgn) {
        res = 1;
    } else if (!val1.pat.sgn && val2.pat.sgn) {
        res = 0;
    } else if (!comp) {
        if (val1.pat.exp > val2.pat.exp)
            res = neg ? 0 : 1;
        else if (val1.pat.exp < val2.pat.exp)
            res = neg ? 1 : 0;
        else
            res = 1;
    } else if (val1.pat.exp == val2.pat.exp) {
        res = (comp == 2 || comp == 0) ? 1 : 0;
        if (neg && comp != 0) res = !res;
    } else {
        bigNormalization(&v1, &v2);
        comp = mntBigComp(v1, v2);
        res = (comp == 2 || comp == 0) ? 1 : 0;
        if (neg && comp != 0) res = !res;
    }

    return res;
}

int s21_is_greater(s21_decimal val1, s21_decimal val2) {
    int res = 0;
    int neg = 0;
    int comp = 0;

    bigDecimal v1 = {};
    bigDecimal v2 = {};

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    mntCpyStd2Big(&val1, &v1);
    mntCpyStd2Big(&val2, &v2);

    neg = val1.pat.sgn && val2.pat.sgn ? 1 : 0;
    comp = mnt_comp(val1, val2);

    if (!val1.pat.mnt1 && !val1.pat.mnt2 && !val1.pat.mnt3 && !comp) {
        res = 0;
    } else if (val1.pat.sgn && !val2.pat.sgn) {
        res = 0;
    } else if (!val1.pat.sgn && val2.pat.sgn) {
        res = 1;
    } else if (!comp) {
        if (val1.pat.exp > val2.pat.exp)
            res = neg ? 1 : 0;
        else if (val1.pat.exp < val2.pat.exp)
            res = neg ? 0 : 1;
        else
            res = 0;
    } else if (val1.pat.exp == val2.pat.exp) {
        res = (comp == 1) ? 1 : 0;
        if (neg && comp != 0) res = !res;
    } else {
        bigNormalization(&v1, &v2);
        comp = mntBigComp(v1, v2);
        res = (comp == 1) ? 1 : 0;
        if (neg && comp != 0) res = !res;
    }

    return res;
}

int s21_is_greater_or_equal(s21_decimal val1, s21_decimal val2) {
    int res = 0;
    int neg = 0;
    int comp = 0;

    bigDecimal v1 = {};
    bigDecimal v2 = {};

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    mntCpyStd2Big(&val1, &v1);
    mntCpyStd2Big(&val2, &v2);

    neg = val1.pat.sgn && val2.pat.sgn ? 1 : 0;
    comp = mnt_comp(val1, val2);

    if (!val1.pat.mnt1 && !val1.pat.mnt2 && !val1.pat.mnt3 && !comp) {
        res = 1;
    } else if (val1.pat.sgn && !val2.pat.sgn) {
        res = 0;
    } else if (!val1.pat.sgn && val2.pat.sgn) {
        res = 1;
    } else if (!comp) {
        if (val1.pat.exp > val2.pat.exp)
            res = neg ? 1 : 0;
        else if (val1.pat.exp < val2.pat.exp)
            res = neg ? 0 : 1;
        else
            res = 1;
    } else if (val1.pat.exp == val2.pat.exp) {
        res = (comp == 1 || comp == 0) ? 1 : 0;
        if (neg && comp != 0) res = !res;
    } else {
        bigNormalization(&v1, &v2);
        comp = mntBigComp(v1, v2);
        res = (comp == 1 || comp == 0) ? 1 : 0;
        if (neg && comp != 0) res = !res;
    }

    return res;
}

int s21_is_equal(s21_decimal val1, s21_decimal val2) {
    int res = 0;
    int comp = 0;

    bigDecimal v1 = {};
    bigDecimal v2 = {};

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    mntCpyStd2Big(&val1, &v1);
    mntCpyStd2Big(&val2, &v2);

    comp = mnt_comp(val1, val2);

    if (!val1.pat.mnt1 && !val1.pat.mnt2 && !val1.pat.mnt3 && !comp) {
        res = 1;
    } else if (val1.pat.sgn && !val2.pat.sgn) {
        res = 0;
    } else if (!val1.pat.sgn && val2.pat.sgn) {
        res = 0;
    } else if (!comp) {
        if (val1.pat.exp > val2.pat.exp)
            res = 0;
        else if (val1.pat.exp < val2.pat.exp)
            res = 0;
        else
            res = 1;
    } else if (val1.pat.exp == val2.pat.exp) {
        res = (comp == 0) ? 1 : 0;
    } else {
        bigNormalization(&v1, &v2);
        comp = mntBigComp(v1, v2);
        res = (comp == 0) ? 1 : 0;
    }

    return res;
}

int s21_is_not_equal(s21_decimal val1, s21_decimal val2) {
    int res = 0;
    int comp = 0;

    bigDecimal v1 = {};
    bigDecimal v2 = {};

    s21_zero_exp(&val1);
    s21_zero_exp(&val2);

    mntCpyStd2Big(&val1, &v1);
    mntCpyStd2Big(&val2, &v2);

    comp = mnt_comp(val1, val2);

    if (!val1.pat.mnt1 && !val1.pat.mnt2 && !val1.pat.mnt3 && !comp) {
        res = 0;
    } else if (val1.pat.sgn && !val2.pat.sgn) {
        res = 1;
    } else if (!val1.pat.sgn && val2.pat.sgn) {
        res = 1;
    } else if (!comp) {
        if (val1.pat.exp > val2.pat.exp)
            res = 1;
        else if (val1.pat.exp < val2.pat.exp)
            res = 1;
        else
            res = 0;
    } else if (val1.pat.exp == val2.pat.exp) {
        res = (comp == 0) ? 0 : 1;
    } else {
        bigNormalization(&v1, &v2);
        comp = mntBigComp(v1, v2);
        res = (comp == 0) ? 0 : 1;
    }

    return res;
}
