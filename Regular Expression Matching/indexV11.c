#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


bool isMatch_no_display_ver(char *s, char *p) {

    bool result = false;

    const int source_str_length = strlen(s);
    const int pattern_str_length = strlen(p);

    int patterns_size = 0;

    char **patterns = (char **)malloc(sizeof(char *) * 20);
    memset(patterns, 0, 20);


    for (int i = 0; i < pattern_str_length; i++) {
        if (p[i] == '*') {
            goto after_find_pattern_checked;
        }
    }

    if (source_str_length != pattern_str_length) {
        goto only_response_result;
    } else {
        for (int i = 0; i < source_str_length; i++) {
            if (s[i] != p[i] && p[i] != '.') {
                goto only_response_result;
            }
        }
        result = true;
        goto only_response_result;
    }

after_find_pattern_checked:

    if (pattern_str_length == 2 && p[0] == '.' && p[1] == '*') {
        result = true;
        goto only_response_result;
    } else if (pattern_str_length == 2 && p[1] == '*') {
        for (int i = 0; i < source_str_length; i++) {
            if (s[i] != p[0]) {
                goto after_special_case_checked;
            }
        }
        result = true;
        goto only_response_result;
    }




after_special_case_checked:

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
    for (int i = 1; i < patterns_size; i++) {
        if (patterns[i - 1][0] == '\30') {
            continue;
        } else if (strcmp(patterns[i - 1], patterns[i]) == 0 && patterns[i - 1][1] == '*') {


            patterns[i - 1][0] = '\30';
            patterns[i - 1][1] = '\0';
        } else if (
            patterns[i - 1][0] != '.' && patterns[i - 1][1] == '*' &&
            patterns[i][1] != '*' &&
            (patterns[i - 1][0] == patterns[i][0])
        ) {

            char temp_swap = patterns[i - 1][0];
            patterns[i - 1][0] = patterns[i][0];
            patterns[i - 1][1] = '\0';

            patterns[i][0] = temp_swap;
            patterns[i][1] = '*';
            patterns[i][2] = '\0';

        }
    }

    int match_index = 0;

    for (int i = 0; i < patterns_size; i++) {
        if (patterns[i][0] == '\30' || patterns[i][0] == '\0') {
            continue;
        }

        char *pattern = patterns[i];

        if (pattern[1] == '*') {
            if (pattern[0] != '.') {
                char *snapshot_pattern = (char *) malloc(sizeof(char) * 25);
                char *source_str_cpy = (char *)malloc(sizeof(char) * 25);

                memset(snapshot_pattern, 0, 25);
                memset(source_str_cpy, 0, 25);
                strcpy(source_str_cpy, s);
                char *source_str_cpy_header = source_str_cpy;


                for (int m = i + 1; m < patterns_size; m++) {

                    if (patterns[m][0] == pattern[0] && patterns[m][1] == '*') {
                        break;
                    }
                    strcat(snapshot_pattern, patterns[m]);
                    // i = m;
                }

                for (int m = 0; m < match_index; m++) {
                    char temp = *(source_str_cpy)++;
                }
                for (int m = match_index; m < source_str_length; m++) {
                    if (s[m] != pattern[0]) {
                        break;
                    }
                    bool match_result = isMatch_no_display_ver(source_str_cpy, snapshot_pattern);

                    if (match_result == true) {
                        match_index = m;
                        goto matched_signle_chr_with_star;
                    }

                    char temp = *(source_str_cpy)++;
                }
                while(match_index < source_str_length && pattern[0] == s[match_index]) {
                    match_index++;
                }
matched_signle_chr_with_star:
                free(snapshot_pattern);
                free(source_str_cpy_header);
            } else {
                char *snapshot_pattern = (char *) malloc(sizeof(char) * 25);
                char *source_str_cpy = (char *)malloc(sizeof(char) * 25);

                memset(snapshot_pattern, 0, 25);
                memset(source_str_cpy, 0, 25);
                strcpy(source_str_cpy, s);
                char *source_str_cpy_header = source_str_cpy;


                for (int m = i + 1; m < patterns_size; m++) {

                    if (patterns[m][0] == '.' && patterns[m][1] == '*') {
                        break;
                    }
                    strcat(snapshot_pattern, patterns[m]);
                    // i = m;
                }




                for (int m = 0; m < match_index; m++) {
                    char temp = *(source_str_cpy)++;
                }
                for (int m = match_index; m < source_str_length; m++) {
                    if (s[m] == '\0') {
                        break;
                    }
                    bool match_result = isMatch_no_display_ver(source_str_cpy, snapshot_pattern);

                    if (match_result == true) {
                        match_index = m;
                        goto matched_all_chr_with_star;
                    }

                    char temp = *(source_str_cpy)++;
                }


                if ((i + 1) < patterns_size) {
                    char barrier_chr_ = '\0';
                    for (int k = i + 1; k < patterns_size; k++) {
                        if (patterns[k][1] == '\0' && patterns[k][0] != '\30') {
                            barrier_chr_ = patterns[k][0];
                            break;
                        }
                    }
                    while(match_index < source_str_length && s[match_index] != barrier_chr_) {
                        match_index++;
                    }
                } else {
                    match_index = source_str_length;
                }

matched_all_chr_with_star:
                free(snapshot_pattern);
                free(source_str_cpy_header);
            }
        } else {
            if (pattern[0] != '.') {
                if (s[match_index] == pattern[0]) {
                    match_index++;
                } else if (s[match_index] != pattern[0]) {
                    goto response_answer;
                }
            } else {
                match_index++;
                if (match_index == source_str_length && i == patterns_size) {
                    result = true;
                    goto response_answer;
                }
            }
        }
    }

    if (match_index == source_str_length) {
        result = true;
    }

response_answer:

    for (int i = 0; i < patterns_size; i++) {
        free(patterns[i]);
    }
    free(patterns);

only_response_result:
    return result;
}

