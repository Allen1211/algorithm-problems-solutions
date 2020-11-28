import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class nSum {
    class Solution {
        public List<List<Integer>> nSum(int[] nums,int n, int target) {
            Arrays.sort(nums);
            return solveNSum(nums, 0, n, target);
        }

        /**
         * 对 nums[begin:] 求n个数之和等于target，返回所有符合要求的元组
         */
        private List<List<Integer>> solveNSum(int[] nums, int begin, int n, int target) {
            List<List<Integer>> res = new ArrayList<>();
            // 递归终止条件：当n==2时，使用两数之和的算法解决
            if (n == 2) {
                int len = nums.length;
                for (int i = begin, j = len - 1 ; i < j;) {
                    if (nums[i] + nums[j] == target) {
                        res.add(new ArrayList<>(Arrays.asList(nums[i], nums[j])));
                        while(++i < len && nums[i] == nums[i - 1]);
                        while(--j > i && nums[j] == nums[j + 1]);
                    } else if (nums[i] + nums[j] < target) {
                        while(++i < len && nums[i] == nums[i - 1]);
                    } else {
                        while(--j > i && nums[j] == nums[j + 1]);
                    }
                }
                return res;
            }
            // 将问题减小为 n - 1数之和，递归解决
            for (int i = begin; i < nums.length; i++) {
                if (i > begin && nums[i] == nums[i-1]) {
                    continue;
                }
                List<List<Integer>> subRes = solveNSum(nums, i + 1, n - 1, target - nums[i]);
                for (List<Integer> tuple : subRes) {
                    tuple.add(nums[i]);
                }
                res.addAll(subRes);
            }
            return res;
        }
    }
}