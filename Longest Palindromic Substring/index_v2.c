#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct charTable {
    char c;
    char **str_array;
} charTable;
int findCharTable(char *table,int index,char c) {
    for (int i=0;i<index;i++) {
        if (table[i] == c) {
            return 1;
        }
    }
    return 0;
}
char *longestPalindrome(char *s) {
    int length = strlen(s);
    char table[62];
    charTable chars[62];
    
    int tableIndex = 0;
    for (int i=0;i<length;i++) {
        if (findCharTable(table,tableIndex,s[i])) {
            continue;
        } else {
            table[tableIndex] = s[i];
            chars[tableIndex].c = s[i];
            int counter = 0;
            /*
                先遍歷過字串，找到當前指定字元所包含的子字串，並計算數量，動態宣告str_array
            */
            for (int j=0;j<length;j++) {
                if (s[i] == s[j]) {
                    counter++;
                }
            }
            chars[tableIndex].str_array = (char **) malloc(sizeof(char *)*counter);
            /*
                開始找當前指定字元所包含的子字串
            */
            
            /*
                結束第一次找到這個字元時進行的流程
            */
            tableIndex++;
        }
    }
    return s;
}

int main(void) {
    longestPalindrome("hello world");
    return 0;
}