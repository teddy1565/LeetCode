#include "index.h"

char *intToRoman(int num) {
    char *s = (char *) malloc(sizeof(char) * 16);
    char *res = s;
    memset(s, 0, 16);

    if (num >= 1000) {
        for (; num >= 1000 ;) {
            *(s++) = 'M';
            num -= 1000;
        }
    }

    if (num >= 900) {
        *(s++) = 'C';
        *(s++) = 'M';
        num -= 900;
    }

    if (num >= 500) {
        *(s++) = 'D';
        num -= 500;
    }

    if (num >= 400) {
        *(s++) = 'C';
        *(s++) = 'D';
        num -= 400;
    }

    for (; num >= 100 ;) {
        *(s++) = 'C';
        num -= 100;
    }

    if (num >= 90) {
        *(s++) = 'X';
        *(s++) = 'C';
        num -= 90;
    }

    if (num >= 50) {
        *(s++) = 'L';
        num -= 50;
    }

    if (num >= 40) {
        *(s++) = 'X';
        *(s++) = 'L';
        num -= 40;
    }

    for (; num >= 10; ) {
        *(s++) = 'X';
        num -= 10;
    }

    if (num == 9) {
        *(s++) = 'I';
        *(s++) = 'X';
        num -= 9;
    }

    if (num >= 5) {
        *(s++) = 'V';
        num -= 5;
    }

    if (num == 4) {
        *(s++) = 'I';
        *(s++) = 'V';
        num -= 4;
    }

    for (; num >= 1; ) {
        *(s++) = 'I';
        num -= 1;
    }

    return res;
    
}

int main(void) {

    assert(intToRoman(test_case_01) == "MMMDCCXLIX");
    assert(intToRoman(test_case_02) == "LVIII");
    assert(intToRoman(test_case_03) == "MCMXCIV");

    return 0;
}