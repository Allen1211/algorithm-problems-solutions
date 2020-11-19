
/* 32. 最长有效括号
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
 */
public class _32_Longest_Valid_Parentheses {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.longestValidParentheses("(()"));
        System.out.println(s.longestValidParentheses("()(()"));
        System.out.println(s.longestValidParentheses("))))((()(("));
        System.out.println(s.longestValidParentheses("()))(()(()))("));
    }

    static class Solution {

        public int longestValidParentheses(String s) {
            StringBuilder s2 = new StringBuilder(s).reverse();
            for (int i = 0; i < s2.length(); i++) {
                s2.setCharAt(i, (char) (s2.charAt(i) ^ 1));
            }
            return Math.max(solve(s), solve(s2.toString()));
        }

        private int solve(String s) {
            if (s.length() == 0) {
                return 0;
            }
            int res = 0, stack = 0;
            for (int i = 0, j = 0; j < s.length() && i < s.length(); i++) {
                stack += s.charAt(i) == '(' ? 1 : -1;
                if (stack == 0) {
                    res = Math.max(res, i - j + 1);
                } else if (stack < 0) {
                    j = i + 1;
                    stack = 0;
                }
            }

            return res;
        }
    }
}