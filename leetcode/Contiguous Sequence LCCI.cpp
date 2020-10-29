/* 面试题 16.17. 连续数列
给定一个整数数组，找出总和最大的连续数列，并返回总和。

示例：

输入： [-2,1,-3,4,-1,2,1,-5,4]
输出： 6
解释： 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶：

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

 */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i-1] >= 0){
                 nums[i] += nums[i-1];
            }
            sum = max(sum, nums[i]);
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums2 = {1, 2, 3, 4, 5};
    vector<int> nums3 = {1};
    vector<int> nums4 = {-1};
    vector<int> nums5 = {0, 2, 0, 2};
    vector<int> nums6 = {-1, -2};

    cout << s.maxSubArray(nums1) << endl;
    cout << s.maxSubArray(nums2) << endl;
    cout << s.maxSubArray(nums3) << endl;
    cout << s.maxSubArray(nums4) << endl;
    cout << s.maxSubArray(nums5) << endl;
    cout << s.maxSubArray(nums6) << endl;

    return 0;
}