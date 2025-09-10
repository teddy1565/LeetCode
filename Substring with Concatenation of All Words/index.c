#include "index.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int words_str_size = strlen(words[0]);
    int input_str_size = strlen(s);
    for (int i = 0; i < input_str_size; i+=words_str_size) {
        printf("\tinput: ");
        for (int l = 0; l < words_str_size; l++) {
            printf("%c", s[i+l]);
        }
        printf("\n");
        for (int j = 0; j < wordsSize; j++) {
            if (s[i] == words[j][0]) {
                for (int k = 0; k < words_str_size; k++) {
                    if (s[i+k] == words[j][k]) {
                        printf("%c ", s[i+k]);
                    }
                }
                printf("\n");
            }
        }
        printf("\n");
    }

    return NULL;
}

int main(void) {
    return 0;
}