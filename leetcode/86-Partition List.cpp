/* 86. 分隔链表
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于
x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。



示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5 */

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* p = dummy;
        while(p->next && p->next->val < x) {
            p = p->next;
        }
        if(!p->next){
            return dummy->next;
        }

        ListNode* q = p;

        while(q->next){
            while(q->next && q->next->val >= x){
                q = q->next;
            }
            if(q->next){
                ListNode* temp = q->next;
                q->next = q->next->next;
                temp->next = p->next;
                p->next = temp;
                p = p->next;
            }
        }

        return dummy->next;
    }
};