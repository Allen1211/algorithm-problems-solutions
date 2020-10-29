/* 143. 重排链表
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3. */

#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
/*
class Solution {
   public:

    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        stack<ListNode*> s;

        // 把链表用栈存储
        auto q = head;
        while (q) {
            s.push(q);
            q = q->next;
        }

        // p指针指向链表头，q指针利用栈弹出从尾部倒过来遍历
        auto p = head;
        while (!s.empty()) {
            q = s.top();s.pop();
            // 当p，q指针相遇，算法结束
            if (p == q || p->next == q) {
                q->next = nullptr;
                return;
            }

            // 让q指向的结点成为p的下一个结点
            auto t = p->next;
            p->next = q;
            q->next = t;
            p = t;
        }
    }
}; */

class Solution {
   public:
    /*
     * 快慢指针找到链表中点
     */
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    /*
     * 反转链表
     */
    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }

    /*
     * 合并链表
     */ 
    void mergeLsit(ListNode* L1, ListNode* L2){
        while(L1 && L2){
            ListNode* t1 = L1->next;
            ListNode* t2 = L2->next;
            L1->next = L2;
            L1 = t1;
            L2->next = L1;
            L2 = t2;
        }
    }

    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        // 找到中点
        ListNode* middle = middleNode(head);
        // 分离前后两个链表
        ListNode* L1 = head;
        ListNode* L2 = middle->next;
        middle->next = nullptr;
        // 将第二个链表反转
        L2 = reverseList(L2);
        // 合并
        mergeLsit(L1, L2);
    }
};

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = nullptr;

    Solution s;
    s.reorderList(n1);
    return 0;
}