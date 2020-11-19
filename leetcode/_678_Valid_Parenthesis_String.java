import java.util.Deque;
import java.util.LinkedList;

/* 
678. 有效的括号字符串
给定一个只包含三种字符的字符串：（ ，） 和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：

任何左括号 ( 必须有相应的右括号 )。
任何右括号 ) 必须有相应的左括号 ( 。
左括号 ( 必须在对应的右括号之前 )。
* 可以被视为单个右括号 ) ，或单个左括号 ( ，或一个空字符串。
一个空字符串也被视为有效字符串。
示例 1:

输入: "()"
输出: True
示例 2:

输入: "(*)"
输出: True
示例 3:

输入: "(*))"
输出: True
注意:

字符串大小将在 [1，100] 范围内。
 */
public class _678_Valid_Parenthesis_String {
    class Solution {
        public boolean checkValidString(String s) {
            Deque<Integer> starStack = new LinkedList<>();
            Deque<Integer> leftStack = new LinkedList<>();

            // 第一阶段
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == '(') {
                    leftStack.push(i);
                } else if (c == ')') {
                    if (!leftStack.isEmpty()) { // 与前面的一个左括号抵消
                        leftStack.pop();
                    } else {                // 遇到一个非法的右括号
                        if (!starStack.isEmpty()) {  // 前面有星号用星号抵消
                            starStack.pop();
                        } else {                // 前面没星号了，返回false
                            return false;
                        }
                    }
                } else {
                    starStack.push(i);
                }
            }

            // 第二阶段
            while (!leftStack.isEmpty()) {
                // 同时出栈，星号必须要在左括号的右侧才可以视作右括号与其抵消
                if (starStack.isEmpty() || leftStack.pop() > starStack.pop()) {
                    return false;
                }
            }

            return true;
        }
    }
}