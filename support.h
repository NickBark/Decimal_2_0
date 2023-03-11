#ifndef SUPPORT_H
#define SUPPORT_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

typedef struct BigBitPattern {
    uint32_t mnt1 : 32;
    uint32_t mnt2 : 32;
    uint32_t mnt3 : 32;
    uint32_t mnt4 : 32;
    uint32_t mnt5 : 32;
    uint32_t mnt6 : 32;
    uint16_t null1 : 16;
    uint8_t exp : 8;
    uint16_t null2 : 7;
    uint32_t sgn : 1;
} BigBitPattern;

typedef union bigDecimal {
    unsigned int bits[7];
    BigBitPattern pat;
} bigDecimal;

enum Operations { ADD, MUL, SUB, DIV, ALL };

//----------------------------------
int isSetBit(int* num, int idx);
void setBit(int* num, int idx);
void resetBit(int* num, int idx);
void inverseBit(int* num, int idx);

int getRow(int bit);
int getCol(int bit);

void bigNormalization(bigDecimal* val1, bigDecimal* val2);
void multBigTen(bigDecimal* val);
void mntBigNorm(bigDecimal* val1, bigDecimal* val2);
int mntBigComp(bigDecimal val1, bigDecimal val2);
int fixBigOverflow(bigDecimal* val);
int mntBigDivByTen(bigDecimal dividend, bigDecimal* res, bigDecimal* remainder);

void mntBigAdd(bigDecimal val1, bigDecimal val2, bigDecimal* res);
int mntBigSub(bigDecimal val1, bigDecimal val2, bigDecimal* res);
int mntBigMul(bigDecimal val1, bigDecimal val2, bigDecimal* res);
int mntBigDiv(bigDecimal dividend, bigDecimal divisor, bigDecimal* res,
              bigDecimal* rem);
void mntBigTruncate(bigDecimal* val);
void mntBigShiftLeft(bigDecimal* val, int shift);
void mntBigShiftRight(bigDecimal* val, int shift);

// альтернатива
int mntBigDiv2(bigDecimal dividend, bigDecimal divisor, bigDecimal* res,
               bigDecimal* rem);

void divBigEngine(bigDecimal dividend, bigDecimal divisor, bigDecimal* bigRes,
                  bigDecimal remainder);
//----------------------------------

void s21_zero_exp(s21_decimal* val);
void normalozation(s21_decimal* val1, s21_decimal* val2);
int mnt_comp(s21_decimal val1, s21_decimal val2);

// Shift func

void mntShiftLeft(s21_decimal* val, int shift);
void mntShiftRight(s21_decimal* val, int shift);

// Copy func
void mntCpy(s21_decimal* val1, s21_decimal* val2);
void mntCpyBig2Std(bigDecimal* val1, s21_decimal* val2);
void mntCpyStd2Big(s21_decimal* val1, bigDecimal* val2);
void mntCpyBig2Big(bigDecimal* val1, bigDecimal* val2);

int mntAdd(s21_decimal val1, s21_decimal val2, s21_decimal* res);

int mntSub(s21_decimal val1, s21_decimal val2, s21_decimal* res);
int mntMul(s21_decimal val1, s21_decimal val2, s21_decimal* res);
int mntDiv(s21_decimal dividend, s21_decimal divisor, s21_decimal* res,
           s21_decimal* remainder);
int mntMod(s21_decimal dividend, s21_decimal divisor, s21_decimal* res);

void multByTen(s21_decimal* val);
// int mntBigDivByTen(bigDecimal dividend, bigDecimal* res,
//                    s21_decimal* remainder);

// Zero mnt func
void mntZero(s21_decimal* res);
void mntBigZero(bigDecimal* res);

// Printf func
void printBit(s21_decimal val);
void printBigBit(bigDecimal val);

void mntNorm(s21_decimal* val1, s21_decimal* val2);
int mntAddOverflow(s21_decimal val1, s21_decimal val2);
int mntMulOverflow(s21_decimal val1, s21_decimal val2);
int equalMinf(s21_decimal val1, s21_decimal val2, int operation);
int equalInf(s21_decimal val1, s21_decimal val2, int operation);

int fixOverflow(bigDecimal* val, s21_decimal* res);

int mntDiv2(s21_decimal dividend, s21_decimal divisor, s21_decimal* res,
            s21_decimal* rem);

#endif  // SUPPORT_H
