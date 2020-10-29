/* 129. 求根到叶子节点数字之和
给定一个二叉树，它的每个结点都存放一个 0-9
的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。

示例 1:

输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.
示例 2:

输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026. */

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    void helper(TreeNode *t, int sum, int &result) {
        sum = sum * 10 + t->val;
        if(t->left == nullptr && t->right == nullptr){
            result += sum;
            return;
        }
        if(t->left != nullptr){
            helper(t->left, sum, result);
        }
        if(t->right != nullptr){
            helper(t->right, sum, result);
        }
    }

    int sumNumbers(TreeNode *root) {
        int result = 0;
        if(root != nullptr){
            helper(root, 0, result);
        }
        return result;
    }
};