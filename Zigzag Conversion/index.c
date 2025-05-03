/*
 * @lc app=leetcode id=6 lang=c
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
char* convert(char* s, int numRows) {
    

    if (numRows == 1) {
        return s;
    }

    if (strlen(s) <= numRows) {
        return s;
    }

    const int source_string_length = strlen(s);
    
    if (numRows == 2) {
        char *temp = (char*) malloc(sizeof(char) * (source_string_length + 1));
        int j = 0;
        for (int i=0; i < (source_string_length); i+=2, j++) {
            temp[j] = s[i];
        }
        for (int i=1; i < (source_string_length + 1); i+=2, j++) {
            temp[j] = s[i];
        }
        temp[source_string_length] = '\0';
        for (int i=0; i < (strlen(temp) + 1); i++) {
            s[i] = temp[i];
        }
        free(temp);
        return s;
    }

    const int space_size = numRows - 2;
    char *answer = (char*) malloc(sizeof(char) * (source_string_length + 1));
    const int zig_interval_size = space_size + numRows;
    
    int k = 0;
    for (int i=0; i < numRows; i++) {
        for (int zig_header_index = i; zig_header_index < (source_string_length + 1); zig_header_index += zig_interval_size) {
            int next_zig_top_header_index = (zig_header_index + zig_interval_size) - i;
            int offset = zig_header_index % zig_interval_size;
            if (zig_header_index >= (source_string_length + 1)) {
                break;
            }
            if (i != 0) {
                answer[k] = s[zig_header_index];
                k++;
                
                if (next_zig_top_header_index - offset == zig_header_index) {
                    continue;
                } else if (next_zig_top_header_index > (source_string_length + 1)) {
                    break;
                }
                answer[k] = s[next_zig_top_header_index - offset];
                k++;
            } else {
                answer[k] = s[zig_header_index];
                k++;
            }
        }
    }

    for (int i = 0; i < source_string_length; i++) {
        s[i] = answer[i];
    }

    s[source_string_length] = '\0';

    free(answer);

    return s;
}
// @lc code=end

