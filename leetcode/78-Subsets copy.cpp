/*
90. 子集 II
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &results, vector<int>& result, vector<int> &nums, int i, int n){
        results.push_back(result);
        for (int j = i; j < n; j++){
            if(j == i || nums[j] != nums[j - 1]){
                result.push_back(nums[j]);
                dfs(results, result, nums, j + 1, n);
                result.pop_back();
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        sort(nums.begin(), nums.end());
        dfs(results, result, nums, 0, nums.size());
        return results;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,2};
    s.subsetsWithDup(nums);
    return 0;
}