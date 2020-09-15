/*
37. 解数独
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。

https://leetcode-cn.com/problems/sudoku-solver/

Note:

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。
*/

#include <cctype>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
   public:
    bool rowMap[9][10];
    bool colMap[9][10];
    bool patchMap[9][10];

    int getPatchNum(int i, int j) { return (i / 3) + (j / 3) * 3; }

    void next(vector<vector<char>>& board, int& i, int& j) {
        do {
            if (j == 8) {
                i += 1;
                j = 0;
            } else {
                j += 1;
            }
        }while(i < 9 && j < 9 && board[i][j] != '.');
    }

    bool doSolveSudoku(vector<vector<char>>& board, int i, int j) {
        if (i == 9) {
            return true;
        }
        int row = i, col = j, patch = getPatchNum(i, j);
        next(board, i, j);
        for (int n = 1; n <= 9; n++) {
            if (!rowMap[row][n] && !colMap[col][n] && !patchMap[patch][n]) {
                rowMap[row][n] = true;
                colMap[col][n] = true;
                patchMap[patch][n] = true;
                if (doSolveSudoku(board, i, j)) {
                    board[row][col] = '0' + n;
                    return true;
                }
                rowMap[row][n] = false;
                colMap[col][n] = false;
                patchMap[patch][n] = false;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        memset(rowMap, false, sizeof(rowMap));
        memset(colMap, false, sizeof(colMap));
        memset(patchMap, false, sizeof(rowMap));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (isdigit(board[i][j])) {
                    int digit = board[i][j] - '0';
                    rowMap[i][digit] = true;
                    colMap[j][digit] = true;
                    patchMap[getPatchNum(i, j)][digit] = true;
                }
            }
        }

        int x = 0, y = 0;
        if(board[0][0] != '.'){
            next(board, x, y);
        }
        doSolveSudoku(board, x, y);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;

    s.solveSudoku(board);
}
