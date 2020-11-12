/*
 * @lc app=leetcode.cn id=125 lang=java
 *
 * [125] 验证回文串
 */

// @lc code=start

public class _125_Valid_Palindrome {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isPalindrome("aba"));
        System.out.println(s.isPalindrome("a   b  "));
        System.out.println(s.isPalindrome("a   a  "));
        System.out.println(s.isPalindrome("   a    "));
        System.out.println(s.isPalindrome(""));

    }

    static class Solution {
        public boolean isPalindrome(String s) {
            char[] arr = s.toCharArray();
            int i = 0, j = arr.length - 1;
            while(i < j) {
                while(i < arr.length && !isValid(arr[i])) {
                    i++;
                }
                while(j >= 0 && !isValid(arr[j])) {
                    j--;
                }
                if(i > j) {
                    return true;
                }
                if(!isEquals(arr[i], arr[j])) {
                    return false;
                }
                i++;
                j--;
            }
            return true;

        }

        private boolean isValid(char ch) {
            return Character.isDigit(ch) || Character.isLetter(ch);
        }

        private boolean isEquals(char x, char y) {
            if (Character.isLetter(x) && Character.isLetter(y)) {
                return Character.toLowerCase(x) == Character.toLowerCase(y);
            } else {
                return x == y;
            }
        }
    }
}

// @lc code=end
