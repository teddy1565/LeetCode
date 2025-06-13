#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char *s, char *p) {

    bool result = false;

    const int source_str_length = strlen(s);
    const int pattern_str_length = strlen(p);

    int patterns_size = 0;

    char **patterns = (char **)malloc(sizeof(char *) * 20);
    memset(patterns, 0, 20);

    char *retry_other_p = (char *) malloc(sizeof(char) * 25);
    memset(retry_other_p, 0, 25);
    char *retry_other_p_header = retry_other_p;
    strcpy(retry_other_p, p);


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
                goto check_align_char;
            }
        }
        result = true;
        goto only_response_result;
    }

check_align_char:
    if (source_str_length >= pattern_str_length) {
        for (int i = 1; i < pattern_str_length; i++) {
            if (p[i] == '*') {
                break;
            } else if (p[i - 1] != s[i - 1] && p[i - 1] != '.') {
                result = false;
                goto only_response_result;
            }
        }
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

    char *snapshot_pattern = (char *) malloc(sizeof(char) * 25);
    char *source_str_cpy = (char *)malloc(sizeof(char) * 25);
    memset(snapshot_pattern, 0, 25);
    memset(source_str_cpy, 0, 25);
    char *source_str_cpy_header = source_str_cpy;
    for (int i = 0; i < patterns_size; i++) {
        source_str_cpy = source_str_cpy_header;
        memset(snapshot_pattern, 0, 25);
        memset(source_str_cpy, 0, 25);
        if (patterns[i][0] == '\30' || patterns[i][0] == '\0') {
            continue;
        }

        char *pattern = patterns[i];

        if (pattern[1] == '*') {
            if (pattern[0] != '.') {
                strcpy(source_str_cpy, s);
                


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
                    bool match_result = isMatch(source_str_cpy, snapshot_pattern);

                    if (match_result == true) {
                        match_index = m;
                        break;
                    }

                    char temp = *(source_str_cpy)++;
                }
                while(match_index < source_str_length && pattern[0] == s[match_index]) {
                    match_index++;
                }

            } else {
                strcpy(source_str_cpy, s);


                for (int m = i + 1; m < patterns_size; m++) {

                    if (patterns[m][0] == '.' && patterns[m][1] == '*') {
                        strcat(snapshot_pattern, patterns[m]);
                        break;
                    }
                    strcat(snapshot_pattern, patterns[m]);
                    // i = m;
                }

                if (strlen(snapshot_pattern) == 0) {
                    goto after_match_simulator;
                }

match_simulator:
                for (int m = 0; m < match_index; m++) {
                    char temp = *(source_str_cpy)++;
                }
                for (int m = match_index; m < source_str_length; m++) {
                    if (s[m] == '\0') {
                        break;
                    }
                    bool match_result = isMatch(source_str_cpy, snapshot_pattern);

                    if (match_result == true) {
                        match_index = m;
                        break;
                    }

                    char temp = *(source_str_cpy)++;
                }

after_match_simulator:
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
                    while(match_index < source_str_length) {
                        match_index++;
                    }
                }
            }


        } else {
            if (pattern[0] != '.' && match_index < source_str_length) {
                if (s[match_index] == pattern[0]) {
                    match_index++;
                } else if (s[match_index] != pattern[0]) {
                    result = false;
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
matched_chr_with_star:
    

    if (match_index == source_str_length) {
        result = true;
    }

response_answer:



    if (result == true) {
        goto only_response_result;
    }

    goto retry_other_possible;

retry_other_possible:


    if (p[1] == '*' && p[0] != '.') {
        *(retry_other_p)++;
        *(retry_other_p)++;
        result = isMatch(s, retry_other_p);
    }

    retry_other_p = retry_other_p_header;

only_response_result:
    free(snapshot_pattern);
    free(source_str_cpy_header);
    for (int i = 0; i < patterns_size; i++) {
        free(patterns[i]);
    }
    free(patterns);
    free(retry_other_p);
    return result;
}
