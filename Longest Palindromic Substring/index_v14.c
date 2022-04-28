#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkDouble(char *s, int length) {
    for(int i=0;i<length;i++) {
        if (s[i] == s[i+1]) {
            return 1;
        }
    }
    return 0;
}

char *longestPalindrome(char *s) {
    int length = strlen(s);
    
    if ((length&1) == 0) {
        int l = length/2;
        int find=1;
        for(int i=0,j=length-1;i<l;i++,j--) {
            if(s[i] != s[j]) {
                find =0;
                break;
            }
        }
        if (find == 1) {
            return s;
        }
    }
    int lc=0,rc=0,maxLen=0;
    for(int i=0;i<length;i++) {
        int _len=0;
        for(int j=0;j<length;j++) {
            if(((i-j)>=0) && ((i+j)<length) && (s[i+j] == s[i-j])) {
                _len+=2;
                if (_len > maxLen) {
                    lc = i-j;
                    rc = i+j;
                    maxLen = _len;
                }
            } else {
                break;
            }
        }
    }
    if (checkDouble(s, length)) {
        for (int i=0;i<length;i++) {
            if (s[i] == s[i+1]) {
                int _len = 1;
                for (int j=0;j<length;j++) {
                    if (((i-j) >= 0) && ((i+1+j) < length) && s[i-j] == s[i+1+j]) {
                        _len+=2;
                        if (_len > maxLen) {
                            lc = i-j;
                            rc = i+1+j;
                            maxLen = _len;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    
    if (maxLen <= 2) {
        for(int i=0;i<length;i++) {
            if (s[i] == s[i+1]) {
                char *res;
                res = (char*) malloc(sizeof(char)*3);
                res[0] = s[i];
                res[1] = s[i+1];
                res[2] = '\0';
                return res;
            }
        }
    }
    char *res;
    res = (char*) malloc(sizeof(char)*maxLen);
    res[maxLen-1] = '\0';
    for(int i=lc,j=0;i<=rc;i++,j++) {
        res[j] = s[i];
    }
    return res;
}
int main(void) {
    printf("%s\n",longestPalindrome("cbba"));
    printf("%s\n",longestPalindrome("babad"));
    printf("%s\n",longestPalindrome("babacxcababc"));
    printf("%s\n",longestPalindrome("bbbbb"));
    printf("%s\n",longestPalindrome("aacabdkacaa"));
    printf("%s\n",longestPalindrome("babaddtattarrattatddetartrateedredividerb"));
    return 0;
}