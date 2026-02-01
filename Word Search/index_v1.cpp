#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>

class Solution {
    private:
        static void back_track(bool & answer, std::vector<std::vector<char>> & board, const int m, const int n, int x, int y, std::string & word, int word_size, int word_index) {
            if (answer == true) {
                return;
            }
            
            if (word_index == word_size) {
                answer = true;
                return;
            }
            
            if (x < 0 || x >= m || y < 0 || y >= n) {
                return;
            }

            if (board[x][y] == word[word_index]) {
                char c = board[x][y];
                board[x][y] = ' ';
                back_track(answer, board, m, n, x + 1, y, word, word_size, word_index + 1);
                back_track(answer, board, m, n, x - 1, y, word, word_size, word_index + 1);
                back_track(answer, board, m, n, x, y + 1, word, word_size, word_index + 1);
                back_track(answer, board, m, n, x, y - 1, word, word_size, word_index + 1);
                board[x][y] = c;
            }
        }
    public:
        bool exist(std::vector<std::vector<char>>& board, std::string word) {
            bool answer = false;
            int m = board.size();
            int n = board[0].size();
            int word_size = word.size();
            for (int i = 0; i < m && answer == false; i++) {
                for (int j = 0; j < n && answer == false; j++) {
                    if (board[i][j] == word[0]) {
                        back_track(answer, board, m, n, i, j, word, word_size, 0);
                    }
                }
            }

            return answer;
        }
};