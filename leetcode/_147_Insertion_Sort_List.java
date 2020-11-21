import java.util.List;

public class _147_Insertion_Sort_List {

    private static class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    class Solution {
        public ListNode insertionSortList(ListNode head) {
            if (head == null || head.next == null) return head;
            head.next = insertionSortList(head.next);
            ListNode ret;
            ListNode q = head;
            while (q.next != null && head.val > q.next.val) q = q.next;
            if (q == head) {
                ret = head;
            } else {
                ret = head.next;
                ListNode temp = q.next;
                q.next = head;
                head.next = temp;
            }
            return ret;
        }
    }

    class Solution2 {
        public ListNode insertionSortList(ListNode head) {
            if (head == null || head.next == null) {
                return head;
            }

            ListNode dummy = new ListNode(0);
            dummy.next = head;
            ListNode lastSorted = head;
            ListNode curr = head.next;

            while (curr != null) {
                if (curr.val < lastSorted.val) {
                    ListNode prev = dummy;
                    while (curr.val > prev.next.val) {
                        prev = prev.next;
                    }
                    ListNode temp = prev.next;
                    prev.next = curr;
                    lastSorted.next = curr.next;
                    curr.next = temp;
                } else {
                    lastSorted = curr;
                }
                curr = lastSorted.next;
            }

            return dummy.next;
        }
    }
}