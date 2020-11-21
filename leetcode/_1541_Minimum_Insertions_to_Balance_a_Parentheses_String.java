public class _1541_Minimum_Insertions_to_Balance_a_Parentheses_String {

    class Solution {
        public int minInsertions(String s) {
            int res = 0, left = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '(') {
                    left++;
                } else {
                    if (i + 1 < s.length() && s.charAt(i + 1) == ')') {
                        i++;
                    } else {
                        res++;
                    }
                    if (left > 0) {
                        left--;
                    } else {
                        res++;
                    }
                }
            }
            return res + left * 2;
        }
    }
}