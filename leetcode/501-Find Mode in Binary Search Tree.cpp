/* 501. 二叉搜索树中的众数
给定一个有相同值的二叉搜索树（BST），找出 BST
中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
*/

#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 利用二叉搜索树的性质：中序遍历序列是递增的结点序列，也就是说重复的结点一定是相邻的，这样可以避免哈希表计数和排序
 * 不使用额外空间：使用Mirrors中序遍历的方式
 */
class Solution {
   public:
    vector<int> result;
    int maxCount = 0;
    int count = 0;
    int num = INT_MIN;

    void update(int nowNum) {
        if (nowNum == num) {
            count++;
        } else {
            num = nowNum;
            count = 1;
        }
        if (count == maxCount) {
            result.push_back(num);
        } else if (count > maxCount) {
            result.clear();
            result.push_back(num);
            maxCount = count;
        }
    }

    vector<int> findMode(TreeNode *root) {
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
                    update(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            } else {
                update(root->val);
                root = root->right;
            }
        }
        return result;
    }
};