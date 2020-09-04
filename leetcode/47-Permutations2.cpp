/*
47. 全排列 II
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
* 排序+剪枝
*/
class Solution {
   public:
    void dfs(vector<vector<int>>& results,vector<int> result, vector<int>& nums,bool marked[], int n, int i) {
        if (i == n) {
            results.emplace_back(result);
            return;
        }
        for (int j = 0; j < n; j++) {
            if(marked[j] || (!marked[j-1] && j > 0 && nums[j] == nums[j-1] )){
                continue;
            }
            marked[j] = true;
            result.push_back(nums[j]);
            dfs(results,result, nums,marked, n, i + 1);
            result.pop_back();
            marked[j] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> result;
        bool marked[nums.size()];
        dfs(results,result, nums,marked, nums.size(), 0);
        return results;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,1,2};
    solution.permuteUnique(nums);
}