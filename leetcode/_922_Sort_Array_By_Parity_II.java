/*
 * @lc app=leetcode.cn id=922 lang=java
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start

public class _922_Sort_Array_By_Parity_II {
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        // 排序后，前面一半是偶数，后面一半是奇数
        sortArrayByParity(A);
        // 把偶数区的奇数下标的元素 与 奇数区的偶数下标的元素交换
        for (int i = 1, j = A.length - 2; i < j; i += 2, j -= 2) {
            swap(A, i, j);
        }
        return A;
    }

    public int[] sortArrayByParity(int[] A) {
        for (int j = 0, i = 0; j < A.length; j++) {
            if ((A[j] & 1) == 0) {
                swap(A, i, j);
                i++;
            }
        }
        return A;
    }

    private void swap(int[] A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

}
// @lc code=end
