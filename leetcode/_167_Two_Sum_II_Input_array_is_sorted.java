/*
 * @lc app=leetcode.cn id=167 lang=java
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start

public class _167_Two_Sum_II_Input_array_is_sorted {

    class Solution {
        public int[] twoSum(int[] numbers, int target) {
            int i = 0, j = numbers.length - 1;
            while (i < j) {
                int sum = numbers[i] + numbers[j];
                if (sum == target) {
                    return new int[] { i + 1, j + 1 };
                } else if (sum < target) {
                    i += 1;
                } else {
                    j -= 1;
                }
            }
            return new int[0];
        }
    }
}

// @lc code=end
