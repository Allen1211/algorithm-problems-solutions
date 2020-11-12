import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=300 lang=java
 *
 * [300] 最长上升子序列
 */

// @lc code=start

public class _300_Longest_Increasing_Subsequence {

    class Solution {
        public int lengthOfLIS(int[] nums) {
            if (nums.length <= 1) {
                return nums.length;
            }
            int[] dp = new int[nums.length];
            Arrays.fill(dp, 1);

            int max = 0;
            for (int i = 1; i < nums.length; i++) {
                for (int j = i - 1; j >= 0; j--) {
                    if (nums[i] > nums[j]) {
                        dp[i] = Math.max(dp[i], dp[j] + 1);
                        max = Math.max(max, dp[i]);
                    }
                }
            }

            return max;
        }
    }
}

// @lc code=end
