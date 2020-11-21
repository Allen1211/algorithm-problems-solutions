import java.util.Deque;
import java.util.LinkedList;

public class _84_Largest_Rectangle_in_Histogram {

    /**
     * 暴力枚举 O(N^2) 枚举宽度，对于每一个i和j，宽为j-i+1, 高为 min(heights[i], heights[j])
     */
    class Solution1 {
        public int largestRectangleArea(int[] heights) {
            int res = 0;
            for (int i = 0; i < heights.length; i++) {
                int h = heights[i];
                for (int j = i; j < heights.length; j++) {
                    h = Math.min(heights[j], h);
                    res = Math.max(res, h * (j - i + 1));
                }
            }
            return res;
        }
    }

    /**
     * 暴力枚举 O(N^2) 枚举高度，对于每一个i，高度为heights[i] 宽度为，right - left - 1, 其中 left为 i
     * 向左找到第一个低于 heights[i]的柱形的下标， right 为 i 右边第一个低于 heights[i]的柱形的下标
     * 
     */
    class Solution2 {
        public int largestRectangleArea(int[] heights) {
            int res = 0;
            int n = heights.length;
            for (int i = 0; i < heights.length; i++) {
                int left = i;
                while (left > 0 && heights[left - 1] >= heights[i]) {
                    left--;
                }
                int right = i;
                while (right + 1 < n && heights[right + 1] >= heights[i]) {
                    right++;
                }
                res = Math.max(res, heights[i] * (right - left + 1));
            }
            return res;
        }
    }

    /**
     * 单调栈 + 哨兵 一次遍历
     * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/bao-li-jie-fa-zhan-by-liweiwei1419/
     */
    class Solution {
        public int largestRectangleArea(int[] heights) {
            int area = 0;

            int[] newHeights = new int[heights.length + 2];
            System.arraycopy(heights, 0, newHeights, 1, heights.length);
            newHeights[0] = newHeights[heights.length + 1] = 0;
            heights = newHeights;

            Deque<Integer> stack = new LinkedList<>();
            stack.addLast(0);
            for (int i = 1; i < heights.length; i++) {
                while (heights[i] < heights[stack.peekLast()]) {
                    int height = heights[stack.pollLast()];
                    int width = i - stack.peekLast() - 1;
                    area = Math.max(area, width * height);
                }
                stack.addLast(i);
            }
            return area;
        }
    }

    /**
     * 单调栈法2 2次遍历 分别记录每个柱形的左右第一个小的柱形
     * 
     */
    class Solution3 {
        public int largestRectangleArea(int[] heights) {
            int res = 0;
            int n = heights.length;

            int[] left = new int[n];
            int[] right = new int[n];
            Deque<Integer> stack = new LinkedList<>();

            for (int i = 0; i < n; i++) {
                while (!stack.isEmpty() && heights[stack.getFirst()] >= heights[i]) {
                    stack.pop();
                }
                if (stack.isEmpty()) {
                    left[i] = -1;
                } else {
                    left[i] = stack.getFirst();
                }
                stack.push(i);
            }

            stack.clear();
            for (int i = n - 1; i >= 0; i--) {
                while (!stack.isEmpty() && heights[stack.getFirst()] >= heights[i]) {
                    stack.pop();
                }
                if (stack.isEmpty()) {
                    right[i] = n;
                } else {
                    right[i] = stack.getFirst();
                }
                stack.push(i);
            }

            for (int i = 0; i < n; i++) {
                res = Math.max(res, heights[i] * (right[i] - left[i] - 1));
            }

            return res;
        }
    }
}