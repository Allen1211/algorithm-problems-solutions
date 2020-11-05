
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
    vector<int> ans;
    int i = 0;

   public:
    BSTIterator(TreeNode *root) {
        ans = inorderTraversal(root);
    }

    /** @return the next smallest number */
    int next() {
        return ans[i++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return i < ans.size();
    }

   private:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *curr = root;
        TreeNode *pre = root;
        while (curr) {
            if (curr->left != nullptr) {
                pre = curr->left;
                while (pre->right != nullptr && pre->right != curr) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    result.emplace_back(curr->val);
                    pre->right = nullptr;
                    curr = curr->right;
                }
            } else {
                result.emplace_back(curr->val);
                curr = curr->right;
            }
        }
        return result;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */