/*
21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {

    }
    ListNode(int x) : val(x), next(nullptr) {

    }
    ListNode(int x, ListNode *next) : val(x), next(next) {

    }
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    if(!p1 && !p2){
        return nullptr;
    }else if(!p1 && p2){
        return p2;
    }else if(p1 && !p2){
        return p1;
    }else {
        ListNode *head = nullptr;
        ListNode *pn = nullptr;
        while (p1 && p2)
        {
            ListNode *next = new ListNode();
            if(p1->val < p2->val){
                next->val = p1->val;
                p1 = p1->next;
            }else {
                next->val = p2->val;
                p2 = p2->next;
            }
            if(!pn){
                pn = new ListNode(next->val, nullptr);
                head = pn;
            }else {
                pn->next = next;
                pn = next;
            }
        }
        if(p1){
            pn->next = p1;
        }else if(p2){
            pn->next = p2;
        }
        return head;
    }


}

void print(ListNode *list){
    ListNode *p = list;
    while (p)
    {
        cout << p->val << " ";
    }
    cout << endl;
    
}


int main(){


    ListNode *list = mergeTwoLists(nullptr, nullptr);
    
    
    print(list);
    return 0;
}
