/*
34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值
target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int size = nums.size();
        if(size == 0){
            return result;
        }
        int left = 0, right = size - 1;
        if (nums[left] == target) result[0] = left;
        if (nums[right] == target) result[1] = right;
        while (left < right && (result[0] == -1 || result[1] == -1)) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                if (result[0] == left) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            if (result[0] == -1 && left >= 0 && left < size && nums[left] == target) {
                while (left > 0 && nums[left - 1] == target) left--;
                result[0] = left;
            }
            if (result[1] == -1 && right >= 0 && right < size && nums[right] == target) {
                while (right < size - 1 && nums[right + 1] == target) right++;
                result[1] = right;
            }
        }
        return result;
    }
};

void print(vector<int> v) { cout << v[0] << "," << v[1] << endl; }

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2, 3, 3, 4};
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    vector<int> nums2 = {5, 7, 7, 8, 8, 10};
    vector<int> nums3 = {5, 8, 8, 8, 10};
    vector<int> nums4 = {8, 8, 8, 8, 8};
    vector<int> nums5 = {8, 9, 10, 11, 12};
    vector<int> nums6 = {2, 2};
    vector<int> nums7 = {2};
    vector<int> nums8 = {1,3};
    print(solution.searchRange(nums, 3));
    print(solution.searchRange(nums1, 8));
    print(solution.searchRange(nums2, 6));
    print(solution.searchRange(nums3, 8));
    print(solution.searchRange(nums4, 8));
    print(solution.searchRange(nums5, 9));
    print(solution.searchRange(nums6, 1));
    print(solution.searchRange(nums6, 3));
    print(solution.searchRange(nums6, 2));
    print(solution.searchRange(nums7, 3));
    print(solution.searchRange(nums7, 1));
    print(solution.searchRange(nums7, 2));
    print(solution.searchRange(nums8, 1));

    return 0;
}
