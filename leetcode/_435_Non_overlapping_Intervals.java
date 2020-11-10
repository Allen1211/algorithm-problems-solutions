import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=435 lang=java
 *
 * [435] 无重叠区间
 */

// @lc code=start
public class _435_Non_overlapping_Intervals {

    class Solution1 {
        public int eraseOverlapIntervals(int[][] intervals) {
            Arrays.sort(intervals, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
            int result = 0, bound = Integer.MIN_VALUE;
            for (int[] curr : intervals) {
                if (curr[0] < bound) {
                    bound = Math.min(bound, curr[1]);
                    result++;
                } else {
                    bound = curr[1];
                }
            }
            return result;
        }
    }

    class Solution2 {
        public int eraseOverlapIntervals(int[][] intervals) {
            if (intervals.length == 0) {
                return 0;
            }
            Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
            int count = 1;
            int bound = intervals[0][1];
            for (int i = 1; i < intervals.length; i++) {
                int[] curr = intervals[i];
                if (curr[0] >= bound) {
                    bound = curr[1];
                    count++;
                }

            }
            return intervals.length - count;
        }
    }

    class Solution3 {
        public int eraseOverlapIntervals(int[][] intervals) {
            int length = intervals.length;
            if (intervals.length == 0) {
                return 0;
            }
            Arrays.sort(intervals, (a, b) -> a[1] - b[1]);

            int[] dp = new int[length];
            Arrays.fill(dp, 1);

            int maxNumOfUnOverlapp = 1;

            for (int i = 1; i < length; i++) {
                for (int j = i - 1; j >= 0; j--) {
                    if (intervals[i][0] >= intervals[j][1]) {
                        dp[i] = Math.max(dp[i], dp[j] + 1);
                        break;
                    }
                }
                dp[i] = Math.max(dp[i], dp[i - 1]);
                maxNumOfUnOverlapp = Math.max(maxNumOfUnOverlapp, dp[i]);
            }
            return length - maxNumOfUnOverlapp;
        }
    }
}
// @lc code=end
