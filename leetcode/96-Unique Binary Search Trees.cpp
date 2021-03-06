/* 96. 不同的二叉搜索树
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3 */

using namespace std;

class Solution {
   public:
    int numTrees(int n) {
        int dp[n + 1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            for (int x = 0; x < i; x++) {
                dp[i] += dp[x] * dp[i - x - 1];
            }
        }

        return dp[n];
    }
};

int main() {
    Solution s;
    s.numTrees(4);
}