#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *longestPalindrome(char *s) {
    int length = strlen(s);
    char **tmp = (char**) malloc(sizeof(char)*length+1);
    for(int i=0;i<length;i++) {
        char *subStr = getSubString(s, i);
        
    }
}
int main(void) {
    return 0;
}