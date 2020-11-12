/*
 * @lc app=leetcode.cn id=11 lang=java
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

public class _11_Container_With_Most_Water {

    class Solution {
        public int maxArea(int[] height) {
            int result = 0;
            int left = 0, right = height.length - 1;
            while (left < right) {
                int area = Math.min(height[left], height[right]) * (right - left);
                result = Math.max(result, area);
                if (height[left] < height[right]) {
                    left++;
                } else {
                    right--;
                }
            }
            return result;
        }
    }
}

// @lc code=end
