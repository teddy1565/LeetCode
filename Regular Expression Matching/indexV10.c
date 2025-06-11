#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool isMatch(char* s, char* p);

int main(void) {

    // assert(isMatch("abcdede", "ab.*de") == true);
    // assert(isMatch("bbbba", "ac*.a*ac*.*.*a*a") == true); // 1
    // assert(isMatch("bbbba", ".*a*a") == true); // 1
    // assert(isMatch("baba", "b*.*") == true); // 1
    // assert(isMatch("bcaccbbacbcbcab", "b*.c*..*.b*b*.*c*") == true); // 1
    // assert(isMatch("bcaccbbacbcbcab", "b*.c*..*.b*b*.*c*") == true); // 1
    // assert(isMatch("abb", "a.*b") == true); // 1

    // assert(isMatch("acbdb", "aa*cbdb") == true);
    // assert(isMatch("aaa", "ab*a*c*a") == true);
    // assert(isMatch("a", "ab*") == true);
    // assert(isMatch("aa", "a*") == true);


    // assert(isMatch("acbbcbcbcbaaacaac", "ac*.a*ac*.*ab*b*ac") == false); // 0
    // assert(isMatch("bbacbcabbbbbcacabb", "aa*c*b*a*.*a*a.*.") == false); // 0

    // isMatch("abcde", "b*.c*..*.b*b*.*c*");
    isMatch("abcde", "b*");
    return 0;
}

bool isMatch(char *s, char *p) {
    bool result = false;

    const int source_str_length = strlen(s);
    const int pattern_str_length = strlen(p);

    char *pattern = (char *)malloc(sizeof(char) * 25);
    memset(pattern, 0, 25);
    char *pattern_header = pattern;

    for (int i = 0; i < pattern_str_length; i++) {
        if (p[i] != '*') {
            *(pattern)++ = p[i];
        }
        if (p[i + 1] == '*') {


            pattern = pattern_header;
            printf("%s\n", pattern);
            memset(pattern, 0, 25);




        } else if (p[i + 1] == '\0') {
            pattern = pattern_header;
            printf("%s\n", pattern);
            memset(pattern, 0, 25);
        }

    }


response_answer:
    free(pattern);

    return result;
}
