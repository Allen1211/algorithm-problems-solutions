/*
59. 螺旋矩阵 II
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

#include <vector>

using namespace std;

class Solution {
   public:
    int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n);
        if(n == 1){
            matrix[0].resize(1);
            matrix[0][0] = 1;
            return matrix;
        }else{
            for(int i=0;i < n; i++){
                matrix[i].resize(n);
            }
        }
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int di = 0, x = 0, y = 0;
        for (int i = 0; i < n * n; i++) {
            matrix[x][y] = i + 1;
            x += direction[di][0];
            y += direction[di][1];
            if ((di == 0 && y == right) || 
                (di == 1 && x == down) || 
                (di == 2 && y == left) || 
                (di == 3 && x == up)) {
                switch (di) {
                    case 0: up++; break;
                    case 1: right--; break;
                    case 2: down--; break;
                    case 3: left++; break;
                }
                di = (di + 1) % 4;
            }
        }
        return matrix;
    }
};


int main(){
    Solution solution;
    solution.generateMatrix(3);
}