public class _18_4Sum {
    class Solution {
        public List<List<Integer>> fourSum(int[] nums, int target) {
            List<List<Integer>> res = new ArrayList<>();
            int len = nums.length;
            Arrays.sort(nums);
    
            for (int a = 0; a < len; a++) {
                if (a > 0 && nums[a] == nums[a - 1]) {
                    continue;
                }
                List<List<Integer>> threeSumRes = threeSum(nums, a + 1, target - nums[a]);
                for(List<Integer> tuple : threeSumRes) {
                    tuple.add(nums[a]);
                }
                res.addAll(threeSumRes);
            }
    
            return res;
        }
        
        private List<List<Integer>> threeSum(int[] nums, int begin, int target) {
            int len = nums.length;
            List<List<Integer>> res = new ArrayList<>();
            for (int k = begin; k < len; k++) {
                if (k > begin && nums[k] == nums[k - 1]) {
                    continue;
                }
                for (int i = k + 1, j = len - 1; i < j; ) {
                    int sum = nums[k] + nums[i] + nums[j];
                    if (sum == target) {
                        res.add(new ArrayList<>(Arrays.asList(nums[k], nums[i], nums[j])));
                        while (++i < len && nums[i] == nums[i - 1]);
                        while (--j > i && nums[j] == nums[j + 1]);
                    } else if(sum < target){
                        while (++i < len && nums[i] == nums[i - 1]);
                    } else {
                        while (--j > i && nums[j] == nums[j + 1]);
                    }
                }
            }
            return res;
        }
    }
}