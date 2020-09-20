/* 404. 左叶子之和
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24 */


#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    
    void dfs(TreeNode* root,int &sum, bool isLeft){
        if(root->left){
            dfs(root->left, sum, true);
        }
        if(root->right){
            dfs(root->right, sum, false);
        }
        if(!root->left && !root->right && isLeft){
            sum += root->val;
        }
    }

    int sumOfLeftLeaves(TreeNode *root) {
        if(!root){
            return 0;
        }
        int sum = 0;
        dfs(root, sum, false);
        return sum;
    }
};