import java.util.Arrays;

public class _283_Move_Zeroes {
    class Solution {
        public void moveZeroes(int[] nums) {
            int cnt = 0;
            for (int i = 0, j = 0; i < nums.length; i++) {
                if (nums[i] != 0) {
                    nums[j] = nums[i];
                    j++;
                } else {
                    cnt++;
                }
            }
            if (cnt > 0) {
                Arrays.fill(nums, nums.length - cnt, nums.length, 0);
            }
        }
    }
}