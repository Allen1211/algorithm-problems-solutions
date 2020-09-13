/*
637. 二叉树的层平均值
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。



示例 1：

输入：
    3
   / \
  9  20
    /  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。


提示：

节点值的范围在32位有符号整数范围内。

*/

#include <queue>
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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> results;
        if(!root) return results;
        queue<TreeNode *> q;
        int cnt = 0;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto t = q.front();q.pop();
                if (i == 0) {
                    results.push_back(t->val);
                } else {
                    results[cnt] += t->val;
                }
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            results[cnt++] /= size;
        }
        return results;
    }
};