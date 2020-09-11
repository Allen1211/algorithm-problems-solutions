/*
* 剑指 Offer 28. 对称的二叉树
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3



示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false


限制：

0 <= 节点个数 <= 1000
*/

#include <math.h>

#include <iostream>
#include <queue>
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
*  
class Solution {
   public:
    void leftTraversal(vector<int> &path, TreeNode *t) {
        if (!t) {
            path.push_back(-1);
            return;
        }
        path.push_back(t->val);
        leftTraversal(path, t->left);
        leftTraversal(path, t->right);
    }

    void rightTraversal(vector<int> &path, TreeNode *t) {
        if (!t) {
            path.push_back(-1);
            return;
        }
        path.push_back(t->val);
        rightTraversal(path, t->right);
        rightTraversal(path, t->left);
    }

    bool isSymmetric(TreeNode *root) {
        if(!root){
            return true;
        }
        vector<int> leftPath;
        vector<int> rightPath;
        leftTraversal(leftPath, root->left);
        rightTraversal(rightPath, root->right);

        if (leftPath.size() != rightPath.size()) {
            return false;
        }

        for (int i = 0; i < leftPath.size(); i++) {
            if (leftPath[i] != rightPath[i]) {
                return false;
            }
        }

        return true;
    }
};
*/

class Solution {
   public:
    bool traversal(TreeNode *left, TreeNode *right) {
        if (!left && !right)
            return true;
        else if (!left || !right || left->val != right->val)
            return false;
        else
            return traversal(left->left, right->right) &&
                   traversal(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        return traversal(root->left, root->right);
    }
};

int main() {
    Solution s;
    TreeNode root(1);
    TreeNode t1(2);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(4);
    TreeNode t6(3);

    root.left = &t1;
    root.right = &t2;

    t1.left = &t3;
    t1.left = &t4;

    t2.left = &t5;
    t2.right = &t6;

    cout << s.isSymmetric(&root);

    return 0;
}