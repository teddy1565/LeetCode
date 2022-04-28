#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int checkNext(char *s, int length) {
    length = length-1;
    for(int i=0;i<length;i++) {
        if(s[i] == s[i+1]) {
            return 1;
        }
    }
    return 0;
}
char *lognestPalindrome(char *s) {
    int length = strlen(s);
    if (checkNext(s, length)) {
        length = length-1;
        for(int i=0;i<length;i++) {
            if(s[i] == s[i+1]) {
                char *res = (char*)malloc(sizeof(char)*3);
                res[0] = s[i];
                res[1] = s[i+1];
                res[2] = '\0';
                return res;
            }
        }
    }
    int lc=0,rc=0;
    int maxLen = 0;
    for (int i=0;i<length;i++) {
        int _len = 0;
        for (int j=0;j<length;j++) {
            if (s[i-j] == s[i+j]) {
                _len+=2;
                if (_len > maxLen) {
                    lc = i-j;
                    rc = i+j;
                    maxLen = _len;
                }
            }
        }
    }
    for (int i=lc;i<=rc;i++) {
        printf("%c", s[i]);
    }
    printf("\n");
    return s;
}

int main(void) {
    lognestPalindrome("babac");
    return 0;
}   