/*
226. 翻转二叉树
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
备注:
这个问题是受到 Max Howell 的 原问题 启发的 ：

谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
*/

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// class Solution {
//    public:
//     void dfs(TreeNode* &t1, TreeNode* &t2){
//         t2 = new TreeNode(t1->val);
//         if(t1->left){
//             dfs(t1->left, t2->right);
//         }
//         if(t1->right){
//             dfs(t1->right, t2->left);
//         }
//     }
//     TreeNode* invertTree(TreeNode* root) {
//         if(!root){
//             return nullptr;
//         }
//         TreeNode* tree;
//         dfs(root, tree);
//         return tree;
//     }
// };

class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        invertTree(root->left);
        invertTree(root->right);
        auto temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};