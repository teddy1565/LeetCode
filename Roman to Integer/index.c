#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
#include <assert.h>

int romanToInt(char* s) {
    char c;
    int r = 0;
    int p = 0;
    while(c = *(s++)) {
        int k = 0;
        switch(c) {
            case 'M':
                k = 1000;
                break;
            case 'C':
                k = 100;
                break;
            case 'I':
                k = 1;
                break;
            case 'D':
                k = 500;
                break;
            case 'L':
                k = 50;
                break;
            case 'X':
                k = 10;
                break;
            case 'V':
                k = 5;
                break;
        }
        if (p < k) {
            r -= p;
            r += (k-p);
        } else {
            r += k;
        }
        p = k;
    }
    return r;
}

int main(void) {
    return 0;
}