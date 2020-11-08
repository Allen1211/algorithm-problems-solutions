/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start

#include <vector>

using namespace std;

// class Solution {
//    public:
//     int maxProfit(vector<int>& prices) {
//         if (prices.empty()) return 0;
//         int n = prices.size();
//         int dp[n][3][2];
        
//         dp[0][1][0] = 0;
//         dp[0][2][0] = 0;
//         dp[0][1][1] = -prices[0];
//         dp[0][2][1] = -prices[0];

//         for (int i = 1; i < prices.size(); i++) {
//             dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
//             dp[i][1][1] = max(dp[i - 1][1][1], - prices[i]);
            
//             dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i]);
//             dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i]);
//         }
//         return dp[n-1][2][0];
//     }
// };

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int dp_1_0 = 0;
        int dp_2_0 = 0;
        int dp_1_1 = -prices[0];
        int dp_2_1 = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp_2_0 = max(dp_2_0, dp_2_1 + prices[i]);
            dp_2_1 = max(dp_2_1, dp_1_0 - prices[i]);
            dp_1_0 = max(dp_1_0, dp_1_1 + prices[i]);
            dp_1_1 = max(dp_1_1, - prices[i]);
        }
        return dp_2_0;
    }
};


// @lc code=end

