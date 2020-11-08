/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start

#include <vector>

using namespace std;

// class Solution {
//    public:
//     int maxProfit(vector<int>& prices) {
//         if(prices.empty()) return 0;
//         int total = 0, profit = 0;
//         int low = prices[0];
//         for (int i = 1; i < prices.size(); i++) {
//             if (prices[i] <= prices[i - 1]) {
//                 if(profit != 0) {
//                     total += profit;
//                     profit = 0;
//                 }
//                 low = prices[i];
//             } else {
//                 profit = prices[i]  - low;
//             }
//         }
//         total += profit;
//         return total;
//     }
// };

// class Solution {
//    public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.empty()) return 0;
//         int n = prices.size();
//         int dp[n][2];
//         dp[0][0] = 0;
//         dp[0][1] = -prices[0];
//         for (int i = 1; i < prices.size(); i++) {
//             dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
//             dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
//         }
//         return dp[n-1][0];
//     }
// };

class Solution {
   public:
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
