#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
    private:

        void show(std::vector<std::string>& board) {
            for (int i = 0; i < board.size(); i++) {
                std::cout << board[i] << std::endl;
            }
            std::cout << "-------------" << std::endl;
        }

        void NQueens(std::vector<std::vector<std::string>>& result, std::vector<std::string>& board, int max_queen_size, int queen_size) {
            // queen_size == max_queue_size, that means the board can have
            
            if (queen_size == max_queen_size) {
                result.push_back(board);
                return;
            }
            

            const int dx[4] = { 1, -1, 1, -1 };
            const int dy[4] = { 1, -1, -1, 1 };

            int n = max_queen_size;

            for (int i = 0; i < n; i++) {
                bool can_place_chess = true;
                // std::cout << "target: " << i << ", " << queen_size << std::endl;
                for (int j = 0; j < n; j++) {
                    // std::cout << j << ", " << queen_size << std::endl;
                    if (board[j][queen_size] == 'Q') {
                        can_place_chess = false;
                        break;
                    }
                }

                if (can_place_chess == false) {
                    continue;
                }

                for (int j = 0; j < n; j++) {
                    // std::cout << queen_size << ", " << j << std::endl;
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
                        // std::cout << current_x << ", " << current_y << std::endl;
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

                // this->show(board);

                board[i][queen_size] = 'Q';
                this->NQueens(result, board, max_queen_size, queen_size + 1);
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