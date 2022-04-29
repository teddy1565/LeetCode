#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ctoi(char c) {
    switch(c) {
        case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
        case '9':
            return 9;
            break;
        case '0':
            return 10;
            break;
        default:
            break;
    }
    return 0;
}
int PoN(char *s, int length) {
    for (int i=0;i<length;i++) {
        if (ctoi(s[i])) {
            for (int j=i;j>=0;j--) {
                if(s[j] == '-') {
                    return -1;
                } else if (s[j] == '+') {
                    return 1;
                }
            }
        }
    }
    return 1;
}
int myAtoi(char *s) {
    int length = strlen(s);
    int positive_or_negative = PoN(s, length);
    printf("%d\n", positive_or_negative);
    return 0;
}
int main(void) {
    myAtoi("w-+14");
    myAtoi("+14");
    myAtoi("14");
    printf("%d\n",atoi("+4 with word 13"));
    printf("%d\n",atoi("41.5"));
    return 0;
}