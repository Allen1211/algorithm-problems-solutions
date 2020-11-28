import javax.swing.border.EmptyBorder;

public class _5607 {
    class Solution {
        public int waysToMakeFair(int[] nums) {
            int res = 0;
            int oddSum = 0, evenSum = 0;
            for (int i = 0; i < nums.length; i += 2) {
                evenSum += nums[i];
            }
            for (int i = 1; i < nums.length; i += 2) {
                oddSum += nums[i];
            }
            int preOddSum = 0, preEvenSum = 0;
            for (int i = 0; i < nums.length; i++) {
                int odd = oddSum - preOddSum;
                int even = evenSum - preEvenSum;
                if (i % 2 == 0) {
                    even -= nums[i];
                } else {
                    odd -= nums[i];
                }
                // swap
                int t = even;
                even = odd;
                odd = t;

                even += preEvenSum;
                odd += preOddSum;

                if (even == odd) {
                    res++;
                }

                if (i % 2 == 0) {
                    preEvenSum += nums[i];
                } else {
                    preOddSum += nums[i];
                }
            }

            return res;
        }
    }
}