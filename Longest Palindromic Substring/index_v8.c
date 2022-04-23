#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestPalindrome(char *s) {
    
}
char *getInput(int length) {
    char *s = (char*) malloc(sizeof(char)*(length+1));
    scanf("%s", s);
    int leng = 0;
    for(int i=0;s[i]!='\0' && s[i]!='\n';i++) {
        leng++;
    }
    char *result = (char*) malloc(sizeof(char)*(leng+1));
    result[leng] = '\0';
    strcpy(result, s);
    free(s);
    return result;
}

int main(void) {
    char *s = getInput(100);
    return 0;
}