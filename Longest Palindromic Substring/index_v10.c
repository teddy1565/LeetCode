#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct palindrome{
    int index;
    char *s;
    int length;
} palindrome;

char *lognestPalindrome(char *s) {
    int length = strlen(s);
    palindrome *P = (palindrome*)malloc(sizeof(palindrome)*length);
    for (int i=0;i<length;i++) {
        P[i].index = i;
    }
    for (int i=0;i<length;i++) {
        printf("%d ",P[i].index);
    }
    free(P);
    return s;
}

int main(void) {
    lognestPalindrome("hello world");
    return 0;
}