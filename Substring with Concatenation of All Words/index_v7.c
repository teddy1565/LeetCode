/**
 * @file index_v7.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"
#define DEBUG
#define VERBOSE

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

    #ifdef VERBOSE
    printf("word_str_size: %d\n", words_str_size);
    printf("input_str_size: %d\n", input_str_size);
    printf("list_length: %d\n", list_length);
    printf("word_size: %d\n", wordsSize);
    #endif

    int *list = malloc(sizeof(int) * list_length);
    int *word_range_list = malloc(sizeof(int) * wordsSize);
    int *word_list = malloc(sizeof(int) * 26);
    int *word_head_list = malloc(sizeof(int) * 26);

    int *word_range_runtime_list = malloc(sizeof(int) * wordsSize);
    int *word_runtime_list = malloc(sizeof(int) * 26);

    for (int i = 0; i < list_length; i++) {
        list[i] = 0;
    }

    for (int i = 0; i < wordsSize; i++) {
        word_range_list[i] = 0;
        word_range_runtime_list[i] = 0;
    }

    for (int i = 0; i < 26; i++) {
        word_list[i] = 0;
        word_head_list[i] = 0;
        word_runtime_list[i] = 0;
    }

    for (int i = 0; i < wordsSize; i++) {
        word_head_list[(words[i][0] - 97)] = 1;
        for (int j = 0; j < words_str_size; j++) {
            word_list[(words[i][j] - 97)] += (((words[i][j] - 97) + 1) * (j + 1));
            word_range_list[i] += words[i][j];
            total += words[i][j];
        }
    }

    qsort(word_range_list, wordsSize, sizeof(int), &compare_cb);

    #ifdef VERBOSE
    printf("total: %d\n", total);
    printf("static_range_list: ");

    for (int i = 0; i < wordsSize; i++) {
        printf("%d ", word_range_list[i]);
    }
    printf("\n");
    #endif

    for (int i = 0; i <= (input_str_size - (words_str_size * wordsSize)); i ++) {

        while(i <= (input_str_size - (words_str_size * wordsSize)) && word_head_list[s[i] - 97] == 0) i++;

        for (int j = 0; j < 26; j++) {
            word_runtime_list[j] = 0;
        }

        for (int j = 0; j < wordsSize; j++) {
            word_range_runtime_list[j] = 0;
        }


        
        // int temp_total = 0;

        #ifdef DEBUG
        printf("%d | ", i);
        #endif

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

        #ifdef VERBOSE
        if (input_str_size < 500) {
            printf("runtime_range_list: ");
            for (int j = 0; j < wordsSize; j++) {
                printf("%d ", word_range_runtime_list[j]);
            }
            printf("\n");
            printf("check_result: %d, check_range_result: %d\n", check_result, check_range_result);
        }
        #endif
        if (check_result == 0 && check_range_result == 0) {
            list[(*returnSize)++] = i;
        }
    }
    #ifdef VERBOSE
    printf("return_size: %d\n", (*returnSize));
    #endif
    return list;
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