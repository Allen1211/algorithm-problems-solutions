import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=560 lang=java
 *
 * [560] 和为K的子数组
 */

// @lc code=start

public class _560_Subarray_Sum_Equals_K {
    class Solution {
        public int subarraySum(int[] nums, int k) {
            int result = 0;
            Map<Integer, Integer> preSum = new HashMap<>();
            preSum.put(0, 1);
    
            int sum_i = 0;
            for (int i = 0; i < nums.length; i++) {
                sum_i += nums[i];
                int sum_j = sum_i - k;
                
                result += preSum.getOrDefault(sum_j, 0);
                preSum.put(sum_i, preSum.getOrDefault(sum_i, 0) + 1);
            }
    
            return result;
        }
    }
}

// @lc code=end
