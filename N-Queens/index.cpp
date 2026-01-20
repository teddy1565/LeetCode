#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
    private:

        static void NQueens(std::vector<std::vector<std::string>>& result, std::vector<std::string>& board, int max_queen_size, int queen_size) {
            // queen_size == max_queue_size, that means the board can have

            const int dx[4] = { 1, -1, 1, -1 };
            const int dy[4] = { 1, -1, -1, 1 };
            
            if (queen_size == max_queen_size) {
                result.push_back(board);
                return;
            }

            int n = max_queen_size;

            for (int i = 0; i < n; i++) {
                bool can_place_chess = true;
                for (int j = 0; j < n; j++) {
                    if (board[j][queen_size] == 'Q') {
                        can_place_chess = false;
                        break;
                    }
                }

                if (can_place_chess == false) {
                    continue;
                }

                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 'Q') {
                        can_place_chess = false;
                        break;
                    }
                }

                if (can_place_chess == false) {
                    continue;
                }

                
                
                for (int j = 0; j < 4; j++) {
                    int x = dx[j];
                    int y = dy[j];
                    int current_x = i;
                    int current_y = queen_size;

                    while ((current_x + x) >= 0 && (current_x + x) < n && (current_y + y) >= 0 && (current_y + y) < n) {
                        current_x = current_x + x;
                        current_y = current_y + y;
                        if (board[current_x][current_y] == 'Q') {
                            can_place_chess = false;
                            break;
                        }
                    }

                    if (can_place_chess == false) {
                        break;
                    }
                }

                if (can_place_chess == false) {
                    continue;
                }
                

                board[i][queen_size] = 'Q';
                NQueens(result, board, max_queen_size, queen_size + 1);
                board[i][queen_size] = '.';

            }
        }
    public:
        std::vector<std::vector<std::string>> solveNQueens(int n) {
            std::vector<std::vector<std::string>> answer;

            std::vector<std::string> board;
            for (int i = 0; i < n; i++) {
                std::string board_ln(n, '.');
                board.push_back(board_ln);
            }

            NQueens(answer, board, n, 0);
            
            return answer;
        }
};