/*
46. 全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void dfs(vector<vector<int>>& results, vector<int>& nums, int n, int i) {
        if (i == n) {
            results.emplace_back(nums);
            return;
        }
        for (int j = i; j < n; j++) {
            swap(nums[i], nums[j]);
            dfs(results, nums, n, i + 1);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        dfs(results, nums, nums.size(), 0);
        return results;
    }
};

