#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *s, int start_index, int end_index) {
    int str_length = end_index - start_index;
    int mid = start_index + (str_length / 2);
    for (int i = start_index, j = end_index - 1; i < (mid + (str_length & 1)) && j >= mid; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void reverseWords(char* s, int sSize) {

    reverse(s, 0, sSize);

    int k = 0;
    int end_index = 0;
    for (; end_index < sSize; end_index++) {
        if (s[end_index] == ' ') {
            reverse(s, k, end_index);
            k = end_index + 1;
        }
    }
    reverse(s, k, sSize);
}