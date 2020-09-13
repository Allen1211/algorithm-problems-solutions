/*
80. 删除排序数组中的重复项 II
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1)
额外空间的条件下完成。

示例 1:

给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3
。

你不需要考虑数组中超出新长度后面的元素。
说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) {
            return size;
        }
        int i = 0, j = 1, cnt = 1;
        while (++i < size) {
            cnt = (nums[i] == nums[i - 1]) ? cnt + 1 : 1;
            if (cnt <= 2) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};

void print(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    vector<int> nums3 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums4 = {0,0,1,1,1,1,2,3,3};
    vector<int> nums5 = {1,1,1,2,2,3};
    vector<int> nums6 = {1, 1, 1, 1};

    Solution s;

    cout << s.removeDuplicates(nums1) << endl;
    print(nums1);
    cout << s.removeDuplicates(nums2) << endl;
    print(nums2);
    cout << s.removeDuplicates(nums3) << endl;
    print(nums3);
    cout << s.removeDuplicates(nums4) << endl;
    print(nums4);
    cout << s.removeDuplicates(nums5) << endl;
    print(nums5);
    cout << s.removeDuplicates(nums6) << endl;
    print(nums6);
}