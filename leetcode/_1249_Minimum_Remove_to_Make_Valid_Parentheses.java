import java.util.Deque;
import java.util.LinkedList;

/*
1249. 移除无效的括号
给你一个由 '('、')' 和小写字母组成的字符串 s。

你需要从字符串中删除最少数目的 '(' 或者 ')' （可以删除任意位置的括号)，使得剩下的「括号字符串」有效。

请返回任意一个合法字符串。

有效「括号字符串」应当符合以下 任意一条 要求：

空字符串或只包含小写字母的字符串
可以被写作 AB（A 连接 B）的字符串，其中 A 和 B 都是有效「括号字符串」
可以被写作 (A) 的字符串，其中 A 是一个有效的「括号字符串」
 

示例 1：

输入：s = "lee(t(c)o)de)"
输出："lee(t(c)o)de"
解释："lee(t(co)de)" , "lee(t(c)ode)" 也是一个可行答案。
示例 2：

输入：s = "a)b(c)d"
输出："ab(c)d"
示例 3：

输入：s = "))(("
输出：""
解释：空字符串也是有效的
示例 4：

输入：s = "(a(b(c)d)"
输出："a(b(c)d)"
 

提示：

1 <= s.length <= 10^5
s[i] 可能是 '('、')' 或英文小写字母
 */

public class _1249_Minimum_Remove_to_Make_Valid_Parentheses {

    public static void main(String[] args) {
        Solution s = new Solution();
        // System.out.println(s.minRemoveToMakeValid("lee(t(c)o)de)"));
        System.out.println(s.minRemoveToMakeValid("())()((("));

    }

    static class Solution {
        public String minRemoveToMakeValid(String s) {
            Deque<Integer> stack = new LinkedList<>();
            boolean[] invalid = new boolean[s.length()];
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c >= 'a' && c <= 'z') {
                    continue;
                }
                if (c == '(') {
                    stack.push(i);
                } else {
                    if (!stack.isEmpty()) {
                        stack.pop();
                    } else {
                        invalid[i] = true;
                    }
                }
            }
            while (!stack.isEmpty()) {
                invalid[stack.pop()] = true;
            }
            StringBuilder result = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                if (!invalid[i]) {
                    result.append(s.charAt(i));
                }
            }
            return result.toString();
        }
    }

    static class Solution2 {
        public String minRemoveToMakeValid(String s) {
            StringBuilder result = new StringBuilder();

            int stack = 0;
            for (char c : s.toCharArray()) {
                if (c >= 'a' && c <= 'z') {
                    result.append(c);
                    continue;
                }
                if (c == '(') {
                    result.append(c);
                    stack++;
                } else {
                    if (stack != 0) {
                        result.append(c);
                        stack--;
                    }
                }
            }
            if (stack > 0) {
                for (int i = result.length() - 1; i >= 0; i--) {
                    if (result.charAt(i) == '(' && stack > 0) {
                        stack--;
                        result.deleteCharAt(i);
                    }
                }
            }
            return result.toString();
        }
    }

}