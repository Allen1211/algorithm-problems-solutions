/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start

#include <algorithm>
#include <string>

using namespace std;

class Solution {
   public:
    string addBinary(string a, string b) {
        string res;

        // 先在较短的字符串前面补足0，使得两个字符串对齐
        if (a.length() < b.length()) {
            string padding(b.length() - a.length(), '0');
            a = padding + a;
        } else if (a.length() > b.length()) {
            string padding(a.length() - b.length(), '0');
            b = padding + b;
        }

        // 模拟全加器
        int s = 0, c = 0;
        for (int i = a.length() - 1; i >= 0; i--) {
            int x = a[i] - '0', y = b[i] - '0';
            s = x ^ y ^ c;
            c = (x & y) | (c & (x ^ y));
            res.push_back(s + '0');
        }
        if (c == 1) {
            res.push_back('1');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
