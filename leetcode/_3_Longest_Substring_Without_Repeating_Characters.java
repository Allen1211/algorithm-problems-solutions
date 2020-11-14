/*
 * @lc app=leetcode.cn id=3 lang=java
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

public class _3_Longest_Substring_Without_Repeating_Characters {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.lengthOfLongestSubstring("abcabcbb"));
        ;

    }

    static class Solution {
        public int lengthOfLongestSubstring(String s) {
            int result = 0;
            int[] bucket = new int[256];

            int i = 0, j = 0;
            while (i < s.length() && j < s.length()) {
                bucket[s.charAt(j)]++;
                if (1 == bucket[s.charAt(j)]) {
                    result = Math.max(result, j - i + 1);
                } else {
                    while (i < s.length() && bucket[s.charAt(j)] >= 2) {
                        bucket[s.charAt(i)]--;
                        i++;
                    }
                }
                j++;
            }
            return result;
        }
    }
    
}

// @lc code=end
