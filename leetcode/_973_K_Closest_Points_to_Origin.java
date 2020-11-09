import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=973 lang=java
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start

public class _973_K_Closest_Points_to_Origin {

    static class Solution {

        public int[][] kClosest(int[][] points, int K) {
            if(points.length == 0 || K == points.length) {
                return points;
            }else {
                int left = 0, right = points.length - 1;
                while(true) {
                    int pivot = partition(points, left, right);
                    if(pivot == K) {
                        break;
                    }else if(pivot < K) {
                        left = pivot + 1;
                    }else {
                        right = pivot - 1;
                    }
                }
                return Arrays.copyOfRange(points, 0, K);              
            }
        }

        private int partition(int[][] points, int left, int right) {
            if (left >= right) {
                return left;
            }
            int pivot = left;
            int i = left + 1, j = right;
            while (i <= j) {
                while (i <= right && distance(points[i]) <= distance(points[pivot])) {
                    i++;
                }
                while (j > left && distance(points[j]) >= distance(points[pivot])) {
                    j--;
                }
                if (i > j) {
                    break;
                }
                swap(points, i, j);
            }
            swap(points, j, pivot);
            return j;
        }

        private double distance(int[] point) {
            return Math.sqrt(point[0] * point[0] + point[1] * point[1]);
        }

        private <T> void swap(T[] arr, int i, int j) {
            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}

// @lc code=end
