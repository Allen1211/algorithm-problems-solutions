/*
 * @lc app=leetcode.cn id=209 lang=java
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
public class _209_Minimum_Size_Subarray_Sum {

    class Solution {
        public int minSubArrayLen(int s, int[] nums) {
            if (nums.length == 0) {
                return 0;
            }
            int result = nums.length + 1;
            int sum = nums[0];
            for (int i = 0, j = 0; i < nums.length && j < nums.length;) {
                if (sum >= s) {
                    if (i == j)
                        return 1;
                    result = Math.min(j - i + 1, result);
                    sum -= nums[i];
                    i += 1;
                } else {
                    j += 1;
                    if (j < nums.length) {
                        sum += nums[j];
                    }
                }
            }
            return result != nums.length + 1 ? result : 0;
        }
    }
}
// @lc code=end
