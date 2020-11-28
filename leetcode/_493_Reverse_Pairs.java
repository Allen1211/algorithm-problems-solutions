public class _493_Reverse_Pairs {
    class Solution {
        public int reversePairs(int[] nums) {
            int len = nums.length;
            if (len <= 1) {
                return 0;
            }
            int[] temp = new int[len];
            return mergesort(nums, temp, 0, len - 1);
        }

        private int mergesort(int[] nums, int[] temp, int left, int right) {
            if (left == right) {
                return 0;
            }
            int mid = left + (right - left) / 2;
            int leftCnt = mergesort(nums, temp, left, mid);
            int rightCnt = mergesort(nums, temp, mid + 1, right);

            int cnt = 0;
            for (int i = left; i <= right; i++) {
                temp[i] = nums[i];
            }
            // 统计翻转对
            for (int i = left, j = mid + 1; i <= mid && j <= right;) {
                long a = temp[i], b = temp[j];
                if (a <= 2 * b) {
                    i++;
                } else {
                    j++;
                    cnt += mid - i + 1;
                }
            }
            int i = left, j = mid + 1;
            for (int k = left; k <= right; k++) {
                if (i > mid) {
                    nums[k] = temp[j++];
                } else if (j > right) {
                    nums[k] = temp[i++];
                } else if (temp[i] <= temp[j]) {
                    nums[k] = temp[i++];
                } else {
                    nums[k] = temp[j++];
                }
            }

            return leftCnt + rightCnt + cnt;
        }
    }
}