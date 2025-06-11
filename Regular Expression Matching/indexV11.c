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
    bool answer = isMatch("baaaaacc", "c*b*ba*c*c");
    printf("answer: %d\n", answer);
    return 0;
}

bool isMatch(char *s, char *p) {

    printf("==============================================\n\n");
    printf("\t%s\n\n\t%s\n\n", s, p);
    printf("-----------------------\n\n");
    bool result = false;

    const int source_str_length = strlen(s);
    const int pattern_str_length = strlen(p);
    int patterns_size = 1;

    char **patterns = (char **)malloc(sizeof(char *) * 20);
    memset(patterns, 0, 20);

    for (int i = 0; i < 20; i++) {
        patterns[i] = (char *)malloc(sizeof(char) * 3);
        memset(patterns[i], 0, 3);
    }

    for (int i = 0, k = 0; i < pattern_str_length; i++) {
        patterns[k][0] = p[i];
        if (p[i + 1] != '*') {
            patterns[k][1] = '\0';
            k++;
            patterns_size++;
        } else {
            patterns[k][1] = '*';
            patterns[k][2] = '\0';
            k++;
            i++;
            patterns_size++;
        }
    }

    printf("pattern split result:\n");
    for (int i = 0; i < patterns_size; i++) {
        printf("%d.|  %s\n", i + 1, patterns[i]);
    }
    printf("\n");
    printf("pattern trunc result:\n");
    for (int i = 1; i < patterns_size; i++) {
        printf("%d.|\t%s\t%s\t%d\t|\n", i, patterns[i - 1], patterns[i], strcmp(patterns[i - 1], patterns[i]));
        if (patterns[i - 1][0] == '\30') {
            continue;
        } else if (strcmp(patterns[i - 1], patterns[i]) == 0 && patterns[i - 1][1] == '*') {


            patterns[i - 1][0] = '\30';
            patterns[i - 1][1] = '\0';
        } else if (
            patterns[i - 1][0] != '.' && patterns[i - 1][1] == '*' &&
            patterns[i][1] != '*' &&
            patterns[i - 1][0] == patterns[i][0]
        ) {
            printf("\t\t\t\t--(swap). %s\t%s\n", patterns[i - 1], patterns[i]);

            patterns[i - 1][1] = '\0';

            patterns[i][1] = '*';
            patterns[i][2] = '\0';

        }
    }

    printf("\n");
    printf("patterns match task:\n");

    int match_index = 0;

    for (int i = 0; i < patterns_size; i++) {
        printf("%d.|\t%s\t\t|\n", i + 1, patterns[i]);
        if (patterns[i][0] == '\30') {
            continue;
        }

        char *pattern = patterns[i];

        if (pattern[1] == '*') {
            if (pattern[0] != '.') {
                while (s[match_index] == pattern[0]) {
                    match_index++;
                }
                if (match_index == source_str_length) {
                    result = true;
                    goto response_answer;
                }
            } else {

            }
        } else {
            if (pattern[0] != '.') {
                if (s[match_index] == pattern[0]) {
                    match_index++;
                } else {
                    printf("\t\t\t|==> (no match)\tMatchIndex:%d\tpattern_char:[%c]\tsource_char:[%c]\n", match_index, pattern[0], s[match_index]);
                    goto response_answer;
                }
            } else {
                match_index++;
            }
        }
    }

response_answer:

    for (int i = 0; i < patterns_size; i++) {
        free(patterns[i]);
    }
    free(patterns);

    return result;
}
