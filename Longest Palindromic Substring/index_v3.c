#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestPalindrome(char *s) {
    int length = 0;
    for(int i=0;i<1000;i++) {
        if (s[i] == '\0' || s[i] == '\n') {
            break;
        }
        length++;
    }
    char **tmp = (char **) malloc(sizeof(char)*length);
    for (int i=0; i<length; i++) {
        for (int j=length-1;j>=0;j--) {
            if (j==i) {
                continue;
            }
            if (s[i] == s[j]) {
                int middle = ((j+1)/2);
                int len = 1;
                printf("%c",s[middle]);
                for(int k=1;s[middle+k] == s[middle-k];k++) {
                    printf("%c",s[middle-k]);
                    printf("%c",s[middle+k]);
                    len+=2;
                }
                printf("\n");
                printf("%d\n",len);
                break;
            }
        }
    }
    return s;
}

int main(void) {
    longestPalindrome("babac");
    return 0;
}