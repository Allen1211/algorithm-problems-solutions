import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;


/*
 * @lc app=leetcode.cn id=451 lang=java
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start

public class _451_Sort_Characters_By_Frequency {
    class Solution {
        public String frequencySort(String s) {
            Map<Character, Integer> bucket = new HashMap<>();
            char[] chs = s.toCharArray();
            for (char ch : chs) {
                int cnt = bucket.getOrDefault(ch, 0);
                bucket.put(ch, cnt + 1);
            }
            
            PriorityQueue<Map.Entry<Character, Integer>> pq = new PriorityQueue<>((p1, p2) -> {
                return p2.getValue() - p1.getValue();
            });
            pq.addAll(bucket.entrySet());
            
            StringBuilder sb = new StringBuilder();
            while (!pq.isEmpty()) {
                Map.Entry<Character, Integer> entry = pq.poll();
                char c = entry.getKey().charValue();
                int cnt = entry.getValue().intValue();
                for (int i = 0; i < cnt; i++) {
                    sb.append(c);
                }
            }
            
            return sb.toString();
        }
    }
}
// @lc code=end
