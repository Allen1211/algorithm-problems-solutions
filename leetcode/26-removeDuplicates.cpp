/*
26. 删除排序数组中的重复项
给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

 

示例 1:

给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。
*/

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    if(size <= 1){
        return size;
    }
    int i=1, j=0;
    while(i < size){
        if(nums[i] != nums[j]){
            nums[++j] = nums[i];
        }
        i++;
    }
    return j+1;
}

void print(vector<int> nums){
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    vector<int> nums3 = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums4 = {1,1,2};
    vector<int> nums5 = {1,2,3,5};
    vector<int> nums6 = {1,1,1,1};

    cout << removeDuplicates(nums1) << endl;
    print(nums1);
    cout << removeDuplicates(nums2) << endl;
    print(nums2);
    cout << removeDuplicates(nums3) << endl;
    print(nums3);
    cout << removeDuplicates(nums4) << endl;
    print(nums4);
    cout << removeDuplicates(nums5) << endl;
    print(nums5);
    cout << removeDuplicates(nums6) << endl;
    print(nums6);

}