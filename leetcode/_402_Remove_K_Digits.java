import java.util.ArrayDeque;
import java.util.Deque;

/*
 * @lc app=leetcode.cn id=402 lang=java
 *
 * [402] 移掉K位数字
 */

// @lc code=start

public class _402_Remove_K_Digits {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.removeKdigits("1542323", 3));
        System.out.println(s.removeKdigits("1542323", 4));
        System.out.println(s.removeKdigits("1542323", 5));
        System.out.println(s.removeKdigits("12229", 1));
        System.out.println(s.removeKdigits("12229", 3));

    }

    static class Solution {
        public String removeKdigits(String num, int k) {
            Deque<Character> stack = new ArrayDeque<>();

            char[] carr = num.toCharArray();
            for (int i = 0; i < carr.length; i++) {
                while (k > 0 && !stack.isEmpty() && stack.getFirst() > carr[i]) {
                    stack.pop();
                    k--;
                }
                stack.push(carr[i]);
            }

            while (k-- > 0) {
                stack.pop();
            }

            StringBuilder result = new StringBuilder();
            boolean isFrontZero = true;
            while (!stack.isEmpty()) {
                char ch = stack.pollLast();
                if (isFrontZero && ch == '0') {
                    continue;
                } else {
                    isFrontZero = false;
                }
                result.append(ch);
            }

            return result.length() == 0 ? "0" : result.toString();
        }
    }
    
    // static class Solution {
    // class MyPair {
    // final char ch;
    // final int idx;

    // public MyPair(char ch, int idx) {
    // this.ch = ch;
    // this.idx = idx;
    // }
    // }
    // public String removeKdigits(String num, int k) {
    // Deque<MyPair> stack = new ArrayDeque<>();
    // boolean[] flag = new boolean[num.length()];

    // int cnt = 0;
    // char[] carr = num.toCharArray();
    // for (int i = 0; i < carr.length && cnt < k; i++) {
    // while (!stack.isEmpty() && stack.getFirst().ch > carr[i]) {
    // int idx = stack.pop().idx;
    // flag[idx] = true;
    // cnt++;
    // if (cnt >= k) {
    // break;
    // }
    // }
    // stack.push(new MyPair(carr[i], i));
    // }

    // while (cnt < k) {
    // int idx = stack.pop().idx;
    // flag[idx] = true;
    // cnt++;
    // }

    // // 最后输出新的字符串，去掉前导零
    // StringBuilder result = new StringBuilder();
    // int i = 0;
    // while (i < carr.length && (flag[i] || carr[i] == '0')) {
    // i++;
    // }
    // while (i < carr.length) {
    // if (!flag[i]) {
    // result.append(carr[i]);
    // }
    // i++;
    // }

    // return result.length() == 0 ? "0" : result.toString();
    // }
    // }
}

// @lc code=end
