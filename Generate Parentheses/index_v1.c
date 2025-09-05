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
    int rows = 2 << (n - 1);
    char **bracket_list = (char **) malloc(sizeof(char *) * rows);

    int brack_len = n * 2;
    for (int i = 0; i < n; i++) {
        bracket_list[i] = (char *) malloc(sizeof(char) * (brack_len + 1));
        memset(bracket_list[i], 0, sizeof(char) * (brack_len + 1));
        int k = n - i;
        for (int j = 0; j < brack_len; j++) {
            int base_g = k % n;
            int base_x = j / k;
            int base_y = j / n;
            int base_z = j % k;

            printf("%d\n", base_x % 2);
            // printf("%d %d %d %d | %d %d %d\n", i, j, k, n, base_x, j % n, (base_x + 1) % 2);
            // printf("%d %d %d | %d %d\n", base_x, base_g, base_y, j, k);
            int index = base_x % 2;
            // printf("%c", bracket_dict[index]);
        }
        printf("\n");
    }
    
    return bracket_list;
}

int main(void) {
    int returnSize = 0;
    generateParenthesis(4, &returnSize);
    return 0;
}