import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=452 lang=java
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start

public class _452_Minimum_Number_of_Arrows_to_Burst_Balloons {

    class Solution {
        public int findMinArrowShots(int[][] points) {
            int length = points.length;
            if (length <= 1) {
                return length;
            }
            Arrays.sort(points, (a, b) -> Integer.compare(a[1], b[1]));

            int nonOverlapping = 1;
            int prev = 0;
            for (int i = 1; i < length; i++) {
                if (points[i][0] > points[prev][1]) {
                    nonOverlapping++;
                    prev = i;
                }
            }
            return nonOverlapping;
        }
    }

    // class Solution {
    // public int findMinArrowShots(int[][] points) {
    // int length = points.length;
    // if (length <= 1) {
    // return length;
    // }
    // Arrays.sort(points, (a, b) -> a[1] - b[1]);

    // int[] dp = new int[length];
    // Arrays.fill(dp, 1);

    // int nonOverlapping = 1;

    // for (int i = 1; i < length; i++) {
    // for (int j = 0; j < i; j++) {
    // if (points[i][0] > points[j][1]) {
    // dp[i] = Math.max(dp[i], dp[j] + 1);
    // nonOverlapping = Math.max(nonOverlapping, dp[i]);
    // }
    // }
    // }

    // return nonOverlapping;
    // }
    // }
}

// @lc code=end
