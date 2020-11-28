import java.util.ArrayDeque;
import java.util.Deque;

public class _918_Maximum_Sum_Circular_Subarray {

    /**
     * https://leetcode-cn.com/problems/maximum-sum-circular-subarray/solution/dong-tai-gui-hua-zui-da-zi-duan-he-fen-zhi-si-xian/
     */
    class Solution {
        public int maxSubarraySumCircular(int[] A) {
            if (A.length == 1) {
                return A[0];
            }
            int sum = 0;
            for (int n : A) {
                sum += n;
            }
            return Math.max(maxSubarraySum(A), sum - minSubarraySum(A));
        }

        private int maxSubarraySum(int[] A) {
            int res = 0, sum = 0;
            for (int i = 0; i < A.length; i++) {
                sum = Math.max(sum + A[i], A[i]);
                res = Math.max(res, sum);
            }
            return res;
        }

        private int minSubarraySum(int[] A) {
            int res = Integer.MAX_VALUE, sum = 0;
            for (int i = 1; i < A.length - 1; i++) {
                sum = Math.min(sum + A[i], A[i]);
                res = Math.min(res, sum);
            }
            return res;
        }

    }

    /**
     * 前缀和 + 单调队列
     */
    class Solution1 {
        public int maxSubarraySumCircular(int[] A) {
            if (A.length == 1)
                return A[0];
            int[] B = new int[2 * A.length];
            for (int i = 0; i < A.length; i++)
                B[i] = A[i];
            for (int i = 0; i < A.length; i++)
                B[A.length + i] = A[i];

            int[] presum = new int[B.length];
            for (int i = 0; i < B.length; i++) {
                if (i == 0) {
                    presum[i] = B[i];
                } else {
                    presum[i] = presum[i - 1] + B[i];
                }
            }
            int res = Integer.MIN_VALUE;
            int k = A.length;
            Deque<Integer> deque = new ArrayDeque<>();
            for (int i = 0; i < B.length; i++) {
                if (!deque.isEmpty()) {
                    res = Math.max(res, presum[i] - presum[deque.peekFirst()]);
                }
                if (!deque.isEmpty() && i - k == deque.peekFirst()) {
                    deque.pollFirst();
                }
                while (!deque.isEmpty() && presum[i] <= presum[deque.peekLast()]) {
                    deque.pollLast();
                }
                deque.addLast(i);
            }
            return res;
        }
    }
}