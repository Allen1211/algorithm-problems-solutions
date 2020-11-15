import java.util.HashMap;
import java.util.Map;

public class _5602 {
    class Solution {

        public int minOperations(int[] nums, int x) {
            int n = nums.length;
            int result = n + 1;

            Map<Integer, Integer> mp = new HashMap<>();
            mp.put(0, -1);

            // 前缀和计算，将所有小于x的前缀和放入哈希表
            int prefixSum = 0;
            for (int i = 0; i < n; i++) {
                prefixSum += nums[i];
                if (prefixSum > x) {
                    break;
                }
                mp.put(prefixSum, i);
            }

            // 如果某个前缀和中已经包含结果，则答案可以暂时为前缀和的元素个数
            if (mp.containsKey(x)) {
                result = mp.get(x) + 1;
            }

            // 对每一个后缀和，
            // 尝试找到一个前缀和使得 前缀和 + 后缀和 == x
            int postfixSum = 0;
            for (int i = n - 1; i >= 0; i--) {
                postfixSum += nums[i];
                if (postfixSum > x) {
                    break;
                }

                if (x - postfixSum >= 0 && mp.containsKey(x - postfixSum)) {
                    int prefixIdx = mp.get(x - postfixSum);
                    if (prefixIdx < i) {
                        result = Math.min(prefixIdx + 1 + n - i, result);
                    }
                }

            }

            return result == n + 1 ? -1 : result;
        }
    }

    class Solution1 {

        public int minOperations(int[] nums, int x) {
            return dfs(nums, 0, nums.length - 1, x, 0);
        }

        private int dfs(int[] nums, int left, int right, int x, int steps) {
            if (x == 0) {
                return steps;
            }
            if (x < 0 || left > right) {
                return -1;
            }
            int leftStep = dfs(nums, left + 1, right, x - nums[left], steps + 1);
            int rightStep = dfs(nums, left, right - 1, x - nums[right], steps + 1);

            if (leftStep != -1 && rightStep != -1) {
                return Math.min(leftStep, rightStep);
            } else {
                return Math.max(leftStep, rightStep);
            }
        }
    }

}