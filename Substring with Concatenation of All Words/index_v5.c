/**
 * @file index_v5.c
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
    printf("word_str_size: %d\n", words_str_size);
    printf("input_str_size: %d\n", input_str_size);
    printf("list_length: %d\n", list_length);

    int *list = malloc(sizeof(int) * list_length);
    int *word_list = malloc(sizeof(int) * 26);
    int *word_head_list = malloc(sizeof(int) * 26);

    for (int i = 0; i < list_length; i++) {
        list[i] = 0;
        
    }

    for (int i = 0; i < 26; i++) {
        word_list[i] = 0;
        word_head_list[i] = 0;
    }

    for (int i = 0; i < wordsSize; i++) {
        word_head_list[(words[i][0] - 97)] = 1;
        for (int j = 0; j < words_str_size; j++) {
            word_list[(words[i][j] - 97)] = 1;
            total += words[i][j];
        }
    }

    printf("total: %d\n", total);

    for (int i = 0; i <= (input_str_size - (words_str_size * wordsSize)); i ++) {

        while(word_head_list[s[i] - 97] == 0) i++;


        
        int temp_total = 0;

        #ifdef DEBUG
        printf("%d | ", i);
        #endif

        for (int j = 0; j < (wordsSize * words_str_size); j++) {

            #ifdef DEBUG
            printf("%d ", j);
            #endif

            temp_total += s[i + j];
        }

        #ifdef DEBUG
        printf("\n");
        printf("inline: %d\n", temp_total);
        #endif

        if (total == temp_total) {
            list[(*returnSize)++] = i;
        }
    }
    printf("return_size: %d\n", (*returnSize));
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