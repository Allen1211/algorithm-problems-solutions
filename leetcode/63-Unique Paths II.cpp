/*
63. 不同路径 II
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

*/

#include <iostream>
#include <vector>
using namespace std;


/*
优化后的动态规划：由于每次状态转移，只依赖于两个值 dp[i][j-1] 和 dp[i-1][j]，
所以只需要用一个一维数组dp[m] dp[m]保存某一行的所有值
每一次迭代相当于从左往右计算一行 dp[j]相当于dp[i-1][j]  dp[j-1] 相当于 dp[i][j-1]
时间复杂度 O(m*n)  空间复杂度 O(m)
*/
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        vector <int> dp(m);
        dp[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                    continue;
                }
                if(j >= 1 && obstacleGrid[i][j-1] == 0){
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp.back();
    }
};

/*
* 动态规划
* 状态转移方程  dp[i][j] = dp[i-1][j] + dp[i][j-1];
* 其中 dp[1][m] = 1 ; dp[n][1] = 1 ; (若只有一行或一列的话，就只有一种走法)
* 时间复杂度 O(m*n)  空间复杂度 O(m*n)
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        // 仅有一行、仅有一列的情况，只有一种走法
        int val = 1;
        for (int i = 0; i < n; i++) {
            if(val == 1 && obstacleGrid[0][i] == 1){
                val = 0;
            }
            dp[0][i] = val;
        }
        val = 1;
        for (int i = 0; i < m; i++){
            if(val == 1 && obstacleGrid[i][0] == 1){
                val = 0;
            }
            dp[i][0] = val;
        }

        // 状态状态转移方程
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[m-1][n-1];
    }
};


