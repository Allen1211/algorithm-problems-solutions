import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
 * @lc app=leetcode.cn id=41 lang=java
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
public class _41_First_Missing_Positive {

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.firstMissingPositive(new int[] { 1, 1 });

    }

    class Solution1 {
        public int firstMissingPositive(int[] nums) {
            Set<Integer> set = new HashSet<>();
            for (int num : nums) {
                set.add(num);
            }
            for (int i = 1;; i++) {
                if (!set.contains(i)) {
                    return i;
                }
            }
        }
    }

    static class Solution {
        public int firstMissingPositive(int[] nums) {
            int N = nums.length;
            for (int i = 1; i <= N;) {
                int val = nums[i - 1];
                if (val >= 1 && val <= N && val != i && nums[val - 1] != val) {
                    swap(nums, i - 1, val - 1);
                } else {
                    i++;
                }
            }
            for (int k = 1; k <= N; k++) {
                if (nums[k - 1] != k) {
                    return k;
                }
            }
            return N + 1;
        }

        private void swap(int[] nums, int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}
// @lc code=end
