/* 113. 路径总和 II
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
] */

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
    vector<int> path;
    vector<vector<int>> results;
    int target;

    void dfs(TreeNode *root, int& currSum) {
        path.push_back(root->val);
        currSum += root->val;
        if (target == currSum && !root->left && !root->right) {
            results.push_back(path);
        } else {
            if (root->left) dfs(root->left, currSum);
            if (root->right)  dfs(root->right, currSum);
        }
        currSum -= root->val;
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        if (root) {
            target = sum;
            int currSum = 0;
            dfs(root, currSum);
        }
        return results;
    }
};