#include "s21_decimal.h"
#include "support.h"

// 0 - OK
// 1 - INF
// 2 - MINF
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ret = 0;
    int overflow = 0;
    int neg = value_1.pat.sgn && value_2.pat.sgn ? 1 : 0;
    bigDecimal bigRes = {};
    bigDecimal bigVal1 = {};
    bigDecimal bigVal2 = {};

    s21_zero_exp(result);
    mntZero(result);

    mntCpyStd2Big(&value_1, &bigVal1);
    mntCpyStd2Big(&value_2, &bigVal2);

    bigNormalization(&bigVal1, &bigVal2);
    bigRes.pat.exp = bigVal1.pat.exp;

    if (!(bigVal1.pat.sgn ^ bigVal2.pat.sgn)) {
        mntBigAdd(bigVal1, bigVal2, &bigRes);
        if (fixBigOverflow(&bigRes)) overflow = 1;
        bigRes.pat.sgn = neg ? 1 : 0;
    } else {
        mntBigSub(bigVal1, bigVal2, &bigRes);
        if (fixBigOverflow(&bigRes)) overflow = 1;
        bigRes.pat.sgn = mntBigComp(bigVal1, bigVal2) == 1 ? bigVal1.pat.sgn
                                                           : bigVal2.pat.sgn;
    }

    mntCpyBig2Std(&bigRes, result);

    if (overflow) ret = result->pat.sgn ? 2 : 1;

    return ret;
}

// 0 - OK
// 1 - INF
// 2 - MINF
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ret = 0;
    int overflow = 0;
    s21_decimal zero = {};

    bigDecimal bigRes = {};
    bigDecimal bigVal1 = {};
    bigDecimal bigVal2 = {};

    s21_zero_exp(result);
    mntZero(result);

    mntCpyStd2Big(&value_1, &bigVal1);
    mntCpyStd2Big(&value_2, &bigVal2);

    bigNormalization(&bigVal1, &bigVal2);
    bigRes.pat.exp = bigVal1.pat.exp;

    if (bigVal1.pat.sgn ^ bigVal2.pat.sgn) {
        mntBigAdd(bigVal1, bigVal2, &bigRes);
        if (fixBigOverflow(&bigRes)) overflow = 1;

        bigRes.pat.sgn = bigVal1.pat.sgn ? 1 : 0;
        if (overflow) ret = bigRes.pat.sgn ? 2 : 1;
    } else {
        mntBigSub(bigVal1, bigVal2, &bigRes);
        if (fixBigOverflow(&bigRes)) overflow = 1;
        if (bigVal1.pat.sgn) bigRes.pat.sgn = !bigRes.pat.sgn;
        if (overflow) ret = bigRes.pat.sgn ? 2 : 1;
    }

    mntCpyBig2Std(&bigRes, result);

    if (overflow) ret = result->pat.sgn ? 2 : 1;

    if (!mnt_comp(*result, zero)) result->pat.sgn = 0;

    return ret;
}

// // 0 - OK
// // 1 - INF
// // 2 - MINF
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ret = 0;
    int overflow = 0;

    bigDecimal bigRes = {};
    bigDecimal bigVal1 = {};
    bigDecimal bigVal2 = {};

    s21_zero_exp(result);
    mntZero(result);

    mntCpyStd2Big(&value_1, &bigVal1);
    mntCpyStd2Big(&value_2, &bigVal2);

    bigRes.pat.exp = bigVal1.pat.exp + bigVal2.pat.exp;
    mntBigMul(bigVal1, bigVal2, &bigRes);

    if (fixBigOverflow(&bigRes)) overflow = 1;
    mntCpyBig2Std(&bigRes, result);
    if (overflow) ret = result->pat.sgn ? 2 : 1;

    return ret;
}

// // 0 - OK
// // 1 - INF
// // 2 - MINF
// // 3 - div by zero
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ret = 0;

    int overflow = 0;

    bigDecimal bigRes = {};
    bigDecimal bigVal1 = {};
    bigDecimal bigVal2 = {};
    bigDecimal remainder = {};
    bigDecimal zero = {};

    mntCpyStd2Big(&value_1, &bigVal1);
    mntCpyStd2Big(&value_2, &bigVal2);

    if (!mntBigComp(bigVal2, zero)) {
        ret = 3;
    } else {
        s21_zero_exp(result);
        mntZero(result);
        mntBigDiv(bigVal1, bigVal2, &bigRes, &remainder);
        divBigEngine(bigVal1, bigVal2, &bigRes, remainder);
        if (fixBigOverflow(&bigRes)) overflow = 1;
        mntCpyBig2Std(&bigRes, result);
        if (overflow) ret = result->pat.sgn ? 2 : 1;
    }

    return ret;
}

// // 0 - OK
// // 1 - INF
// // 2 - MINF
// // 3 - div by zero
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int ret = 0;
    int overflow = 0;

    bigDecimal bigRes = {};
    bigDecimal bigVal1 = {};
    bigDecimal bigVal2 = {};
    bigDecimal zero = {};
    bigDecimal remainder = {};

    mntCpyStd2Big(&value_1, &bigVal1);
    mntCpyStd2Big(&value_2, &bigVal2);

    if (!mntBigComp(bigVal2, zero)) {
        ret = 3;
    } else {
        s21_zero_exp(result);
        mntZero(result);
        mntBigDiv(bigVal1, bigVal2, &bigRes, &remainder);
        divBigEngine(bigVal1, bigVal2, &bigRes, remainder);
        fixBigOverflow(&bigRes);
        mntBigTruncate(&bigRes);

        mntBigMul(bigRes, bigVal2, &bigRes);
        bigRes.pat.exp = bigRes.pat.exp + bigVal2.pat.exp;

        // bigRes.pat.exp = bigVal1.pat.exp > bigVal2.pat.exp ? bigVal1.pat.exp
        //                                                    : bigVal2.pat.exp;

        bigNormalization(&bigVal1, &bigRes);
        mntBigSub(bigVal1, bigRes, &bigRes);

        bigRes.pat.sgn = bigVal1.pat.sgn & bigVal2.pat.sgn;
        if (fixBigOverflow(&bigRes)) overflow = 1;
        if (overflow) mntBigTruncate(&bigRes);
        mntCpyBig2Std(&bigRes, result);
    }

    return ret;
}
