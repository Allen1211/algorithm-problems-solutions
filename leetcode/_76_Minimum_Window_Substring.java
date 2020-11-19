/* 
76. Minimum Window Substring
Hard

Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:

Input: s = "a", t = "a"
Output: "a"
 

Constraints:

1 <= s.length, t.length <= 105
s and t consist of English letters.
*/

public class _76_Minimum_Window_Substring {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.minWindow("ADOBECODEBANC", "ABC"));
        System.out.println(s.minWindow("ADOBECODEBANC", "ABBC"));
        System.out.println(s.minWindow("adobeCODEbanc", "cba"));
        System.out.println(s.minWindow("ADOBECODEBANC", "A"));
        System.out.println(s.minWindow("ADOBECODEBANC", "EN"));
        System.out.println(s.minWindow("A", "A"));
        System.out.println(s.minWindow("ABABCABC", "BC"));
        System.out.println(s.minWindow("a", "aa"));

    }

    static class Solution {
        public String minWindow(String s, String t) {
            int[] result = new int[] { 0, Integer.MAX_VALUE };
            int[] mapT = new int[58];
            int[] mapS = new int[58];
            int left = 0, right = 0;

            for (int i = 0; i < t.length(); ++i) {
                ++mapT[cIdx(t, i)];
            }
            while (right < s.length()) {

                while (right < s.length() && !stillValid(mapT, mapS)) {
                    if (mapT[cIdx(s, right)] > 0) {
                        ++mapS[cIdx(s, right)];
                    }
                    ++right;
                }

                while (left <= right && stillValid(mapT, mapS)) {
                    if (right - left < result[1] - result[0]) {
                        result[0] = left;
                        result[1] = right;
                    }
                    if (mapS[cIdx(s, left)] > 0) {
                        --mapS[cIdx(s, left)];
                    }
                    ++left;
                }

            }
            return s.substring(result[0], result[1] == Integer.MAX_VALUE ? 0 : result[1]);
        }

        private int cIdx(String s, int i) {
            return s.charAt(i) - 'A';
        }

        private boolean stillValid(int[] mapT, int[] mapS) {
            for (int i = 0; i < mapT.length; i++) {
                if (mapT[i] > mapS[i]) {
                    return false;
                }
            }
            return true;
        }
    }
}