/*
78. 子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;

        int n = nums.size();
        int cnt = 1 << n;                       // 幂集的大小 2的n次方，也就是1左移n次
        for (int i = 0; i < cnt; i++){          // 从 全0 到 全1，全0代表全部都不选(空集)，全1代表全部都选(全集)，1010代表选择第1,3个
            vector<int> subset;
            for (int j = 0; j < n; j++){        // 二进制数i共n个bit，用按位与的方式分别检测每一位是否为1
                int temp = 1 << j;              // 使第j个bit为1，其他为0. 如j=2则是 0100 
                if(temp & i){                   // 按位与，若二进制数i的第j个bit为1，则按位与的结果不为0
                    subset.push_back(nums[j]);  // 将第j个元素放入该子集
                }
            }
            results.push_back(subset);
        }
        return results;
        
    }
};