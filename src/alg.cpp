// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t res = num;
    uint64_t maxa = num;
    while (res != 1) {
        if (res % 2 == 0) {
            res = res / 2;
        } else {
            res = 3 * res + 1;
        }
        if (res > maxa) {
            maxa = res;
        }
    }
    return maxa;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int dlina = 1;
    uint64_t tek = num;
    while (tek != 1) {
        if (tek % 2 == 0) {
            tek = tek / 2;
        } else {
            tek = 3 * tek + 1;
        }
        dlina++;
    }
    return dlina;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    unsigned int max_len = 0;
    unsigned int res = 0;

    for (uint64_t ch = lbound; ch <= rbound; ++ch) {
        unsigned int len = collatzLen(ch);
        if (len > max_len) {
            max_len = len;
            res = ch;
        }
    }
    *maxlen = max_len;
    return res;
}
