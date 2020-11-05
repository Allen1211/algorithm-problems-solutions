/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    void helper(vector<string>& result, string str, int& n, int left,
                int right) {
        if(left - right > 0){
            if(left  < n) {
                helper(result, str + '(', n, left + 1, right);
            }
            helper(result, str + ')', n, left, right + 1);
        }else {
            if(right < n){
                helper(result, str + '(', n, left + 1, right);
            }else {
                result.emplace_back(str);
                return;
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        if (n <= 0) {
            return {""};
        }
        string str = "(";
        vector<string> result;

        helper(result, str, n, 1, 0);

        return result;
    }
};
// @lc code=end


int main(){
    Solution s;
    s.generateParenthesis(3);
    return 0;
}