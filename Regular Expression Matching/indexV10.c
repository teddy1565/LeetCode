#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool isMatch(char* s, char* p);

int main(void) {

    assert(isMatch("abcdede", "ab.*de") == true);
    assert(isMatch("bbbba", "ac*.a*ac*.*.*a*a") == true); // 1
    assert(isMatch("bbbba", ".*a*a") == true); // 1
    assert(isMatch("baba", "b*.*") == true); // 1
    assert(isMatch("bcaccbbacbcbcab", "b*.c*..*.b*b*.*c*") == true); // 1
    assert(isMatch("bcaccbbacbcbcab", "b*.c*..*.b*b*.*c*") == true); // 1
    assert(isMatch("abb", "a.*b") == true); // 1

    assert(isMatch("acbdb", "aa*cbdb") == true);
    assert(isMatch("aaa", "ab*a*c*a") == true);
    assert(isMatch("a", "ab*") == true);
    assert(isMatch("aa", "a*") == true);


    assert(isMatch("acbbcbcbcbaaacaac", "ac*.a*ac*.*ab*b*ac") == false); // 0
    assert(isMatch("bbacbcabbbbbcacabb", "aa*c*b*a*.*a*a.*.") == false); // 0


    return 0;
}

bool isMatch(char *s, char *p) {
    bool result = false;
    
    return result;
}
