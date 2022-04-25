#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *longestPalindrome(char *s) {
    int lc=0, rc=0;
    int length = strlen(s);
    int maxLength = 0;
    if (length&1) {
        for (int current = 0; current < length; current++) {
            int _maxLength = 0;
            for (int offset=0; offset < length; offset++) {
                if (s[current+offset] == s[current-offset] && (current-offset) >= 0) {
                    _maxLength += 2;
                    if (_maxLength > maxLength) {
                        maxLength = _maxLength;
                        lc = current-offset;
                        rc = current+offset;
                    }
                }
            }
        }
    }
    printf("%d\n", maxLength);
    printf("%d %d\n", lc, rc);
    return s;
}
int main(void) {
    longestPalindrome("cdd");
    return 0;
}