/*
62. 不同路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

例如，上图是一个7 x 3 的网格。有多少可能的路径？

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 2:

输入: m = 7, n = 3
输出: 28

提示：

1 <= m, n <= 100
题目数据保证答案小于等于 2 * 10 ^ 9

https://leetcode-cn.com/problems/unique-paths/
*/

#include <iostream>

using namespace std;


/*
优化后的动态规划：由于每次状态转移，只依赖于两个值 dp[i][j-1] 和 dp[i-1][j]，
所以只需要用一个一维数组dp[m] dp[m]保存某一行的所有值
每一次迭代相当于从左往右计算一行 dp[j]相当于dp[i-1][j]  dp[j-1] 相当于 dp[i][j-1]
时间复杂度 O(m*n)  空间复杂度 O(m)
*/
class Solution {
   public:
    int uniquePaths(int m, int n) {
        int dp[m];
        // 仅有一行、仅有一列的情况，只有一种走法
        for (int i = 0; i < m; i++) {
            dp[i] = 1;
        }
        // 状态转移，n行n-1次迭代 (n-1是因为第一行已经赋好值了)
        for (int i = 0; i < n - 1; i++) {
            for (int j = 1; j < m; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }

        return dp[m - 1];
    }
};

/*
* 动态规划
* 状态转移方程  dp[i][j] = dp[i-1][j] + dp[i][j-1];
* 其中 dp[1][m] = 1 ; dp[n][1] = 1 ; (若只有一行或一列的话，就只有一种走法)
* 时间复杂度 O(m*n)  空间复杂度 O(m*n)
*/
// class Solution {
//    public:
//     int uniquePaths(int m, int n) {
//         int dp[m + 1][n + 1];
//         // 仅有一行、仅有一列的情况，只有一种走法
//         for (int i = 1; i <= n; i++) {
//             dp[1][i] = 1;
//         }
//         for (int i = 1; i <= m; i++){
//             dp[i][1] = 1;
//         }
//         // 状态状态转移方程
//         for (int i = 2; i <= m; i++) {
//             for (int j = 2; j <= n; j++) {
//                 dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
//             }
//         }

//         return dp[m][n];
//     }
// };

/*
* 暴力递归回溯，超时
*/
// class Solution {
//    public:
//     int direction[2][2] = {{0, 1}, {1, 0}};

//     void dfs(int m, int n, int i, int j, int &cnt) {
//         if (i == m - 1 && j == n - 1) {
//             cnt++;
//             return;
//         }
//         int x, y;
//         for (int d = 0; d < 2; d++) {
//             x = i + direction[d][0];
//             y = j + direction[d][1];
//             if (x < m && y < n) {
//                 dfs(m, n, x, y, cnt);
//             }
//         }
//     }

//     int uniquePaths(int m, int n) {
//         int cnt = 0;
//         dfs(m, n, 0, 0, cnt);
//         return cnt;
//     }
// };
