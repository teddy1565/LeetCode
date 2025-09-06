#include "index.h"

char * mergeAlternately(char * word1, char * word2) {
    int str1_length = strlen(word1);
    int str2_length = strlen(word2);

    char *s = (char *) malloc(sizeof(char) * (str1_length + str2_length + 1));
    memset(s, 0, sizeof(char) * (str1_length + str2_length + 1));

    for (int i = 0, j = 0, k = 0; i < (str1_length + str2_length); i++) {
        if (i % 2 == 0) {

            if ((j + 1) > str1_length) {
                goto word2_append;
            }

            word1_append:
            s[i] = word1[j++];
        } else {

            if ((k + 1) > str2_length) {
                goto word1_append;
            }

            word2_append:
            s[i] = word2[k++];
        }
    }

    return s;
}

int main(void) {
    return 0;
}