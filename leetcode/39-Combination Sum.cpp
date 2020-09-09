/*
39. 组合总和
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates
中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]


提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500
*/
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
   public:
   /*
    *  递归回溯方式1 
    */
    // void dfs(vector<vector<int>> &results, vector<int> &result,
    //          vector<int> &candidates, int i, int target) {
    //     if (target == 0) {
    //         results.push_back(result);
    //         return;
    //     }

    //     for (int j = i; j < candidates.size(); j++) {
    //         int val = candidates[j];
    //         if (target - val < 0) {
    //             break;
    //         }

    //         result.push_back(val);
    //         dfs(results, result, candidates, j, target - val);
    //         result.pop_back();
    //     }
    // }
   /*
    *  递归回溯方式2 
    */
    void dfs(vector<vector<int>> &results, vector<int> &result,
             vector<int> &candidates, int i, int target) {
        if(target == 0){
            results.push_back(result);
            return;
        }
        // 不选择本元素 （若后面还有）
        if(i + 1 < candidates.size()){
            dfs(results, result, candidates, i + 1, target);       
        }
        // 选择本元素，重复一次或多次  (若选择该数后不会使target变为负数)
        int val = candidates[i];
        if(target - val >= 0){
            result.push_back(val);
            dfs(results, result, candidates, i, target - val);
            result.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> results;
        vector<int> result;
        sort(candidates.begin(), candidates.end());
        dfs(results, result, candidates, 0, target);
        return results;
    }
};