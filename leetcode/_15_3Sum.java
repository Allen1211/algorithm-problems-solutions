public class _15_3Sum {
    class Solution {
        public List<List<Integer>> threeSum(int[] nums) {
            int len = nums.length;
            Arrays.sort(nums);
            List<List<Integer>> res = new ArrayList<>();
            for (int k = 0; k < len; k++) {
                if(nums[k] > 0) {
                    break;
                }
                if (k == 0 || nums[k] != nums[k - 1]) {
                    for (int i = k + 1, j = len - 1; i < j; ) {
                        if (nums[i] + nums[j] == -nums[k]) {
                            res.add(Arrays.asList(nums[k], nums[i], nums[j]));
                            while (++i < len && nums[i] == nums[i - 1]);
                            while (--j > i && nums[j] == nums[j + 1]);
                        } else if(nums[i] + nums[j] < -nums[k]){
                            while (++i < len && nums[i] == nums[i - 1]);
                        } else {
                            while (--j > i && nums[j] == nums[j + 1]);
                        }
                    }
                }
            }
            return res;
        }
    
    }
}