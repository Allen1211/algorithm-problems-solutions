import sun.net.www.content.image.png;

/*
 * @lc app=leetcode.cn id=328 lang=java
 *
 * [328] 奇偶链表
 */

// @lc code=start

class _328_Odd_Even_Linked_List {

    class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    class Solution {
        public ListNode oddEvenList(ListNode head) {
            if (head == null || head.next == null) {
                return head;
            }

            ListNode oddHead = head;
            ListNode evenHead = head.next;

            ListNode p = oddHead, q = evenHead;
            while (p.next != null) {
                p.next = q.next;
                if (q.next != null) {
                    q.next = q.next.next;
                }
                if (p.next == null) {
                    break;
                }
                p = p.next;
                q = q.next;
            }
            p.next = evenHead;
            return oddHead;
        }
    }
}
// @lc code=end
