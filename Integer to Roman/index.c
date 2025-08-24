#include "index.h"

char *intToRoman(int num) {
    char *s = (char *) malloc(sizeof(char) * 16);
    int s_index = 0;
    memset(s, 0, 16);

    if (num >= 1000) {
        for (; num >= 1000 ;) {
            s[s_index++] = 'M';
            num -= 1000;
        }
    }

    if (num >= 900) {
        s[s_index++] = 'C';
        s[s_index++] = 'M';
        num -= 900;
    }

    if (num >= 500) {
        s[s_index++] = 'D';
        num -= 500;
    }

    if (num >= 400) {
        s[s_index++] = 'C';
        s[s_index++] = 'D';
        num -= 400;
    }

    for (; num >= 100 ;) {
        s[s_index++] = 'C';
        num -= 100;
    }

    if (num >= 90) {
        s[s_index++] = 'X';
        s[s_index++] = 'C';
        num -= 90;
    }

    if (num >= 50) {
        s[s_index++] = 'L';
        num -= 50;
    }

    if (num >= 40) {
        s[s_index++] = 'X';
        s[s_index++] = 'L';
        num -= 40;
    }

    for (; num >= 10; ) {
        s[s_index++] = 'X';
        num -= 10;
    }

    if (num == 9) {
        s[s_index++] = 'I';
        s[s_index++] = 'X';
        num -= 9;
    }

    if (num >= 5) {
        s[s_index++] = 'V';
        num -= 5;
    }

    if (num == 4) {
        s[s_index++] = 'I';
        s[s_index++] = 'V';
        num -= 4;
    }

    for (; num >= 1; ) {
        s[s_index++] = 'I';
        num -= 1;
    }

    return s;
    
}

int main(void) {

    assert(intToRoman(test_case_01) == "MMMDCCXLIX");
    assert(intToRoman(test_case_02) == "LVIII");
    assert(intToRoman(test_case_03) == "MCMXCIV");

    return 0;
}