import java.util.Arrays;

public class _51 {
    class Solution {
        public int reversePairs(int[] nums) {
            if (nums.length <= 1) {
                return 0;
            }
            int mid = nums.length / 2;
            int[] subA = Arrays.copyOfRange(nums, 0, mid);
            int[] subB = Arrays.copyOfRange(nums, mid, nums.length);
            int leftCnt = reversePairs(subA);
            int rightCnt = reversePairs(subB);
            return leftCnt + rightCnt + mergeAndCount(nums, subA, subB);
        }

        private int mergeAndCount(int[] arr, int[] subA, int[] subB) {
            int i = 0, j = 0, k = 0;
            int cnt = 0;
            while (i < subA.length && j < subB.length) {
                if (subA[i] <= subB[j]) {
                    arr[k++] = subA[i++];
                } else {
                    cnt += subA.length - i;
                    arr[k++] = subB[j++];
                }
            }
            while (i < subA.length) arr[k++] = subA[i++]; 
            while (j < subB.length) arr[k++] = subB[j++]; 
            return cnt;
        }
    }
}