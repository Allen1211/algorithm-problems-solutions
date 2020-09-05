/*
54. 螺旋矩阵
给定一个包含 m x n 个元素的矩阵（m 行, n
列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

#include <vector>

using namespace std;

class Solution {
   public:
    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool shouldTurn(int di, int x, int y, int up, int down, int left ,int right){
        return (di == 0 && y == right) || 
                (di == 1 && x == down) || 
                (di == 2 && y == left) || 
                (di == 3 && x == up);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        if(rows == 0) return result;
        int cols = matrix[0].size();
        if(cols == 1){
            for(vector<int> v : matrix){
                result.push_back(v[0]);
            }
            return result;
        }

        int up = 0, down = rows - 1, left = 0, right = cols - 1;
        int di = 0, x = 0, y = 0;
        bool init = true;
        for (int i = 0; i < rows * cols; i++) {
            result.push_back(matrix[x][y]);
            x += direction[di][0];
            y += direction[di][1];
            if (shouldTurn(di, x, y, up, down, left, right)) {
                switch (di) {
                    case 0: up++; break;
                    case 1: right--; break;
                    case 2: down--; break;
                    case 3: left++; break;
                }
                di = (di + 1) % 4;
            }
        }
        return result;
    }
};


