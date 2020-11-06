/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* t = nullptr;
        ListNode* p = head;
        ListNode* q = p;
        while(p != nullptr) {
            q = p->next;
            p->next = t;
            t = p;
            p = q;
        }
        return t;
    }
};
// @lc code=end
