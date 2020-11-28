import java.util.HashSet;
import java.util.Set;

public class _653_Two_Sum_IV_Input_is_a_BST {
    private class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    class Solution {
        private Set<Integer> set = new HashSet<>();

        public boolean findTarget(TreeNode root, int k) {
            if (root == null) {
                return false;
            }
            if (findTarget(root.left, k) || findTarget(root.right, k)) {
                return true;
            }
            if (set.contains(k - root.val)) {
                return true;
            }
            set.add(root.val);
            return false;
        }
    }
}