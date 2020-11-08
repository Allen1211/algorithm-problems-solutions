/*
 * @lc app=leetcode.cn id=140 lang=java
 *
 * [140] 单词拆分 II
 */

// @lc code=start

import java.util.*;

public class _140_Word_Break_II {

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.wordBreak("catsanddog", Arrays.asList("cat", "cats", "sand", "and", "dog")));
    }

    static class Solution {
        public List<String> wordBreak(String s, List<String> wordDict) {
            Set<String> dict = new HashSet<>(wordDict);
            Boolean[] memo = new Boolean[s.length() + 1];
            List<String> results = new ArrayList<>();
            List<String> sentence = new ArrayList<>();
            dfs(s, dict, memo, 0, sentence, results);

            return results;
        }

        private boolean dfs(String s, Set<String> dict, Boolean[] memo, int start, List<String> sentence,
                List<String> results) {
            if (start >= s.length()) {
                StringBuilder sb = new StringBuilder();
                sentence.forEach(word -> sb.append(word).append(" "));
                sb.deleteCharAt(sb.length() - 1);
                results.add(sb.toString());
                return true;
            }
            if (memo[start] != null && memo[start] == false) {
                return false;
            }
            boolean flag = false;
            for (int i = start + 1; i <= s.length(); i++) {
                String sub = s.substring(start, i);
                if (!dict.contains(sub)) {
                    continue;
                }
                sentence.add(sub);
                if (dfs(s, dict, memo, i, sentence, results)) {
                    memo[i] = true;
                    flag = true;
                }
                sentence.remove(sentence.size() - 1);
            }
            memo[start] = flag;
            return flag;
        }
    }
}

// @lc code=end
