/*
257. 二叉树的所有路径
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(vector<string> &paths, string path, TreeNode *p) {
    path += to_string(p->val);
    if (!p->left && !p->right) {
        paths.push_back(path);
        return;
    }
    if (p->left) dfs(stack,path + "->", p->left);
    if (p->right) dfs(stack, path + "->", p->right);
}

vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> paths;
    if(root){
        string path;
        dfs(paths, path, root);
    }
    return paths;
}