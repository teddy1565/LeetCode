#include "index.h"


int strStr(char* haystack, char* needle) {

    for (int i = 0; i < strlen(haystack); i++) {
        char *haystack_p = &(haystack[i]);
        char *needle_p = needle;
        
        while(needle_p != '\0' && haystack_p != '\0') {
            char a = *(haystack_p)++;
            char b = *(needle_p)++;
            
            if (a != b && b != '\0') {
                break;
            } else if (a == '\0' && b == '\0') {
                return i;
            } else if (b == '\0') {
                return i;
            }
        }
    }

    return -1;
}

int main(void) {
    return 0;
}