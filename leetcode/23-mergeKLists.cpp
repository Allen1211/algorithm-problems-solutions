/*
23. 合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。



示例 1：

输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：

输入：lists = []
输出：[]
示例 3：

输入：lists = [[]]
输出：[]


提示：

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4

*/
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
 * 暴力法 O(NlogN)
 */
// ListNode *mergeKLists(vector<ListNode *> &lists) {
//     int size = lists.size();
//     if (size == 0 || (size == 1 && lists[0] == nullptr)) {
//         return nullptr;
//     }
//     vector<int> arr;
//     for (ListNode *link : lists) {
//         for (ListNode *p = link; p; p = p->next) {
//             arr.push_back(p->val);
//         }
//     }
//     sort(arr.begin(), arr.end());
//     ListNode *head, *p1, *p2;
//     head = p1 = p2 = nullptr;
//     for (int val : arr) {
//         if (!p1) {
//             p1 = new ListNode();
//             p1->val = val;
//             head = p1;
//         } else {
//             p2 = new ListNode(val, nullptr);
//             p1->next = p2;
//             p1 = p2;
//         }
//     }
//     return head;
// }

/*
 * 最小堆法
 * 由于每一条链表都是有序的
 * 由于最多只有k个结点在堆中，所以
 * O(Nlogk)
 * 
 */
struct Status{
    int val;
    ListNode *ptr;
    bool operator < (const Status &rhs) const {
        return val > rhs.val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists){
    priority_queue<Status> q;
    for(auto l : lists){
        if(l){
            q.push({l->val, l});
        }
    }
    ListNode head;
    ListNode *p = &head;
    while (!q.empty()){
        auto s = q.top();q.pop();
        p->next = s.ptr;
        p = p->next;
        if(s.ptr->next){
            q.push({s.ptr->next->val, s.ptr->next});
        }
    }
    return head.next;
}