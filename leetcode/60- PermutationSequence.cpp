/*
60. 第k个排列
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213"
示例 2:

输入: n = 4, k = 9
输出: "2314"

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> factorial;

    void fillFactorial(int n) {
        factorial.resize(n);
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
    }

   public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        fillFactorial(n);
        string result = "";
        int idx;
        while (n >= 1) {
            idx = (k - 1) / factorial[n - 1];
            k = (k - 1) % factorial[n - 1] + 1;
            
            result += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);

            n--;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.getPermutation(3, 4) << endl;
    cout << solution.getPermutation(3, 2) << endl;
    cout << solution.getPermutation(3, 1) << endl;
    cout << solution.getPermutation(4, 9) << endl;
    cout << solution.getPermutation(1, 1) << endl;
}