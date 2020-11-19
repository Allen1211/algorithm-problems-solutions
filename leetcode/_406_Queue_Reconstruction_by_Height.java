import java.util.Arrays;
import java.util.*;
/*
 * @lc app=leetcode.cn id=406 lang=java
 *
 * [406] 根据身高重建队列
 */

// @lc code=start

public class _406_Queue_Reconstruction_by_Height {

    class Solution {
        public int[][] reconstructQueue(int[][] people) {

            Arrays.sort(people, (p1, p2) -> {
                return p1[0] != p2[0] ? p1[0] - p2[0] : p1[1] - p2[1];
            });

            int[][] result = new int[people.length][2];

            List<Integer> idxes = new ArrayList<>();
            for (int i = 0; i < people.length; i++) {
                idxes.add(i);
            }

            int cnt = 0, repeat = 1;
            for (int i = 0; i < people.length; i++) {
                if (i != 0 && people[i][0] == people[i - 1][0]) {
                    cnt = people[i][1] - repeat;
                    repeat++;
                } else {
                    cnt = people[i][1];
                    repeat = 1;
                }
                int j = idxes.get(cnt);
                result[j] = people[i];

                idxes.remove(cnt);
            }

            return result;
        }
    }
}

// @lc code=end
