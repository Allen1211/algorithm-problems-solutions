public class _164_Maximum_Gap {

    class Solution {
        public int maximumGap(int[] nums) {
            int res = 0;
            if (nums.length >= 2) {
                radixsort(nums);
                for (int i = 1; i < nums.length; i++) {
                    res = Math.max(nums[i] - nums[i - 1], res);
                }
            }
            return res;
        }

        private void radixsort(int[] arr) {
            int max = arr[0];
            for (int n : arr) {
                max = Math.max(max, n);
            }
            for (int exp = 1; max / exp > 0; exp *= 10) {
                int n = arr.length;
                int[] output = new int[n];
                int[] bucket = new int[10];
                for (int i = 0; i < n; i++) {
                    bucket[(arr[i] / exp) % 10]++;
                }
                for (int i = 1; i < 10; i++) {
                    bucket[i] += bucket[i - 1];
                }
                for (int i = n - 1; i >= 0; i--) {
                    output[bucket[(arr[i] / exp) % 10] - 1] = arr[i];
                    bucket[(arr[i] / exp) % 10]--;
                }
                System.arraycopy(output, 0, arr, 0, n);
            }
        }
    }

}