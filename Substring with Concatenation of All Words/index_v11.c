/**
 * @file index_v11.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-16
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

    (*returnSize) = 0;
    int words_str_size = strlen(words[0]);
    int input_str_size = strlen(s);

    int list_length = input_str_size;
    long long int word_total = 0;

    int *answer = (int *) malloc(sizeof(int) * list_length);
    int *word_head_list = (int *) malloc(sizeof(int) * 26);

    memset(answer, 0, sizeof(int) * list_length);


    memset(word_head_list, 0, sizeof(int) * 26);

    for (int i = 0; i < wordsSize; i++) {
        word_head_list[(words[i][0] - 97)] = 1;
        long long int k_tmp = 0;
        for (int j = 0; j < words_str_size; j++) {
            k_tmp += (words[i][j] * words[i][j] * (j + 1));
        }
        word_total += (k_tmp * k_tmp);
    }

    
    printf("word_total: %d\n", word_total);

    for (int i = 0; i <= (input_str_size - (words_str_size * wordsSize)); i ++) {

        while(i <= (input_str_size - (words_str_size * wordsSize)) && word_head_list[s[i] - 97] == 0) {
            i++;
        }

        
        long long int feature_total = 0;
        for (int j = 0; j < wordsSize; j++) {
            long long int temp_feature_total = 0;
            for (int k = 0; k < words_str_size; k++) {
                int s_index = i + k + (j * words_str_size);
                if (s_index > input_str_size || s[s_index] == '\0') {
                    break;
                }
                temp_feature_total += (s[s_index] * s[s_index] * (k + 1));
            }
            feature_total += (temp_feature_total * temp_feature_total);

        }
        if (feature_total == word_total) {
            answer[(*returnSize)++] = i;
        }
    }

    free(word_head_list);

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