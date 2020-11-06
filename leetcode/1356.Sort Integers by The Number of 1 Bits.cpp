/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
    static int numOf1Bits(int x) {
        unsigned int ux = x;
        int cnt_x = 0;
        while (ux != 0) {
            cnt_x += ux & 1;
            ux = ux >> 1;
        }
        return cnt_x;
    }

    static bool comp(const int& x, const int& y) {
        int nx = numOf1Bits(x);
        int ny = numOf1Bits(y);
        return nx == ny ? x <= y : nx < ny;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};
// @lc code=end
