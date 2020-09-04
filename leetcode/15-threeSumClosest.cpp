/*
15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* 双指针法 去重
*/

int threeSumClosest(vector<int>& nums, int target) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    int sum = INT_MIN;
    for (int i = 0; i < size - 2; i++){
        int now = i;
        int left = now + 1;
        int right = size - 1;
        while (left < right){
            int temp = nums[now] + nums[left] + nums[right];
            if(sum == INT_MIN || abs(temp - target) < abs(sum - target)){
                sum = temp;
            }
            if(temp < target){
                left++;
                while(left < right && nums[left] == nums[left-1]){
                    left++;
                }
            }else if(temp > target){
                right--;
                while(left < right && nums[right] == nums[right+1]){
                    right--;
                }
            }else {
                break;
            }
        }
    }
    return sum;
}


int main(){
    vector<int> t1 = {1,1,3,4,4,6};
    vector<int> t2 = {-1,2,1,-4};    
    vector<int> t3 = {-1,2,1,-4,9};  
    vector<int> t4 = {1,2,4,8,16,32,64,128};  
    vector<int> t5 = {-55,-24,-18,-11,-7,-3,4,5,6,9,11,23,33};  
    cout << threeSumClosest(t1, 7) << endl;
    cout << threeSumClosest(t2, 1) << endl;
    cout << threeSumClosest(t3, -2) << endl;
    cout << threeSumClosest(t4, 82) << endl;
    cout << threeSumClosest(t5, 0) << endl;
}