/*
79. 单词搜索
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。



示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false


提示：

board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

#include <string>
#include <vector>

using namespace std;


class Solution {
   public:
    int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool search(vector<vector<char>>& board, string& word, int c, int i, int j,
                int row, int col, bool** marked) {
        marked[i][j] = true;
        if (c >= word.size()) {
            return true;
        }
        int x, y;
        for (int d = 0; d < 4; d++) {
            x = i + direction[d][0];
            y = j + direction[d][1];
            if (x < 0 || x >= row || y < 0 || y >= col) {
                continue;
            }
            if (!marked[x][y] && board[x][y] == word[c]) {
                bool found = search(board, word, c + 1, x, y, row, col, marked);
                marked[x][y] = false;
                if (found) {
                    return true;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        bool *marked[row];
        for (int i = 0; i < row; i++) {
            marked[i] = new bool[col];
            for (int j = 0; j < col; j++) {
                marked[i][j] = false;
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    if (search(board, word, 1, i, j, row, col,
                               marked)) {
                        return true;
                    }else {
                        marked[i][j] = false;
                    }
                }
            }
        }
        return false;
    }
};