#include "index.h"


int get_chr_code(char c) {
    if (c == '(') {
        return 1;
    } else if (c == '[') {
        return 2;
    } else if (c == '{') {
        return 3;
    } else if (c == ')') {
        return -1;
    } else if (c == ']') {
        return -2;
    } else if (c == '}') {
        return -3;
    }

    return 0;
}

bool isValid(char* s) {
    int str_length = strlen(s);

    int current_chr_code = get_chr_code(s[0]);
    int align_code = get_chr_code(s[0]);

    for (int i = 1; i < str_length; i++) {
        current_chr_code += get_chr_code(s[i]);

    }

    if (current_chr_code == 0) {
        return true;
    }
    
    return false;
}

int main(void) {
    return 0;
}