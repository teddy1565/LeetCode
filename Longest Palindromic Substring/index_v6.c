#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IF if(
#define ELSEIF } else if (
#define ELSE } else {
#define THEN ){
#define DO ){
#define END }
#define AND &&
#define OR ||
#define WHILE while(

int len(char *s) {
    int length = 0;
    for (int i=0;s[i]!='\0';i++) {
        length++;
    }
    return length;
}
char *longestPalindrome(char *s) {
    int r=0;
    int c=0;
    WHILE c<len(s) DO
        WHILE c-(r+1) >= 0 AND c+(r+1) < len(s) AND s[c+(r+1)] == s[c-(r+1)] DO
            r = r+1;
        END
    END
    return s;
}
int main(void) {
    longestPalindrome("hello world");
    return 0;
}