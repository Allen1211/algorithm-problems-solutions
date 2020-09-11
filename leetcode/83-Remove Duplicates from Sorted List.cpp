/*
83. 删除排序链表中的重复元素
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
*/

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p1, *p2;
        p1 = head;
        p2 = head->next;
        while (p2){
            while (p2 && p2->val == p1->val){
                p2 = p2->next;
            }
            p1->next = p2;
            p1 = p2;
            if(p2){
                p2 = p2->next;
            }
        }
        return head;
    }
};