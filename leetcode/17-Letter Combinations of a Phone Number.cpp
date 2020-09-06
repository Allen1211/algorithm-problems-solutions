/*
17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/


示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*
* 方法1 : 递归回溯 相当于深度优先搜索
*/
// class Solution {
//    public:

//     vector<string> map={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

//     void dfs(vector<string> &results, string result, string digits, int idx) {
//         if (idx == digits.length()) {
//             results.push_back(result);
//             return;
//         }
//         string letters = map[digits.at(idx) - '2'];
//         for(char letter : letters) {
//             dfs(results, result + letter, digits, idx + 1);
//         }
//     }

//     vector<string> letterCombinations(string digits) {
//         vector<string> results;
//         if(digits.length() == 0){
//             return results;
//         }
//         string result;
//         dfs(results, result, digits, 0);
//         return results;
//     }
// };


/*
* 方法2：队列 相当于广度优先搜索
*/
class Solution {
   public:

    vector<string> map={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void bfs(vector<string> &results, string digits) {
        queue<string> q;
        q.push("");
        for(char digit : digits) {
            int size = q.size();
            for(int i = 0; i < size; i++){
                string tmp = q.front(); q.pop();
                string letters = map[digit - '2'];
                for(char letter : letters){
                    q.push(tmp + letter);
                }
            }
        }
        while(!q.empty()){
            results.push_back(q.front());
            q.pop();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if(digits.length() == 0){
            return results;
        }
        bfs(results, digits);
        return results;
    }
};


int main(){
    Solution solution;
    solution.letterCombinations("9");
}