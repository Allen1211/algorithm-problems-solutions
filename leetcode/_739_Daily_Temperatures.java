import java.util.ArrayDeque;
import java.util.Deque;

public class _739_Daily_Temperatures {
    class Solution {
        public int[] dailyTemperatures(int[] T) {
            Deque<Integer> stack = new ArrayDeque<>(T.length);
            int[] res = new int[T.length];
            for (int i = 0; i < T.length; i++) {
                while(!stack.isEmpty() && T[i] > T[stack.peekLast()]) {
                    int j = stack.pollLast();
                    res[j] = i - j;
                }
                stack.addLast(i);
            }
            String a = "";
            
            return res;
        }
    }
}