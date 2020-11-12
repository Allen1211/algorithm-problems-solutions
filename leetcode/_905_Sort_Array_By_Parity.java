import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.function.ToIntFunction;

/*
 * @lc app=leetcode.cn id=905 lang=java
 *
 * [905] 按奇偶排序数组
 */

// @lc code=start

public class _905_Sort_Array_By_Parity {
    class Solution {
        public int[] sortArrayByParity(int[] A) {
            for (int j = 0, i = 0; j < A.length; j++) {
                if ((A[j] & 1) == 0) {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                    i++;
                }
            }
            return A;
        }

    }
    class Solution2 {
        public int[] sortArrayByParity(int[] A) {
            return Arrays.stream(A)
            .boxed()
            .sorted((a, b) -> (a & 1) - (b & 1))
            .mapToInt(Integer::valueOf)
            .toArray();
        }
    }
}

// @lc code=end
