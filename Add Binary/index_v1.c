#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int a_length = strlen(a);
    int b_length = strlen(b);
    if (b_length > a_length) {
        char *tmp = b;
        b = a;
        a = tmp;
        int tmp_length = b_length;
        b_length = a_length;
        a_length = tmp_length;
    }
    int c_length = (a_length > b_length ? a_length : b_length) + 1;
    char *c = (char *) malloc(sizeof(char) * (c_length + 1));
    memset(c, 0, sizeof(char) * (c_length + 1));

    int p = 0;
    int k = c_length - 1;
    for (int i = a_length - 1; i >= 0; i--, k--) {
        c[k] = a[i];
    }
    
    k = c_length - 1;
    for (int i = b_length - 1; i >= 0; i--, k--) {
        int n = (c[k] - 48) + (b[i] - 48);
        int m = n + p;
        p = (m / 2);
        n = m % 2;
        c[k] = (n + 48);
    }

    if (p == 1 && k > 0) {
        int n = ((c[k] - 48) + p) % 2;
        int m = ((c[k] - 48) + p) / 2;
        
        c[k] = (n + 48);
        c[k - 1] = (m + 48);

    } else if (p == 1 && k == 0) {
        c[0] = '1';
    } else if (p == 0) {
        int count = 0;
        for (int i = 0, l = 0; i < c_length; i++) {
            if (c[i] != '\0') {
                break;
            }
            count++;
        }
        printf("count: %d\n", count);
        printf("c_length: %d\n", c_length);
        strcpy(c, &(c[count]));
    }
    
    printf("%d\n", k);
    printf("%s\n", c);
    printf("%d\n", p);
    return c;
}