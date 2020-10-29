
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        /*
         * 循环不变量
         * all in [0, zero) == 0
         * all in [zero, i) == 1
         * all in [two, size) == 2
         */
        int zero = 0;
        int i = 0;
        int two = nums.size();;
        while(i < two){
            if(nums[i] == 0){
                swap(nums[zero], nums[i]);
                ++zero;
                ++i;
            }else if(nums[i] == 1){
                ++i;
            }else {
                --two;
                swap(nums[two], nums[i]);
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,1,2,1,2};
    s.sortColors(nums);
    nums = {1, 2, 2, 2, 2, 0, 0, 0, 1, 1};
    s.sortColors(nums);
}