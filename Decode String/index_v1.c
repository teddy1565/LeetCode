#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *decode_string_main(char *s) {
    int str_len = strlen(s);
    int prefix_len = 0;
    int n = 0;
    int start_index = 0;
    int stop_index = 0;
    for (int i = 0, split_mode = 0, brack_count = 0; i < str_len; i++) {
        int k = s[i] - 48;
        if (k >= 0 && k < 10 && split_mode != 2) {
            split_mode = 1;
            n = n * 10 + k;
        } else if (s[i] == '[') {
            if (brack_count == 0) {
                start_index = i;
            }
            split_mode = 2;
            brack_count += 1;
            continue;
        } else if (s[i] == ']') {
            brack_count -= 1;
            if (brack_count == 0) {
                split_mode = 0;
                stop_index = i;
                break;
            }
        } else if (split_mode == 0) {
            prefix_len += 1;
        }
    }
    char *prefix = (char *) malloc(sizeof(char) * prefix_len);
    strncpy(prefix, s, sizeof(char) * prefix_len);
}

char* decodeString(char* s) {
    int str_len = strlen(s);
    char **str_list = (char **) malloc(sizeof(char *) * 40);
    for (int i = 0; i < 40; i++) {
        str_list[i] = (char *) malloc(sizeof(char) * 31);
        memset(str_list[i], 0, sizeof(char) * 31);
    }

    int str_list_index = 0;
    int str_list_chr_index = 0;
    int n = 0;
    
    for (int i = 0, split_mode = 0, brack_count = 0; i < str_len; i++) {
        int k = s[i] - 48;
        if (k >= 0 && k < 10 && split_mode != 2) {
            split_mode = 1;
            n = n * 10 + k;
        } else if (s[i] == '[') {
            split_mode = 2;
            brack_count += 1;
        } else if (s[i] == ']') {
            brack_count -= 1;
            if (brack_count == 0) {
                split_mode = 0;
            }
            continue;
        } else if (split_mode == 0) {
            str_list[str_list_index][str_list_chr_index] = s[i];
        }
    }

    for (int i = 0; i < 40; i++) {
        free(str_list[i]);
    }
    free(str_list);

    return NULL;
}