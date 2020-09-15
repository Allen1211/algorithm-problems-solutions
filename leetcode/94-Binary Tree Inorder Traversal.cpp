/*
94. 二叉树的中序遍历
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        if(!root){
            return result;
        }
        s.push(root);
        TreeNode *p = root;
        while (true) {
            while (p->left) {
                s.push(p->left);
                p = p->left;
            }
            do {
                p = s.top();s.pop();
                result.push_back(p->val);
            } while (p->right == nullptr && !s.empty());
            if (p->right) {
                s.push(p->right);
                p = p->right;
            } else {
                break;
            }
        }

        return result;
    }
};