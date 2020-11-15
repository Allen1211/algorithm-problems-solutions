/*
 * @lc app=leetcode.cn id=53 lang=java
 *
 * [53] 最大子序和
 */

// @lc code=start

public class _53_Maximum_Subarray {
    class Solution {
        public int maxSubArray(int[] nums) {
            if(nums.length == 0) {
                return Integer.MIN_VALUE;
            }
            int maxSum = nums[0];
            for (int i = 1; i < nums.length; i++) {
                nums[i] = Math.max(nums[i - 1] + nums[i], nums[i]);
                maxSum = Math.max(maxSum, nums[i]);
            }
            return maxSum;
        }
    }
}

// @lc code=end
