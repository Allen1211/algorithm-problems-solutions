import java.util.*;

/*
 * @lc app=leetcode.cn id=57 lang=java
 *
 * [57] 插入区间
 */

// @lc code=start

public class _57_Insert_Intervals {
    class Solution {
        public int[][] insert(int[][] intervals, int[] newInterval) {
            List<int[]> result = new ArrayList<>();
            int left = newInterval[0], right = newInterval[1];
            boolean placed = false;
            for (int[] interval : intervals) {
                if (left > interval[1]) {
                    result.add(interval);
                } else if (right < interval[0]) {
                    if(!placed) {
                        result.add(new int[]{left, right});
                        placed = true;
                    }
                    result.add(interval);
                } else {
                    left = Math.min(left, interval[0]);
                    right = Math.max(right, interval[1]);
                }
            }
            if(!placed) {
                result.add(new int[] { left, right });
            }
            return result.toArray(new int[0][0]);
        }
    }

    // class Solution {
    //     public int[][] insert(int[][] intervals, int[] newInterval) {
    //         int len = intervals.length;
    //         List<int[]> result = new ArrayList<>();

    //         int left = newInterval[0], right = newInterval[1];
    //         int leftIdx = len, rightIdx = len;
    //         for(int i = 0; i < len; i++) {
    //             if(newInterval[0] > intervals[i][1]) {
    //                 result.add(intervals[i]);
    //             }else {
    //                 left = Math.min(intervals[i][0], newInterval[0]);
    //                 leftIdx = i;
    //                 break;
    //             }
    //         }
    //         for(int i = leftIdx; i < len; i++) {
    //             if(newInterval[1] < intervals[i][0]) {
    //                 right = newInterval[1];
    //                 rightIdx = i - 1;
    //                 break;
    //             }else if(newInterval[1] <= intervals[i][1]) {
    //                 right = intervals[i][1];
    //                 rightIdx = i;
    //                 break;
    //             }
    //         }

    //         result.add(new int[]{left, right});

    //         for(int i = rightIdx + 1; i < len; i++) {
    //             result.add(intervals[i]);
    //         }

    //         return result.toArray(new int[0][0]);
    //     }
    // }
}
// @lc code=end
