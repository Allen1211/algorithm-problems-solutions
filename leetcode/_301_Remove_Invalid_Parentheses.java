import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class _301_Remove_Invalid_Parentheses {

    public static void main(String[] args) {
        Solution s = new Solution();
        // System.out.println(s.removeInvalidParentheses("()())()"));
        // System.out.println(s.removeInvalidParentheses("(a)())()"));
        // System.out.println(s.removeInvalidParentheses(")("));
        System.out.println(s.removeInvalidParentheses(")(f"));
    }

    static class Solution {
        
        public List<String> removeInvalidParentheses(String s) {
            int left = 0, right = 0;
            for (char c : s.toCharArray()) {
                if (c == '(') {
                    left++;
                } else if(c == ')') {
                    if (left == 0) {
                        right++;
                    } else {
                        left--;
                    }
                }
            }
            Set<String> res = new HashSet<>();
            dfs(res, s, "", 0, 0, left, right);
            return new ArrayList<String>(res);
        }

        private void dfs(Set<String> res, String s, String result, int i, int stack, int left, int right) {
            if (i == s.length()) {
                if (stack == 0) {
                    res.add(result);
                }
                return;
            }
            if (s.charAt(i) == '(') {
                dfs(res, s, result + "(", i + 1, stack + 1, left, right);
                if (left > 0) {
                    dfs(res, s, result, i + 1, stack, left - 1, right);
                }
            } else if (s.charAt(i) == ')') {
                if (stack > 0) {
                    dfs(res, s, result + ")", i + 1, stack - 1, left, right);
                }
                if (right > 0) {
                    dfs(res, s, result, i + 1, stack, left, right - 1);
                }
            } else {
                dfs(res, s, result + s.charAt(i), i + 1, stack, left, right);
            }
        }
    }
}