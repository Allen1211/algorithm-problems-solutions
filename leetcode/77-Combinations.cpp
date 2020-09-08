/*
77. 组合
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <vector>
using namespace std;

class Solution {
   public:
    void doCombine(vector<vector<int>> &results, vector<int> &result, int i,
                   int n, int k) {
        if( result.size() + (n - i + 1) < k){   // 剪枝：当剩下的元素都被选中，总数也达不到k个，则可以直接放弃
            return;
        }
        if (result.size() == k) {
            results.push_back(result);
            return;
        }
        for (int j = i; j <= n; j++) {
            result.push_back(j);
            doCombine(results, result, j + 1, n, k);
            result.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > results;
        vector<int> result;
        doCombine(results, result, 1, n, k);

        return results;
    }
};