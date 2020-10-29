/* 145. 二叉树的后序遍历
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？ */

#include <stack>
#include <vector>

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
class Solution {
   public:
    struct Node {
        TreeNode *tree;
        bool flag;
        Node(TreeNode *tree) : tree(tree), flag(false) {}
    };

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if(!root) return result;
        stack<Node *> s;
        auto p = root;
        do {
            while (p) {
                s.push(new Node(p));
                p = p->left;
            }
            auto node = s.top();
            if (!node->flag) {
                node->flag = true;
                p = node->tree->right;
            } else {
                s.pop();
                result.push_back(node->tree->val);
            }
        } while (!s.empty());

        return result;
    }
};

int main() {
    Solution s;

    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);

    n1.right = &n2;
    n2.left = &n3;

    s.postorderTraversal(&n1);
}