/*
107. 二叉树的层次遍历 II
给定一个二叉树，返回其节点值自底向上的层次遍历。
（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

*/

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> results;
        if (root == nullptr) {
            return results;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> layer;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();q.pop();
                layer.push_back(node->val);
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            results.push_back(layer);
        }
        reverse(results.begin(), results.end());
        return results;
    }
};

int main(){
    TreeNode root(1);
    TreeNode a(2);
    TreeNode b(3);
    TreeNode c(4);
    root.left = &a;
    root.right = &b;
    a.left = &c;

    Solution solution;
    solution.levelOrderBottom(&root);
    
}