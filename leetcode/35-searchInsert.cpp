/*
35. 搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0
*/

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int size = nums.size();
    if(size == 0 || target <= nums[0]){
        return 0;
    }else if(target > nums[size - 1]){
        return size;
    }
    int left = 0;
    int right = size -1;
    int mid;
    while(left < right){
        mid = (left + right) / 2;
        if(target < nums[mid]){
            right = mid;
        }else if(target > nums[mid]){
            left = mid + 1;
        }else {
            return mid;
        }
    }
    return nums[left] >= target ? left : left + 1;
}

