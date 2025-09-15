/**
 * @file index_v2.c
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
        list[i] = 0;
    }

    // for (int i = 0; i < words_str_size; i++) {
    //     for (int j = 0; j < input_str_size; j += words_str_size) {
    //         for (int k = 0; k < wordsSize; k++) {
    //             int s_index = j + i + (k * words_str_size);
    //             if (s_index >= input_str_size) {
    //                 continue;
    //             }

    //             if (s[i + j + (k * words_str_size)] == words[k][i]) {
    //                 list[j / words_str_size] += 1;
    //             }
    //         }
    //     }
    // }

    for (int i = 0; i < input_str_size; i += words_str_size) {
        for (int j = 0; j < words_str_size; j++) {
            for (int k = 0; k < wordsSize; k++) {
                int s_index = i + j + (k * words_str_size);
                printf("%d %d %d | ", i, j, (k * words_str_size));
                if (s_index >= input_str_size) {
                    printf("\n");
                    continue;
                }
                printf("%d %d %d %d | %c %c\n", i, j, k, words_str_size, s[s_index], words[k][j]);
                for (int u = 0; u < wordsSize; u++) {
                    if (s[i + j + (k * words_str_size)] == words[u][j]) {
                        list[i / words_str_size] += 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < list_length; i++) {
        printf("%d ", list[i]);
    }

    return NULL;
}

int main(void) {
    return 0;
}