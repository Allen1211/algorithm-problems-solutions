/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i], nums[i-1] + nums[i]);
            result = max(nums[i], result);
        }
        return result;
    }
};
// @lc code=end
