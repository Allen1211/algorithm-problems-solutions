/* https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
 */

#include <stack>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
   public:

    Node* treeToDoublyList(Node* root) {
        if (!root) {
            return root;
        }
        stack<Node*> s;
        s.push(root);
        Node* p = root;
        Node* pre = nullptr;
        Node* curr = nullptr;
        Node* head = nullptr;
        Node* tail = nullptr;
        while (true) {
            while (p->left) {
                s.push(p->left);
                p = p->left;
            }
            do {
                curr = p = s.top();
                s.pop();

                if(pre != nullptr){
                    pre->right = curr;
                    curr->left = pre;
                }else {
                    head = p;
                }
                pre = curr;

            } while (p->right == nullptr && !s.empty());

            if (p->right) {
                s.push(p->right);
                p = p->right;
            } else {
                tail = p;
                break;
            }
        }
        head->left = tail;
        tail->right = head;

        return head;
    }
};