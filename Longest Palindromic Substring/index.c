#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *longestPalindrome(char *s) {
    int leng = strlen(s);
    if (leng == 1) {
        printf("%s\n",s);
    }
    char lut[62];
    int Index = 0;
    typedef struct subString{
        char *str;
        struct subString *prev,*next;
    } subString;
    subString *result = (subString*) malloc(sizeof(subString));
    result->prev = NULL;
    result->next = NULL;
    for (int i=0;i<leng;i++) {
        /*檢查此字元是否被找過了*/
        int flag = 0;
        for (int j=0;j<Index;j++) {
            if (s[i] == lut[j]) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            continue;
        }
        /*由左至右檢查每一個與當前同字元的子字串*/
        for (int j=i+1;j<leng;j++) {
            int child_str_find_flag = 1;
            if (s[j] == s[i]) {
                if (j == i+1) {
                    result->str = (char *) malloc(sizeof(char)*3);
                    strncpy(result->str,&s[i],2);
                    result->str[2] = '\0';
                    result->next = (subString *) malloc(sizeof(subString));
                    result->next->prev = result;
                    result->next->str = NULL;
                    result->next->next = NULL;
                    result = result->next;
                    continue;
                }
                for(int k=i+1,l=j-1;k<j;k++,l--) {
                    if (s[k] != s[l]) {
                        child_str_find_flag = 0;
                        break;
                    }
                }
                if (child_str_find_flag) {
                    /*如果檢查到子字串，先記錄，因為不見得是最長*/
                    result->str = (char *) malloc(sizeof(char)*((j-i)+2));
                    strncpy(result->str,&s[i],j-i+1);
                    result->str[j-i+1] = '\0';
                    result->next = (subString*) malloc(sizeof(subString));
                    result->next->prev = result;
                    result->next->str = NULL;
                    result->next->next = NULL;
                    result = result->next;
                    continue;
                } else {
                    continue;
                }
            } else {
                continue;
            }
        }
    }
    do {
        printf("%s\n",result->str);
    } while(result = result->prev);
    
    return "hello world";
}
int main (void) {
    printf("%s",longestPalindrome("abbbbbbbbbbbba"));
    return 0;
}