#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *longestPalindrome(char *s) {
    int length = 0;
    
    for(int i=0;s[i]!='\0';i++) {
        length++;
    }
    char **tmp = (char**) malloc(sizeof(char) * length);

    for (int i=0;i<length;i++) {
        int len = 1;
        int start = 0;
        int end = 0;
        for (int offset=1;s[i-offset] == s[i+offset]; offset++) {
            len+=2;
            start = i-offset;
            end = i+offset;
        }
        tmp[i] = (char*) malloc(sizeof(char) * (len+1));
        tmp[i][len-1] = '\0';
        for (int j=start,k=0;j<=end;j++,k++) {
            tmp[i][k] = s[j];
        }
        printf("%s\n",tmp[i]);
    }
    return s;
}

int main(void) {
    longestPalindrome("hello world");
    return 0;
}