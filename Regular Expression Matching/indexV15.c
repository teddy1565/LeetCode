#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isMatch(char *s, char *p) {
    const int source_str_length = strlen(s);
    const int pattern_str_length = strlen(p);
    bool answer = false;

    int **v = (int **) malloc(sizeof(int *) * (pattern_str_length + 1));

    for (int i = 0; i <= pattern_str_length; i++) {
        v[i] = (int *) malloc(sizeof(int) * (source_str_length + 1));
        memset(v[i], 0, sizeof(int) * (source_str_length + 1));
    }

    v[0][0] = 1;

    for (int i = 1; i < pattern_str_length; i++) {
        if (p[i] == '*' && v[i-1][0] == 1) {     // 抓可能開頭沒有match到的情況，這段是在處理 pattern 能匹配空字串
            v[i+1][0] = 1;
        }
    }

    for (int i = 0; i < pattern_str_length; i++) {
        for (int j = 0; j < source_str_length; j++) {
            if (p[i] == s[j] || p[i] == '.') {  // 如果匹配成功，則狀態往下轉移
                v[i + 1][j + 1] = v[i][j];
            } else if (p[i] == '*' && i > 0) {  // 如果匹配到'*' 而且i > 0

                /**
                 * 舉個例子，當i為1時，p[i] = '*', p[i - 1] = 'a', v[i + 1] 則為 v[2][j]行
                 *  0       1       2       3       4       5       6       7       8       9       10      11
                    a       a       b       b       a       b       b       b       b       b       d
                    ------------------------------------------------------------------------------------------------
                    1       0       0       0       0       0       0       0       0       0       0       0        | a    0
                    0      [1]      0       0       0       0       0       0       0       0       0       0        | *    1
                  > 1       1       1       0       0       0       0       0       0       0       0       0        | b    2
                    0       0       0       1       0       0       0       0       0       0       0       0        | *    3
                    1       1       1       1       1       0       0       0       0       0       0       0        | a    4
                    0       1       1       0       0       1       0       0       0       0       0       0        |      5
                 */



                if (p[i - 1] == s[j] || p[i - 1] == '.') {  // 檢查前一個字元，與當前比對的原始字串的字元有沒有匹配

                     /**
                      * 當 p[i-1] 和 s[j] 匹配時，p[i-1]* 有兩種選擇：
                      * 
                      * 1. 匹配 0 次：  
                      * 跟下面else的(B) 區塊一樣，忽略 p[i-1]*。  
                      * 結果取決於 p[0...i-2] 是否匹配 s[0...j]。  
                      * 對應到 DP 表是 v[i-1][j+1]。
                      * 
                      * 2. 匹配 1 次或更多次：  
                      * p[i-1]* 至少要匹配一次 s[j]。  
                      * 如果它匹配了 s[j]，我們就需要看 p[0...i] (整個 ...p[i-1]* pattern) 能否匹配 s 的前一個子字串 s[0...j-1]。  
                      * 對應到 DP 表是 v[i+1][j]。
                      * 
                      * - v[i - 1][j + 1]: 這就是上面說的「匹配 0 次」的情況。(正確)
                      * - v[i + 1][j]: 這就是上面說的「匹配 1 次或更多次」的情況。(正確)
                      * - v[i][j + 1]: 這一項代表 p[0...i-1] (也就是 pattern 到 * 之前) 是否能匹配 s[0...j]。
                      * 在標準的 DP 解法中，這一項通常是不需要的。
                      * 前兩項已經完整地覆蓋了所有可能性。
                      * 不過，將它 || (OR) 進來，雖然多餘，但並不會導致錯誤的結果。
                      */
                    v[i + 1][j + 1] = v[i][j + 1] || v[i + 1][j] || v[i - 1][j + 1];
                } else {    // 如果都不匹配的話，
                    /**
                     * 將匹配字元時的結果複製到當前狀態
                     * 
                     * 這是為了要處理中間只有一個不同字元的狀況，但通常情況下就算沒有匹配到
                     * 
                     * 不存在只有一個不同字元的狀況，也可以直接複製未匹配狀態
                     */

                    /**
                     * '*' 代表它前面的字元 p[i-1] 可以出現 0 次或多次。
                     * 
                     * 既然 p[i-1] 跟當前的 s[j] 不匹配，那麼 p[i-1]* 唯一的可能性就是匹配 0 次 (相當於 p[i-1]* 這兩個字元直接被忽略)。
                     * 
                     * 因此，p[0...i] 能否匹配 s[0...j]，就完全取決於 p[0...i-2] (跳過 p[i-1]*) 能否匹配 s[0...j]。  
                     * 這對應到 DP 表中就是 v[i-1][j+1]
                     * 
                     */
                    v[i + 1][j + 1] = v[i - 1][j + 1];
                }
            }
        }
    }

    answer = v[pattern_str_length][source_str_length];

show_v:
    for (int i = 0; i < source_str_length + 1; i++) {
        printf("%d\t", i);
    }
    printf("\n");
    for (int i = 0; i < source_str_length + 1; i++) {
        printf("%c\t", s[i]);
    }
    printf("\n");
    for (int i = 0; i < source_str_length + 1; i++) {
        printf("--------");
    }
    printf("\n");
    for (int i = 0; i < pattern_str_length + 1; i++) {
        for (int j = 0; j < source_str_length + 1; j++) {
            printf("%d\t", v[i][j]);
        }
        printf(" | %c\t%d \n", p[i], i);
    }
    printf("\n");

release_resource:
    for (int i = 0; i < pattern_str_length + 1; i++) {
        free(v[i]);
    }
    free(v);

    printf("answer: %d\n", answer);
    return answer;
}

int main(void) {
    isMatch("aabbabbbbbd", "a*b*a"); // false
    // isMatch("bbcbbcbcbbcaabcacb", "a*.*ac*a*a*.a..*.*"); // false
    // isMatch("asdvcavsdrfte", ".");
    return 0;
}