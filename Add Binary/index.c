#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int a_length = strlen(a);
    int b_length = strlen(b);
    
    int c_carrier = 0;
    
    int a_index = a_length - 1;
    int b_index = b_length - 1;
    while (a_index >= 0 || b_index >= 0) {
        char a_chr = a_index < 0 ? '0' : a[a_index];
        char b_chr = b_index < 0 ? '0' : b[b_index];

        int n = ((a_chr - 48) + (b_chr - 48) + c_carrier);
        c_carrier = n / 2;

        a_index--;
        b_index--;
    }

    int c_length = (a_length > b_length ? a_length : b_length) + c_carrier;
    char *c = (char *) malloc(sizeof(char) * (c_length + 1));
    memset(c, 0, sizeof(char) * (c_length + 1));

    c_carrier = 0;
    a_index = a_length - 1;
    b_index = b_length - 1;
    int c_index = c_length - 1;
    while (a_index >= 0 || b_index >= 0 || c_index >= 0) {
        char a_chr = a_index < 0 ? '0' : a[a_index];
        char b_chr = b_index < 0 ? '0' : b[b_index];

        int n = ((a_chr - 48) + (b_chr - 48) + c_carrier);
        c_carrier = n / 2;
        c[c_index] = (n % 2) + 48;

        a_index--;
        b_index--;
        c_index--;
    }
    return c;
}
