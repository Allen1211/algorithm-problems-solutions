/*
 * @lc app=leetcode.cn id=1122 lang=java
 *
 * [1122] 数组的相对排序
 */

// @lc code=start

public class _1122_Relative_Sort_Array {

    class Solution {
        public int[] relativeSortArray(int[] arr1, int[] arr2) {
            if(arr1.length == 0 || arr2.length == 0) {
                return new int[0];
            }
            int maxVal = -1;
            for (int val : arr1) {
                maxVal = Math.max(val, maxVal);
            }
            int[] bucket = new int[maxVal + 1];
            for (int i = 0; i < arr1.length; i++) {
                bucket[arr1[i]]++;
            }
            int[] result = new int[arr1.length];
            int n = 0;
            for (int i = 0; i < arr2.length; i++) {
                for (int k = 0; k < bucket[arr2[i]]; k++) {
                    result[n++] = arr2[i];
                }
                bucket[arr2[i]] = 0;
            }
            for (int i = 0; i < bucket.length; i++) {
                for (int k = 0; k < bucket[i]; k++) {
                    result[n++] = i;
                }
            }
    
            return result;
        }
    }
}

// @lc code=end
