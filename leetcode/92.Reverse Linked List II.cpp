/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* p = head;
        ListNode *p_from, *p_to, *p_m, *p_n;
        p_from = p_to = p_m = p_to = nullptr;
        for (int i = 0; i < m - 1; i++) {
            p_from = p;
            p = p->next;
        }
        p_m = p;
        ListNode* t = p_from;
        for (int i = m; i <= n; i++) {
            ListNode* q = p->next;
            p->next = t;
            t = p;
            p = q;
        }
        p_to = p;
        p_n = t;

        if (p_from == nullptr && p_to == nullptr) {
            return p_n;
        } else if (p_from == nullptr) {
            p_m->next = p_to;
            return p_n;
        } else {
            p_from->next = p_n;
            p_m->next = p_to;
            return head;
        }
    }
};
// @lc code=end
