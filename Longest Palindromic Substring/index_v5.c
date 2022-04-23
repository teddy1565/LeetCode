#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *subString(char *s,int index) {
    int length = 1;
    int start = index;
    int end = index;
    for (int offset=0; s[index+offset] == s[index-offset]; offset++) {
        length+=2;
        start -= offset;
        end += offset;
    }
    char *result = (char*) malloc(sizeof(char) * (length+1));
    result[length-1] = '\0';
    for (int i=start,j=0;i<=end;i++,j++) {
        result[j] = s[i];
    }
    return result;
}
char *longestPalindrome(char *s) {
    char *ss = subString(s,0);
    printf("%s\n", ss);
    return s;
}
int main(void) {
    longestPalindrome("babac");
    return 0;
}