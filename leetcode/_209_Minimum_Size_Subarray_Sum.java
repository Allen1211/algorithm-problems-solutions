/*
 * @lc app=leetcode.cn id=209 lang=java
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
public class _209_Minimum_Size_Subarray_Sum {

    class Solution {
        public int minSubArrayLen(int s, int[] nums) {
            int result = Integer.MAX_VALUE;
            for (int i = 0, j = 0, sum = 0; i < nums.length; i++) {
                sum += nums[i];
                while(j <= i && sum >= s) {
                    result = Math.min(result, i - j + 1);
                    sum -= nums[j++];
                }
            }
            return result == Integer.MAX_VALUE ? 0 : result;
        }
    }
}
// @lc code=end
