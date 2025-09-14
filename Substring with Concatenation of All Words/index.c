#include "index.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    
    int words_str_size = strlen(words[0]);
    int input_str_size = strlen(s);

    int words_answer_index = 0;
    int *words_answer_list = (int *) malloc(sizeof(int) * 5000);
    for (int i = 0; i < 5000; i++) {
        words_answer_list[i] = -1;
    }

    int *words_index_list = (int *) malloc(sizeof(int) * wordsSize);
    int words_index_index = 0;

    for (int i = 0; i < wordsSize; i++) {
        words_index_list[i] = -1;
    }

    for (int i = 0; i < input_str_size; i+=words_str_size) {
        printf("\tinput: ");
        for (int l = 0; l < words_str_size; l++) {
            printf("%c", s[i+l]);
        }
        printf("\n");


        for (int j = 0; j < wordsSize && words_index_index < (wordsSize - 1); j++) {
            if (s[i] == words[j][0]) {
                int find = 1;
                for (int k = 0; k < words_str_size; k++) {
                    if (s[i+k] == words[j][k]) {
                        printf("%c ", s[i+k]);
                    } else {
                        find = 0;
                        break;
                    }
                }
                if (find == 1) {
                    printf("words_index_index: %d, %d\n", words_index_index, j);
                    words_index_list[words_index_index++] = j;
                    break;
                }
                printf("\n");
            }
        }
        printf("\n");

        printf("words_index_index: %d\n", words_index_index);
        if (words_index_index == (wordsSize - 1)) {
            words_answer_list[words_answer_index++] = i;
            
        }

        words_index_index = 0;
        for (int k = 0; k < wordsSize; k++) {
            words_index_list[k] = -1;
        }
    }

    printf("\n\n=================\n\n");


    // for (int i = 0; i < words_index_index; i++) {
    //     printf("%s\n", words[words_index_list[i]]);
    // }

    for (int i = 0; i < words_answer_index; i++) {
        printf("%d\n", words_answer_list[i]);
    }

    return NULL;
}

int main(void) {
    return 0;
}