/*
24. 两两交换链表中的节点
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。



示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    void doSwap(ListNode *p, ListNode *q) {
        p->next = q->next;
        q->next = p->next->next;
        p->next->next = q;
    }

    ListNode *swapPairs(ListNode *head) {
        if (!head || !(head->next)) {
            return head;
        }

        ListNode *L = new ListNode(-1);
        ListNode *p = L;
        p->next = head;
        ListNode *q = head;

        while (q && q->next) {
            doSwap(p, q);
            p = p->next->next;
            q = q->next;
        }

        return L->next;
    }
};

int main(){
    auto *l1 = new ListNode(1);
    auto *l2 = new ListNode(2);
    auto *l3 = new ListNode(3);
    auto *l4 = new ListNode(4);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = nullptr;

    Solution s;
    s.swapPairs(l1);


}