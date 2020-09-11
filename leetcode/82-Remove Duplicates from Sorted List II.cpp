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
        if(!head || !(head->next)){
            return head;
        }
        // 真 头结点
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p1 = dummy;
        ListNode *p2 = dummy->next;
        while (p2){
            if(!p2 -> next){                    // p2已经是最后一个结点了，结束
                break;
            }else if(p2->next->val != p2->val){ // 下一个结点和当前结点值不等，说明当前元素p2->val不重复，p1,p2一起向前
                p1 = p1->next;
                p2 = p2->next;
            }else {                             // p2是个重复结点，应去掉包括该结点及后面所有值等于p2->val的结点。
                int duplicate = p2->val;
                while ((p2 = p2->next) && p2->val == duplicate);    //移动到下一个与p2值不同的结点
                p1->next = p2;
            }
        }
        return dummy->next;                     //返回新的头结点
    }
};


int main(){
    ListNode head(1);
    ListNode p1(2);
    ListNode p2(3);
    ListNode p3(3);
    ListNode p4(4);
    ListNode p5(4);
    ListNode p6(5);

    head.next = &p1;
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    p5.next = &p6;


    Solution s;
    s.deleteDuplicates(&head);

    return 0;
}