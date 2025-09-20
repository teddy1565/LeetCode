/**
 * @file index_v15.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-20
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
    const int words_str_size = strlen(words[0]);
    const int input_str_size = strlen(s);

    long long int word_total = 0;

    int *answer = (int *) malloc(sizeof(int) * input_str_size);
    int *word_head_list = (int *) malloc(sizeof(int) * 26);
    long long int *tmp_answer = (long long int *) malloc(sizeof(long long int) * (input_str_size + 1));

    memset(answer, 0, sizeof(int) * input_str_size);
    memset(tmp_answer, 0, sizeof(long long int) * (input_str_size + 1));


    memset(word_head_list, 0, sizeof(int) * 26);

    for (int i = 0; i < wordsSize; i++) {
        word_head_list[(words[i][0] - 97)] = 1;
        long long int k_tmp = 0;
        for (int j = 0; j < words_str_size; j++) {
            k_tmp += (words[i][j] * words[i][j] * (j + 1));
        }
        word_total += (k_tmp * k_tmp);
    }

    const int word_str_total_length = words_str_size * wordsSize;
    
    printf("word_total: %lld\n", word_total);
    printf("word_str_total_length: %d\n", word_str_total_length);

    printf("---------------------------------\n\n");

    for (int i = 0; i <= (input_str_size - words_str_size); i++) {

        while(i <= (input_str_size - words_str_size) && word_head_list[s[i] - 97] == 0) i++;

        if ((*returnSize) > 1 && answer[(*returnSize)-1] == (i - 1) && s[i] == s[i - 1] && s[i + (word_str_total_length - 1)] == s[(i - 1)]) {
            answer[(*returnSize)++] = i;
            continue;
        }

        
        
        long long int temp_feature_total = 0;
        for (int k = 0; k < words_str_size; k++) {
            int s_index = i + k;
            if (s_index > input_str_size || s[s_index] == '\0') {
                break;
            }
            temp_feature_total += (s[s_index] * s[s_index] * (k + 1));
        }

        tmp_answer[i] = (temp_feature_total * temp_feature_total);
    }

    for (int i = 0; i < input_str_size; i++) {
        if (tmp_answer[i] == 0) {
            continue;
        }
        long long int tmp_answer_total = 0;
        for (int j = i, k = 0; j < input_str_size && k < wordsSize; j += words_str_size) {
            tmp_answer_total += tmp_answer[j];
            k++;
        }
        if (tmp_answer_total == word_total) {
            answer[(*returnSize)++] = i;
        }
        printf("%d | %lld | %lld\n", i, tmp_answer[i], tmp_answer_total);
    }

    free(word_head_list);
    free(tmp_answer);

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