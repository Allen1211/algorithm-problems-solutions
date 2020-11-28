import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class _315_Count_of_Smaller_Numbers_After_Self {
    class Solution {
        public List<Integer> countSmaller(int[] nums) {
            int len = nums.length;
            if (len == 0) {
                return Collections.emptyList();
            }
            int[] indexes = new int[len];
            int[] res = new int[len];
            int[] temp = new int[len];

            for (int i = 0; i < len; i++) {
                indexes[i] = i;
            }
            mergesort(nums, indexes, temp, res, 0, len - 1);
            return Arrays.stream(res).boxed().collect(Collectors.toList());
        }

        private void mergesort(int[] nums, int[] indexes, int[] temp, int[] res, int left, int right) {
            if (left == right) {
                return;
            }
            int mid = left + (right - left) / 2;
            mergesort(nums, indexes, temp, res, left, mid);
            mergesort(nums, indexes, temp, res, mid + 1, right);
            if (nums[indexes[mid]] <= nums[indexes[mid + 1]]) {
                return;
            }

            for (int i = left; i <= right; i++) {
                temp[i] = indexes[i];
            }
            int i = left, j = mid + 1;
            for (int k = left; k <= right; k++) {
                if (i > mid) {
                    indexes[k] = temp[j++];
                } else if (j > right) {
                    indexes[k] = temp[i++];
                    res[indexes[k]] += right - mid;
                } else if (nums[temp[i]] <= nums[temp[j]]) {
                    indexes[k] = temp[i++];
                    res[indexes[k]] += j - mid - 1;
                } else {
                    indexes[k] = temp[j++];
                }
            }
        }

    }

}