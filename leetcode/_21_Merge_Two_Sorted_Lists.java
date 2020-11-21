public class _21_Merge_Two_Sorted_Lists {
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
        public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
            ListNode dummy = new ListNode();
            ListNode prev = dummy;

            while (l1 != null && l2 != null) {
                if (l1.val < l2.val) {
                    prev.next = l1;
                    prev = l1;
                    l1 = l1.next;
                } else {
                    prev.next = l2;
                    prev = l2;
                    l2 = l2.next;
                }
            }
            prev.next = l1 != null ? l1 : l2;

            return dummy.next;
        }
    }
}