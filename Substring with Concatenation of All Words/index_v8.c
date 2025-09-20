/**
 * @file index_v8.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"


int compare_eq(const int *s_list, int *d_list, int list_size) {
    int *tmp = (int *) malloc(sizeof(int) * list_size);
    memcpy(tmp, d_list, sizeof(int) * list_size);
    int find = 0;

    for (int i = 0; i < list_size; i++) {
        int task_find = 0;
        for (int j = 0; j < list_size; j++) {
            if (tmp[j] == -1) {
                continue;
            } else if (s_list[i] == tmp[j]) {
                tmp[j] = -1;
                task_find = 1;
                break;
            }
        }
        if (task_find == 0) {
            find = 1;
            break;
        }
    }

    return find;
}

int compare_cb(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    
    if (wordsSize == 0) {
        return NULL;
    }

    (*returnSize) = 0;
    int words_str_size = strlen(words[0]);
    int input_str_size = strlen(s);

    int list_length = input_str_size;
    int total = 0;

    int *answer = (int *) malloc(sizeof(int) * list_length);
    int *word_range_list = (int *) malloc(sizeof(int) * wordsSize);
    int *word_list = (int *) malloc(sizeof(int) * 26);
    int *word_head_list = (int *) malloc(sizeof(int) * 26);

    int *word_range_runtime_list = (int *) malloc(sizeof(int) * wordsSize);
    int *word_runtime_list = (int *) malloc(sizeof(int) * 26);

    memset(answer, 0, sizeof(int) * list_length);

    memset(word_range_list, 0, sizeof(int) * wordsSize);
    memset(word_range_runtime_list, 0, sizeof(int) * wordsSize);

    memset(word_list, 0, sizeof(int) * 26);
    memset(word_head_list, 0, sizeof(int) * 26);
    memset(word_runtime_list, 0, sizeof(int) * 26);

    for (int i = 0; i < wordsSize; i++) {
        word_head_list[(words[i][0] - 97)] = 1;
        for (int j = 0; j < words_str_size; j++) {
            word_list[(words[i][j] - 97)] += (((words[i][j] - 97) + 1) * (j + 1));
            word_range_list[i] += words[i][j];
            total += words[i][j];
        }
    }

    qsort(word_range_list, wordsSize, sizeof(int), &compare_cb);


    for (int i = 0; i <= (input_str_size - (words_str_size * wordsSize)); i ++) {

        while(i <= (input_str_size - (words_str_size * wordsSize)) && word_head_list[s[i] - 97] == 0) i++;

        memset(word_runtime_list, 0, sizeof(int) * 26);
        memset(word_range_runtime_list, 0, sizeof(int) * wordsSize);

        for (int j = 0; j < wordsSize; j++) {
            for (int k = 0; k < words_str_size; k++) {
                int s_index = i + k + (j * words_str_size);
                if (s_index > input_str_size || s[s_index] == '\0') {
                    continue;
                }
                word_runtime_list[(s[s_index] - 97)] += (((s[s_index] - 97) + 1) * (k + 1));
                word_range_runtime_list[j] += s[s_index];
            }
        }

        int check_result = memcmp(word_runtime_list, word_list, sizeof(int) * 26);
        qsort(word_range_runtime_list, wordsSize, sizeof(int), &compare_cb);
        int check_range_result = memcmp(word_range_runtime_list, word_range_list, sizeof(int) * wordsSize);

        if (check_result == 0 && check_range_result == 0) {
            answer[(*returnSize)++] = i;
        }
    }

    free(word_range_list);
    free(word_list);
    free(word_head_list);
    free(word_range_runtime_list);
    free(word_runtime_list);

    return answer;
}

int main(void) {
    char words[2][4] = {
        { 'f', 'o', 'o', '\0' },
        { 'b', 'a', 'r', '\0' }
    };

    int total = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            total += words[i][j];
        }
    }
    printf("%d\n", total);
    return 0;
}