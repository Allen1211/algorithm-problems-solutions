/* 144. 二叉树的前序遍历
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。 */

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

/*
 * 迭代法
 */
class Solution {
   public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (p || !s.empty()) {
            while (p) {
                result.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            p = p->right;
        }
        return result;
    }
};

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *pre = nullptr;
        TreeNode *curr = root;
        while (curr) {
            if (curr->left) {
                // 找到当前节点的前驱 （左子树一直往右走到底）
                pre = curr->left;
                while (pre->right && pre->right != curr) {
                    pre = pre->right;
                }
                // 找到了未访问过的前驱结点，将其右孩子指向curr
                if (pre->right == nullptr) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    // 前驱结点右孩子不为空，说明该前驱结点已经访问过了，也就是当前结点的左子树已经遍历完了，记录当前结点并复原结构
                    result.push_back(curr->val);
                    pre->right = nullptr;
                    curr = curr->right;
                }
            } else {
                result.push_back(curr->val);
                curr = curr->right;
            }
        }

        return result;
    }
};