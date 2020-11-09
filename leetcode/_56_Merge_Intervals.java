import java.util.Arrays;
import java.util.*;

/*
 * @lc app=leetcode.cn id=56 lang=java
 *
 * [56] 合并区间
 */

// @lc code=start

public class _56_Merge_Intervals {
    class Solution {
        public int[][] merge(int[][] intervals) {
            if(intervals.length <= 1) {
                return intervals;
            }
            Arrays.sort(intervals, (a, b) -> {
                return a[0] - b[0];
            });
            List<int[]> result = new ArrayList<>();
            for (int i = 0; i < intervals.length; i++) {
                int left = intervals[i][0];
                int right = intervals[i][1];
                if(i == 0 || left > result.get(result.size() - 1)[1]) {
                    result.add(new int[]{left, right});
                }else {
                    int[] last = result.get(result.size() - 1);
                    last[1] = Math.max(last[1], right);
                }
            }
            return result.toArray(new int[0][0]);
        }
    }

}

// @lc code=end
