#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <array>

//[
//["X","O","X"]
//["O","X","O"]
//["X","O","X"]
//]
//
class Solution {
    public:
        void solve(std::vector<std::vector<char>>& board) {
            int dx[4] = { 1, -1, 0, 0 };
            int dy[4] = { 0, 0, 1, -1 };

            std::vector<std::array<int, 2>> coordinate;
            int row_size = board.size();
            int col_size = board[0].size();
            for (int i = 0; i < col_size; i++) {
                if (board[0][i] == 'O' ) {
                    coordinate.push_back({0, i});
                }
                if (board[row_size - 1][i] == 'O') {
                    coordinate.push_back({row_size - 1, i});
                }
            }

            for (int i = 0; i < row_size; i++) {
                if (board[i][0] == 'O') {
                    coordinate.push_back({i, 0});
                }
                if (board[i][col_size - 1] == 'O') {
                    coordinate.push_back({i, col_size - 1});
                }
            }

            while (coordinate.size() > 0) {
                std::array<int, 2> code = coordinate.back();
                coordinate.pop_back();
                int x = code[0];
                int y = code[1];
                if (board[x][y] == 'A') {
                    continue;
                }
                board[x][y] = 'A';
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= row_size || nx < 0 || ny >= col_size || ny < 0 || board[nx][ny] != 'O') {
                        continue;
                    }

                    coordinate.push_back({ nx, ny });
                }
            }

            for (int i = 0; i < row_size; i++) {
                for (int j = 0; j < col_size; j++) {
                    if (board[i][j] == 'O') {
                        board[i][j] = 'X';
                    } else if (board[i][j] == 'A') {
                        board[i][j] = 'O';
                    }
                }
            }
        }
};