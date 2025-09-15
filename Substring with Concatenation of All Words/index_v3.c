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
    printf("word_str_size: %d\n", words_str_size);
    printf("input_str_size: %d\n", input_str_size);
    printf("list_length: %d\n", list_length);

    int *list = malloc(sizeof(int) * list_length);

    for (int i = 0; i < list_length; i++) {
        list[i] = -1;
    }

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < input_str_size; j += words_str_size) {
            for (int k = 0; k < words_str_size; k++) {
                if (s[j + k] == words[i][k]) {
                    list[j / words_str_size] = i;
                }
            }
        }
    }

    for (int i = 0; i < list_length; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return NULL;
}

int main(void) {
    return 0;
}