bool isMatch(char *s, char *p) {


    bool result = false;

    const int source_str_length = strlen(s);
    const int pattern_str_length = strlen(p);

    printf("==============================================\n\n");
    printf("  ");
    for (int i = 0; i < source_str_length; i++) {
        printf("%d\t", i);
    }
    printf("\n\n  ");
    for (int i = 0; i < source_str_length; i++) {
        printf("%c\t", s[i]);
    }
    printf("\n\n");
    printf("\t%s\n\n\t%s\n\n", s, p);
    printf("-----------------------\n\n");

    int patterns_size = 0;

    char **patterns = (char **)malloc(sizeof(char *) * 20);
    memset(patterns, 0, 20);



    for (int i = 0; i < pattern_str_length; i++) {
        if (p[i] == '*') {
            goto after_find_pattern_checked;
        }
    }

    if (source_str_length != pattern_str_length) {
        goto only_response_result;
    } else {
        for (int i = 0; i < source_str_length; i++) {
            if (s[i] != p[i] && p[i] != '.') {
                goto only_response_result;
            }
        }
        result = true;
        goto only_response_result;
    }

after_find_pattern_checked:

    if (pattern_str_length == 2 && p[0] == '.' && p[1] == '*') {
        result = true;
        goto only_response_result;
    } else if (pattern_str_length == 2 && p[1] == '*') {
        for (int i = 0; i < source_str_length; i++) {
            if (s[i] != p[0]) {
                goto after_special_case_checked;
            }
        }
        result = true;
        goto only_response_result;
    }



after_special_case_checked:

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
            (patterns[i - 1][0] == patterns[i][0])
        ) {
            printf("\t\t\t\t|-(swap):\t%s\t%s\n", patterns[i - 1], patterns[i]);

            char temp_swap = patterns[i - 1][0];
            patterns[i - 1][0] = patterns[i][0];
            patterns[i - 1][1] = '\0';

            patterns[i][0] = temp_swap;
            patterns[i][1] = '*';
            patterns[i][2] = '\0';

        }
    }

    printf("\n");
    printf("patterns match task:\n");

    int match_index = 0;

    for (int i = 0; i < patterns_size; i++) {
        printf("%d.|\t%s\t(%d)\t|\n", i + 1, patterns[i], match_index);
        if (patterns[i][0] == '\30' || patterns[i][0] == '\0') {
            continue;
        }

        char *pattern = patterns[i];

        if (pattern[1] == '*') {
            if (pattern[0] != '.') {
                printf("\t\t\t|- (task %c*) MatchIndex: %d\n", pattern[0], match_index);
                char *snapshot_pattern = (char *) malloc(sizeof(char) * 25);
                char *source_str_cpy = (char *)malloc(sizeof(char) * 25);

                memset(snapshot_pattern, 0, 25);
                memset(source_str_cpy, 0, 25);
                strcpy(source_str_cpy, s);
                char *source_str_cpy_header = source_str_cpy;


                for (int m = i + 1; m < patterns_size; m++) {

                    if (patterns[m][0] == pattern[0] && patterns[m][1] == '*') {
                        break;
                    }
                    strcat(snapshot_pattern, patterns[m]);
                    // i = m;
                }



                printf("\t\t\t|- (task %c*) snapshot_pattern: %s\n", pattern[0], snapshot_pattern);

                for (int m = 0; m < match_index; m++) {
                    char temp = *(source_str_cpy)++;
                }
                printf("\t\t\t|- (task %c*) source_str_cpy: %s\n", pattern[0], source_str_cpy);
                for (int m = match_index; m < source_str_length; m++) {
                    if (s[m] != pattern[0]) {
                        break;
                    }
                    bool match_result = isMatch_no_display_ver(source_str_cpy, snapshot_pattern);

                    if (match_result == true) {
                        printf("\t\t\t|- (task %c*) Matched MatchIndex %d => %d\n", pattern[0], match_index, m);
                        match_index = m;
                        goto matched_signle_chr_with_star;
                    }

                    char temp = *(source_str_cpy)++;
                }
                while(match_index < source_str_length && pattern[0] == s[match_index]) {
                    match_index++;
                }


matched_signle_chr_with_star:
                printf("\n");
                free(snapshot_pattern);
                free(source_str_cpy_header);
            } else {
                printf("\t\t\t|- (task .*) MatchIndex: %d\n", match_index);
                char *snapshot_pattern = (char *) malloc(sizeof(char) * 25);
                char *source_str_cpy = (char *)malloc(sizeof(char) * 25);

                memset(snapshot_pattern, 0, 25);
                memset(source_str_cpy, 0, 25);
                strcpy(source_str_cpy, s);
                char *source_str_cpy_header = source_str_cpy;


                for (int m = i + 1; m < patterns_size; m++) {

                    if (patterns[m][0] == '.' && patterns[m][1] == '*') {
                        break;
                    }
                    strcat(snapshot_pattern, patterns[m]);
                    // i = m;
                }



                printf("\t\t\t|- (task .*) snapshot_pattern: %s\n", snapshot_pattern);

                for (int m = 0; m < match_index; m++) {
                    char temp = *(source_str_cpy)++;
                }
                printf("\t\t\t|- (task .*) source_str_cpy: %s\n", source_str_cpy);
                for (int m = match_index; m < source_str_length; m++) {
                    if (s[m] == '\0') {
                        break;
                    }
                    bool match_result = isMatch_no_display_ver(source_str_cpy, snapshot_pattern);
                    if (match_result == 0) {
                        printf("\t\t\t\t|- (task .*) match_simulate: [ False ]\t%s\n", source_str_cpy);
                    } else {
                        printf("\t\t\t\t|- (task .*) match_simulate: [ True ]\t%s\n", source_str_cpy);
                    }
                    if (match_result == true) {
                        printf("\t\t\t|- (task %c*) MatchIndex %d => %d\n", pattern[0], match_index, m);
                        match_index = m;
                        goto matched_all_chr_with_star;
                    }

                    char temp = *(source_str_cpy)++;
                }

                printf("\t\t\t| === INFO ===> (task .*) > i:%d, patterns_size:%d, match_index: %d\n\n", i, patterns_size, match_index);
                printf("\t\t\t| === INFO ===> (task .*) > pattern:%s\n\n", pattern);



                if ((i + 1) < patterns_size) {
                    char barrier_chr_ = '\0';
                    for (int k = i + 1; k < patterns_size; k++) {
                        if (patterns[k][1] == '\0' && patterns[k][0] != '\30') {
                            barrier_chr_ = patterns[k][0];
                            break;
                        }
                    }

                    printf("\t\t\t| === INFO ===> (task .*) > next_pattern: %s\tbarrier_chr: %c\n\n", patterns[i + 1], barrier_chr_);
                    while(match_index < source_str_length && s[match_index] != barrier_chr_) {
                        printf("\t\t\t|- (task .*) match_index: [ %d => %d ]\n", match_index, match_index + 1);
                        match_index++;
                    }
                } else {
                    printf("\t\t\t|- (task .*) match_index: [ %d => %d ]\n\n", match_index, source_str_length);
                    match_index = source_str_length;
                }

matched_all_chr_with_star:
                printf("\n");
                free(snapshot_pattern);
                free(source_str_cpy_header);
            }
        } else {
            if (pattern[0] != '.') {
                if (s[match_index] == pattern[0]) {
                    match_index++;
                    printf("\t\t\t|==> (task info)\tMatchIndex:%d\tpattern_char:[%c]\tsource_char:[%c]\tpatternsIndex: %d\tpatterns_size: %d\n", match_index, pattern[0], s[match_index], i, patterns_size);
                } else if (s[match_index] != pattern[0]) {
                    printf("\t\t\t|==> (no match)\tMatchIndex:%d\tpattern_char:[%c]\tsource_char:[%c]\tpatternsIndex: %d\tpatterns_size: %d\n", match_index, pattern[0], s[match_index], i, patterns_size);
                    goto response_answer;
                }
            } else {
                match_index++;
                if (match_index == source_str_length && i == patterns_size) {
                    result = true;
                    goto response_answer;
                }
            }
        }
    }

    if (match_index == source_str_length) {
        result = true;
    }

response_answer:

    for (int i = 0; i < patterns_size; i++) {
        free(patterns[i]);
    }
    free(patterns);

only_response_result:
    return result;
}


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
    assert(isMatch("aab", "c*a*b") == true);
    assert(isMatch("a", "ab*a") == false);
    assert(isMatch("a", "ab*") == true);
    assert(isMatch("aaa", "ab*a*c*a") == true);
    assert(isMatch("aa", "a*") == true);
    assert(isMatch("mississippi", "mis*is*p*.") == false);
    assert(isMatch("mississippi", "mis*is*ip*.") == true);
    assert(isMatch("aba", ".*.*") == true);
    assert(isMatch("aba", "..*") == true);

    bool answer = isMatch("aabcbcbcaccbcaabc", ".*a*aa*.*b*.c*.*a*");
    printf("answer: %d\n", answer);

    // answer = isMatch("a", "ab*a");
    // printf("answer: %d\n", answer);
    return 0;
}
