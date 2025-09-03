#include "index.h"

const char bracket_dict[2] = { '(', ' ' };

// n = 4
// ((((
// ((( (
// (((  (
// (((   (

// (( ((
// (( ( (
// (( (  (

// ((  ((
// ((  ( (

// ( (((

// ( (( (
// ( ((  (

// ( ( ((

// ( ( ( (

int pow_int(int x, int y) {
    if (x == 0) {
        return 0;
    } else if (y == 0) {
        return 1;
    }

    int k = 1;
    for (int i = 0; i < y; i++) {
        k = k * x;
    }

    return k;

}

char** generateParenthesis(int n, int* returnSize) {
    int max_rows = 2 << n;
    int brack_len = n * 2;

    char *bracket_source = (char *) malloc(sizeof(char) * (brack_len+1));
    memset(bracket_source, 0, sizeof(char) * (brack_len + 1));
    for (int i = 0; i < brack_len; i++) {
        if (i >= (brack_len/2)) {
            bracket_source[i] = ')';
        } else {
            bracket_source[i] = '(';
        }
    }

    char **bracket_list = (char **) malloc(sizeof(char *) * max_rows);

    for (int i = 0; i < max_rows; i++) {
        bracket_list[i] = (char *) malloc(sizeof(char) * (brack_len + 1));
        memset(bracket_list[i], 0, sizeof(char) * (brack_len + 1));
        memcpy(bracket_list[i], bracket_source, sizeof(char) * brack_len);
        int k = i / n;  // 0 0 0 0 1
        int l = i % n;  // 0 1 2 3 0
        int offset = n - 1;
        for (int j = 0; j < brack_len; j++) {
            int index = ((j / n)) % 2;  // 0 0 0 0 1 1 1 1
            int g = j / n;
            int m = j % n;
            printf("%d %d | %d %d | %d %d\n", i, j, k, l, g, m);
            // printf("%c", bracket_dict[index]);
        }
        printf("\n");
    }

    // printf("%s\n", bracket_source);
    
    return bracket_list;
}

int main(void) {
    int returnSize = 0;
    generateParenthesis(4, &returnSize);
    return 0;
}