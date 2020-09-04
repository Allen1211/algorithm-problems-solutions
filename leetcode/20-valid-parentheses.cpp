/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s){
    if(s.length() <= 1){
        return false;
    }
    stack<char> stack;
    for(int i=0;i < s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            stack.push(s[i]);
        }else {
            if(stack.empty()){
                return false;
            }
            char top = stack.top();
            if((ch == ')' && top != '(') ||
               (ch == '}' && top != '{') ||
               (ch == ']' && top != '[') ){
                   return false;
            } 
            stack.pop();
        }
    }
    return stack.size() == 0;
}

int main(){
    cout << isValid("") << endl;
    cout << isValid("){") << endl;
    cout << isValid("((") << endl;
    cout << isValid("(") << endl;
    cout << isValid("()") << endl;
    cout << isValid("()[]{}") << endl;
    cout << isValid("(]") << endl;
    cout << isValid("([)]") << endl;
    cout << isValid("{[]}") << endl;
}
