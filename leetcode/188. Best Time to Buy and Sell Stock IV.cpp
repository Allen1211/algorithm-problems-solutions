/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size();
        if (k >= n / 2) {
            return maxProfit(prices);
        }

        int dp[k + 1][2];

        for (int i = 0; i <= k; i++) {
            dp[i][0] = 0;
            dp[i][1] = -prices[0];
        }

        for (int i = 0; i < n; i++) {
            for (int j = k; j > 0; j++) {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
            }
        }
        return dp[k][0];
    }

    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int dp0 = 0;
        int dp1 = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            int new_dp0 = max(dp0, dp1 + prices[i]);
            int new_dp1 = max(dp1, dp0 - prices[i]);
            dp0 = new_dp0;
            dp1 = new_dp1;
        }
        return dp0;
    }
};
// @lc code=end
