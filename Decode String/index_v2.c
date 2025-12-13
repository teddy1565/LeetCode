#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* decodeString(char *s);
char* decode_string_main(char *s) {
    int str_len = strlen(s);
    int check_head_num = s[0] - 48;
    if (check_head_num < 0 || check_head_num > 9) {
        char *ss = (char *) malloc(sizeof(char) * (str_len + 1));
        memset(ss, 0, sizeof(char) * (str_len + 1));
        strcpy(ss, s);
        return ss;
    }
    int n = 0;
    char c;
    while (c = *(s++)) {
        if (c == '[') {
            break;
        }
        n = n * 10 + (c - 48);
    }
    char *sp = (char *) malloc(sizeof(char) * (strlen(s)));
    strncpy(sp, s, sizeof(char) * (strlen(s) - 1));
    sp[strlen(s) - 1] = '\0';

    int find_next = 0;
    for (int i = 0; i < strlen(sp) ; i++) {
        if (sp[i] == '[') {
            find_next = 1;
            break;
        }
    }
    if (find_next == 1) {
        char *m = sp;
        sp = decodeString(m);
        free(m);
    }

    char *res = (char *) malloc(sizeof(char) * (n * strlen(sp) + 1));
    memset(res, 0, sizeof(char) * (n * strlen(sp) + 1));
    for (int i = 0; i < n; i++) {
        strcat(res, sp);
    }
    free(sp);
    
    return res;
}

char* decodeString(char* s) {
    const int str_list_size = 40;
    const int str_list_col_size = 31;

    int str_len = strlen(s);
    char **str_list = (char **) malloc(sizeof(char *) * str_list_size);
    for (int i = 0; i < str_list_size; i++) {
        str_list[i] = (char *) malloc(sizeof(char) * str_list_col_size);
        memset(str_list[i], 0, sizeof(char) * str_list_col_size);
    }

    int str_list_index = 0;
    int str_list_chr_index = 0;
    
    for (int i = 0, split_mode = 0, brack_count = 0; i < str_len; i++) {
        int k = s[i] - 48;
        if (k >= 0 && k < 10 && split_mode != 2) {
            if (split_mode != 1) {
                split_mode = 1;
                str_list[str_list_index][str_list_chr_index++] = '\0';
                str_list_chr_index = 0;
                str_list_index++;
            }
            str_list[str_list_index][str_list_chr_index++] = s[i];
        } else if (s[i] == '[') {
            if (split_mode != 2) {
                split_mode = 2;
            }
            brack_count += 1;
            str_list[str_list_index][str_list_chr_index++] = s[i];
        } else if (s[i] == ']') {
            brack_count -= 1;
            str_list[str_list_index][str_list_chr_index++] = s[i];
            if (brack_count == 0) {
                split_mode = 0;
                str_list[str_list_index][str_list_chr_index++] = '\0';
                str_list_chr_index = 0;
                str_list_index++;
            }
        } else {
            str_list[str_list_index][str_list_chr_index++] = s[i];
        }
    }

    str_list[str_list_index][str_list_chr_index++] = '\0';
    str_list_index++;

    int answer_length = 0;
    for (int i = 0; i < str_list_index; i++) {
        char *sn = decode_string_main(str_list[i]);
        answer_length += strlen(sn);
        free(sn);
    }

    char *answer = (char *) malloc(sizeof(char) * (answer_length + 10));
    memset(answer, 0, sizeof(char) * (answer_length + 10));
    
    for (int i = 0; i < str_list_index; i++) {
        char *sn = decode_string_main(str_list[i]);
        strcat(answer, sn);
        free(sn);
    }

    for (int i = 0; i < str_list_size; i++) {
        free(str_list[i]);
    }
    free(str_list);

    return answer;
}