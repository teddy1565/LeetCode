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
    for (int i = 1; i < str_length; i++) {
        current_chr_code += get_chr_code(s[i]);
    }
    if (current_chr_code != 0) {
        return false;
    }

    int balance_list[str_length];
    int balance_index = 0;
    for (int i = 0; i < str_length; i++) {
        int code = get_chr_code(s[i]);
        if (code > 0) {
            balance_list[balance_index++] = code;
        } else if (code < 0) {
            int index = --balance_index;
            if (index < 0) {
                return false;
            }
            int code_pair = balance_list[index];
            if (code + code_pair != 0) {
                return false;
            }
        }
    }
    
    return true;
}

int main(void) {
    return 0;
}