#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {

        // Skip non-alphanumeric from left
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // Skip non-alphanumeric from right
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Compare characters (case-insensitive)
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
    
}