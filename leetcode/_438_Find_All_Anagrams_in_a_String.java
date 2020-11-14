import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode.cn id=438 lang=java
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start

public class _438_Find_All_Anagrams_in_a_String {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.findAnagrams("cbaebabacd", "abc"));
        ;
    }

    static class Solution {
        public List<Integer> findAnagrams(String s, String p) {
            List<Integer> result = new ArrayList<>();
            int lenS = s.length();
            int lenP = p.length();

            if (lenP > lenS) {
                return result;
            }

            int[] need = new int[26];
            int[] window = new int[26];

            for (int i = 0; i < lenP; i++) {
                need[p.charAt(i) - 'a']++;
            }

            for (int i = 0, j = 0; i < lenS && j < lenS; j++) {
                int idx = s.charAt(j) - 'a';
                window[idx]++;
                while (i < lenS && window[idx] > need[idx]) {
                    if (need[idx] == 0) {
                        i = j + 1;
                        Arrays.fill(window, 0);
                        break;
                    } else {
                        window[s.charAt(i) - 'a']--;
                        i++;
                    }
                }
                if (j - i + 1 == lenP) {
                    result.add(i);
                }
            }
            return result;
        }
    }

    class Solution1 {
        public List<Integer> findAnagrams(String s, String p) {
            List<Integer> result = new ArrayList<>();

            int lenS = s.length();
            int lenP = p.length();

            if (lenP > lenS) {
                return result;
            }

            int[] bucketP = new int[26];
            int[] bucketS = new int[26];

            for (int i = 0; i < p.length(); i++) {
                bucketP[p.charAt(i) - 'a']++;
                bucketS[s.charAt(i) - 'a']++;
            }

            int i = 0;
            int j = i + lenP - 1;
            while (j < lenS) {
                if (Arrays.equals(bucketP, bucketS)) {
                    result.add(i);
                }
                if (j < lenS - 1) {
                    bucketS[s.charAt(++j) - 'a']++;
                    bucketS[s.charAt(i++) - 'a']--;
                } else {
                    break;
                }
            }
            return result;
        }
    }
}
// @lc code=end
