import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=523 lang=java
 *
 * [523] 连续的子数组和
 */

// @lc code=start

public class _523_Continuous_Subarray_Sum {

    class Solution {
        public boolean checkSubarraySum(int[] nums, int k) {
            Map<Integer, Integer> map = new HashMap<>();
            map.put(0, -1);
    
            int preSum = 0;
            for (int i = 0; i < nums.length; i++) {
                preSum += nums[i];
                if (k != 0) {
                    preSum %= k;
                }
                if (map.containsKey(preSum)) {
                    if (i - map.get(preSum) > 1) {
                        return true;
                    }
                } else {
                    map.put(preSum, i);
                }
            }
            return false;
        }
    }
}
// @lc code=end
