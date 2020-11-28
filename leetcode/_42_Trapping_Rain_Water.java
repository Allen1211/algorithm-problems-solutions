import java.util.ArrayDeque;
import java.util.Deque;

public class _42_Trapping_Rain_Water {

    class Solution {
        public int trap(int[] height) {
            int res = 0;
            Deque<Integer> stack = new ArrayDeque<>(height.length);
            for (int i = 0; i < height.length; i++) {
                if (!stack.isEmpty() && height[i] > height[stack.peekLast()]) {
                    int h = Math.min(height[stack.peekFirst()], height[i]);
                    while (!stack.isEmpty() && height[i] > height[stack.peekLast()]) {
                        int j = stack.pollLast();
                        int w = stack.isEmpty() ? 1 : j - stack.peekLast();
                        res += (h - height[j]) * w;
                    }
                }
                stack.addLast(i);
            }
            return res;
        }
    }

    class Solution2 {
        public int trap(int[] height) {
            int res = 0;
            Deque<Integer> stack = new ArrayDeque<>(height.length);
            for (int i = 0; i < height.length; i++) {
                while (!stack.isEmpty() && height[i] > height[stack.peekLast()]) {
                    int j = stack.pollLast();
                    if (stack.isEmpty()) {
                        break;
                    }
                    int h = Math.min(height[stack.peekLast()], height[i]);
                    int w = i - stack.peekLast() - 1;
                    res += (h - height[j]) * w;
                }
                stack.addLast(i);
            }
            return res;
        }
    }
}