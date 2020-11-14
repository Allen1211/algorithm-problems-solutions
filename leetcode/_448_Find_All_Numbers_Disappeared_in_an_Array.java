import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=448 lang=java
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start

public class _448_Find_All_Numbers_Disappeared_in_an_Array{ 
    class Solution {
        public List<Integer> findDisappearedNumbers(int[] nums) {
            for (int i = 0; i < nums.length; i++) {
                while (nums[i] != i + 1) {
                    if (nums[nums[i] - 1] != nums[i]) {
                        swap(nums, i, nums[i] - 1);
                    } else {
                        break;
                    }
                }
            }
    
            List<Integer> result = new ArrayList<>();
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != i + 1) {
                    result.add(i + 1);
                }
            }
    
            return result;
        }
    
        private void swap(int[] nums, int i, int j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}

// @lc code=end
