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
https://leetcode-cn.com/problems/3sum/solution/san-shu-zhi-he-cshi-xian-shuang-zhi-zhen-fa-tu-shi/
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> resultList;
    int size = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size - 2; i++){
        int now = i;
        if(nums[now] > 0){
            break;
        }
        if(now > 0 && nums[now] == nums[now-1]){
            continue;
        }
        int left = now + 1;
        int right = size - 1;
        while (left < right){
            
            int x = nums[now];
            int y = nums[left];
            int z = nums[right];

            if(y + z > -x){
                right--;
            }else if(y + z < -x){
                left++;
            }else {
                vector<int> result = {x,y,z};
                resultList.push_back(result);
                // 去重
                while(left < right && nums[left] == y){
                    left++;
                }
                while(left < right && nums[right] == z){
                    right--;
                }
            }

        }
        
    }
    return resultList;
}

void print(vector<vector<int>> list){
    cout << "--------" << endl;;
    for(vector<int> v : list){
        for(int num : v){
            cout << num << " ";
        }    
        cout << endl;
    }
}

int main(){
    vector<int> t1 = {-1, 0, 1, 2, -1, -4};
    vector<int> t2 = {1,2,3,4,5};    
    vector<int> t3 = {0,0, 0,0};  
    print(threeSum(t1));
    print(threeSum(t2));
    print(threeSum(t3));
}