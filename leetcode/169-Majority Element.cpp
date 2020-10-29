/* 169. 多数元素
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊
n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。



示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2 */

#include <vector>

using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(true){
            int pivot = left;
            int lt = left;
            int i = left + 1;
            int gt = right + 1;
            while (i < gt) {
                if (nums[i] < nums[pivot]) {
                    lt++;
                    swap(nums[lt], nums[i]);
                    i++;
                } else if (nums[i] == nums[pivot]) {
                    i++;
                } else {
                    gt--;
                    swap(nums[gt], nums[i]);
                }
            }
            swap(nums[lt], nums[pivot]);

            if(2 * (gt - lt) >= nums.size()){
                return nums[pivot];
            }else {
                if(2 * lt < nums.size()){
                    left = gt;
                }else {
                    right = lt - 1;
                }
            }
        }
    }
};