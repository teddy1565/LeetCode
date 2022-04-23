#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *preProcess(char *s,int index) {
    int length = 1;
    int start = index;
    int end = index;
    for(int offset=1;s[index+offset] == s[index-offset];offset++) {
        length+=2;
        start-=offset;
        end+=offset;
    }
    char *tmp = (char*) malloc(sizeof(char)*(length+1));
    tmp[length] = '\0';
    for(int i=start,j=0;i<=end;i++,j++) {
        tmp[j] = s[i];
    }
    return tmp;
}

char *lognestPalindrome(char *s) {
    int length = 0;
    for (int i=0;s[i]!='\0';i++) {
        length++;
    }
    for (int i=0;i<length;i++) {
        char *afterProcess = preProcess(s,i);
        printf("%s\n", afterProcess);
    }
    return s;
}
int main(void) {
    lognestPalindrome("babac");
    return 0;
}
