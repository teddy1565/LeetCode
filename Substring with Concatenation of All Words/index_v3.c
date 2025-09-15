/**
 * @file index_v3.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    
    if (wordsSize == 0) {
        return NULL;
    }

    int words_str_size = strlen(words[0]);
    int input_str_size = strlen(s);

    int list_length = (input_str_size / words_str_size);
    int total = 0;
    printf("word_str_size: %d\n", words_str_size);
    printf("input_str_size: %d\n", input_str_size);
    printf("list_length: %d\n", list_length);

    int *list = malloc(sizeof(int) * list_length);

    int *answer = malloc(sizeof(int) * list_length);
    int answer_index = 0;
    (*returnSize) = 0;

    for (int i = 0; i < list_length; i++) {
        list[i] = 0;
        answer[i] = 0;
    }

    for (int i = 0; i < wordsSize; i++) {
        total += (i + 1);
    }

    printf("total: %d\n", total);

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < input_str_size; j += words_str_size) {
            for (int k = 0; k < words_str_size; k++) {
                if (s[j + k] == words[i][k]) {
                    list[j / words_str_size] = i + 1;
                }
            }
        }
    }

    for (int i = 0; i < (list_length - (wordsSize - 1)); i++) {
        int sum = 0;
        for (int j = 0; j < wordsSize; j++) {
            sum += list[i + j];
        }
        if (sum == total) {
            answer[(*returnSize)++] = i * words_str_size;
        }
        printf("%d: %d\n", i * words_str_size, sum);
    }

    for (int i = 0; i < list_length; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return answer;
}

int main(void) {
    return 0;
}