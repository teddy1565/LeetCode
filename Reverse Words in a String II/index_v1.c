#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseWords(char* s, int sSize) {
    int row_n = 1;
    int max_str_length = 0;
    int max_str_counter = 0;
    for (int i = 0; i < sSize; i++) {
        if (s[i] == ' ') {
            row_n++;
            if (max_str_counter > max_str_length) {
                max_str_length = max_str_counter;
            }
            max_str_counter = 0;
            continue;
        }
        max_str_counter++;
    }
    
    if (max_str_counter > max_str_length) {
        max_str_length = max_str_counter;
    }
    char **temp_s = (char **) malloc(sizeof(char *) * row_n);
    for (int i = 0; i < row_n; i++) {
        temp_s[i] = (char *) malloc(sizeof(char) * (max_str_length + 1));
        memset(temp_s[i], 0, sizeof(char) * (max_str_length + 1));
    }

    int row_index = 0;
    int col_index = 0;
    for (int i = 0; i < sSize; i++) {
        if (s[i] == ' ') {
            row_index++;
            col_index = 0;
            continue;
        }
        temp_s[row_index][col_index] = s[i];
        col_index++;
    }
    temp_s[row_index][col_index] = '\0';

    int s_index = 0;

    for (int i = row_index; i >= 0; i--) {
        for (int j = 0; j < max_str_length; j++) {
            if (temp_s[i][j] == '\0') {
                break;
            }
            s[s_index] = temp_s[i][j];
            s_index++;
        }
        if (s_index < sSize) {
            s[s_index] = ' ';
            s_index++;
        }
    }

    for (int i = 0; i < row_n; i++) {
        free(temp_s[i]);
    }
    free(temp_s);

}