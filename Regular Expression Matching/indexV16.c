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
            if (p[i] == s[j] || p[i] == '.') {
                v[i + 1][j + 1] = v[i][j];
            } else if (p[i] == '*' && i > 0) {


                if (p[i - 1] == s[j] || p[i - 1] == '.') {
                    v[i + 1][j + 1] = v[i][j + 1] || v[i + 1][j] || v[i - 1][j + 1];
                } else {
                    v[i + 1][j + 1] = v[i - 1][j + 1];
                }
            }
        }
    }

    answer = v[pattern_str_length][source_str_length];

    for (int i = 0; i < pattern_str_length + 1; i++) {
        free(v[i]);
    }
    free(v);

    return answer;
}