
/** 139. 单词拆分
给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s
是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false 
*/

import java.util.*;

public class _139_Word_Break {
    public static void main(String[] args) {
        Solution s = new Solution();
        boolean result = s.wordBreak("leetcode", Arrays.asList("leet", "code"));
        System.out.println(result);
    }

    /**
     * 动态规划
     * https://leetcode-cn.com/problems/word-break/solution/dan-ci-chai-fen-by-leetcode-solution/
     */
    // static class Solution {
    // public boolean wordBreak(String s, List<String> wordDict) {
    // int len = s.length();
    // Set<String> dict = new HashSet<>(wordDict);
    // boolean[] dp = new boolean[len + 1];
    // dp[0] = true;
    // for (int i = 1; i <= len; i++) {
    // for (int j = i - 1; j >= 0; j--) {
    // dp[i] = dp[j] && dict.contains(s.substring(j, i));
    // if (dp[i]) {
    // break;
    // }
    // }
    // }
    // return dp[len];
    // }
    // }

    /**
     * 回溯法：记忆化递归
     * 避免重复计算，防止超时
     * memo[start]表示：从start开始的子串是否能够完成拆分
     */
    static class Solution {
        public boolean wordBreak(String s, List<String> wordDict) {
            Set<String> dict = new HashSet<>(wordDict);
            Boolean[] memo = new Boolean[s.length() + 1];
            return dfs(s, dict, memo, 0);
        }

        private boolean dfs(String s, Set<String> dict, Boolean[] memo, int start) {
            if (start >= s.length()) {
                return true;
            }
            if (memo[start] != null) {
                return memo[start];
            }
            for (int i = start + 1; i <= s.length(); i++) {
                if (dict.contains(s.substring(start, i)) && dfs(s, dict, memo, i)) {
                    memo[i] = true;
                    return true;
                }
            }
            memo[start] = false;
            return false;
        }
    }

}