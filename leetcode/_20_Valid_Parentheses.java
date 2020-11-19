import java.util.Deque;
import java.util.LinkedList;

public class _20_Valid_Parentheses {

    class Solution {
        public boolean isValid(String s) {
            if (s == "")
                return true;
            Deque<Character> stack = new LinkedList<>();
            for (char c : s.toCharArray()) {
                if (c == '(' || c == '{' || c == '[') {
                    stack.push(c);
                } else {
                    if (stack.isEmpty()) {
                        return false;
                    }
                    char last = stack.pop();
                    if ((last != '(' && c == ')') || (last != '{' && c == '}') || (last != '[' && c == ']')) {
                        return false;
                    }
                }
            }

            return stack.isEmpty();
        }
    }
}