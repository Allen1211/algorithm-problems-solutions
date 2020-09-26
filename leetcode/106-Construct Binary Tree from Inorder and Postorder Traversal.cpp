/* 106. 从中序与后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7 */

#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    int rootIdx;
    unordered_map<int, int> idxMap;

    TreeNode* doBuild(vector<int>& inorder, vector<int>& postorder, int left, int right){
        if(left > right){
            return nullptr;
        }
        int val = postorder[rootIdx--];
        auto root = new TreeNode(val);
        int mid = idxMap[val];

        root->left = doBuild(inorder, postorder, left, mid - 1);
        root->right = doBuild(inorder, postorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        for(int i = 0; i < size; i++){
            idxMap[inorder[i]] = i;
        }
        rootIdx = size - 1;

        return doBuild(inorder, postorder, 0, size);

    }
};