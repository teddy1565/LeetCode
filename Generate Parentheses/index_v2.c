/**
 * @file index_v2.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-04
 * 
 * @copyright Copyright (c) 2025
 * 
 * I try just use char* and calculate how much it should change. but i think not good
 * 
 */
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

    int base_n = pow_int(2, n*2) - pow_int(2, n);

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
        if (i == 0) {
            continue;
        }

        int k = i / n;  // 0 0 0 0 1 1 1 1 2 2 2 2
        int l = i % (n - 1);  // 0 1 2 3 0 1 2 3 0 1 2 3

        for (int j = 0; j < brack_len; j++) {
            // [0][3] <-> [1][0]
            // [0][3] <-> [1][1]
            // [0][3] <-> [1][2]


            // [0][2] <-> [1][0]
            // [0][2] <-> [1][1]
            // [0][2] <-> [1][2]

            // [0][3] <-> [1][0]
            // [0][2] <-> [1][1]

        }



        
        int offset = n - 1;
        int ttttt = ((i / n) * n) + (i % n);
        printf("%d\n", ttttt);
        int ggggg = (n * k) + (l);
        for (int j = 0; j < brack_len; j++) {
            int index = ((j / n)) % 2;  // 0 0 0 0 1 1 1 1
            
            
            int g = j / n;
            int m = j % n;
            // printf("%d %d | %d %d | %d %d | %d\n", i, j, k, l, g, m, ggggg);
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