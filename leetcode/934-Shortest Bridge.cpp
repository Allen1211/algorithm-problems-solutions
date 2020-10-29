/* 934. 最短的桥
在给定的二维二进制数组 A 中，存在两座岛。（岛是由四面相连的 1
形成的一个最大组。）

现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。

返回必须翻转的 0 的最小数目。（可以保证答案至少是 1。）
示例 1：

输入：[[0,1],[1,0]]
输出：1
示例 2：

输入：[[0,1,0],[0,0,0],[0,0,1]]
输出：2
示例 3：

输入：[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
输出：1


提示：

1 <= A.length = A[0].length <= 100
A[i][j] == 0 或 A[i][j] == 1

*/

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
   public:
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    queue<pair<int, int>> q;

    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        bool flag = true;

        // 先通过深搜找到第一个岛屿，把第一个岛屿的元素值全部改为2
        for (int i = 0; i < m && flag; i++) {
            for (int j = 0; j < n && flag; j++) {
                if (A[i][j] == 1) {
                    dfs(A, i, j, m, n);
                    flag = false;
                }
            }
        }

        int level = 0;

        while(!q.empty()){
            level++;

            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = i + d[k][0], y = j + d[k][1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if(A[x][y] == 1){
                            return level;
                        }else if(A[x][y] == 0){
                            q.push({x, y});
                            A[x][y] = 2;
                        }
                    }
                }
            }
        }

        return level;
    }

    void dfs(vector<vector<int>>& A, int i, int j, int& m, int& n) {
        if (A[i][j] == 2) {
            return;
        } else if (A[i][j] == 0) {
            q.push({i, j});
            return;
        }
        A[i][j] = 2;
        for (int k = 0; k < 4; k++) {
            int x = i + d[k][0], y = j + d[k][1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                dfs(A, x, y, m, n);
            }
        }

    }
};