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

/*
 * 迭代算法，中序遍历 时间复杂度 O(n) 空间复杂度 O(n)
 */
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> s;
        if (!root) {
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
                p = s.top();
                s.pop();
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

/*
 * Mirrors中序遍历，把空间复杂度优化到O(1)
 * 原理：
 * 前驱结点：指根节点的左子树最右下的那一个叶子结点
 * 在中序遍历序列中，当root结点的前驱结点被遍历到，下一个被遍历到的一定是root结点。
 * 从前驱结点 "回溯到" root结点，一般要借助递归调用栈一层一层地回溯来实现，这需要O(n)的空间
 * 由于前驱结点一定是叶子结点，可以在第一次遍历到根节点时，把它的前驱结点的右孩子连接到它自己
 * 这样遍历完前驱结点后立即可以通过指针回到root结点，而不需要借助递归调用栈
 */
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *predecessor = nullptr;

        while (root) {
            if (root->left) {
                // 找到当前节点的前驱 （左子树一直往右走到底）
                predecessor = root->left;
                while (predecessor->right && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                // 找到了未访问过的前驱结点，将其右孩子指向root
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                } else {
                    // 前驱结点右孩子不为空，说明该前驱结点已经访问过了，也就是当前结点的左子树已经遍历完了，记录当前结点并断开连接
                    result.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            } else {
                result.push_back(root->val);
                root = root->right;
            }
        }

        return result;
    }
};