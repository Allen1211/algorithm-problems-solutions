/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int dp0 = 0;
        int dp1 = -prices[0];
        for(int i = 1; i < prices.size(); i++) {
            dp0 = max(dp0, dp1 + prices[i]);
            dp1 = max(dp1, -prices[i]);
        }
        return dp0;
    }
};
// class Solution {
//    public:
//     int maxProfit(vector<int>& prices) {
//         if(prices.empty()) return 0;
//         int result = 0;
//         int low = prices[0];
//         for (int i = 1; i < prices.size(); i++) {
//             if (prices[i] <= prices[i - 1]) {
//                 low = min(low, prices[i]);
//             } else {
//                 result = max(result, prices[i] - low);
//             }
//         }
//         return result;
//     }
// };
// @lc code=end
