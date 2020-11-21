import java.util.List;

import org.omg.CORBA.DynAnyPackage.Invalid;

public class _148_Sort_List {

    static class ListNode {
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

    /**
     * 归并排序，自底向上，迭代法
     */
    class Solution_MergeSort_BottomUp {
        public ListNode sortList(ListNode head) {
            int length = listLength(head);
            ListNode res = new ListNode(Integer.MIN_VALUE, head);

            for (int intv = 1; intv < length; intv *= 2) {
                ListNode prev = res;
                ListNode h = res.next;
                while (h != null) {
                    // BEGIN get the two merge head `h1`, `h2`
                    ListNode h1 = h, h2 = null;
                    int i = intv;
                    while (i != 0 && h != null) {
                        h = h.next;
                        i -= 1;
                    }
                    // no need to merge because the `h2` is None.
                    if (i != 0)
                        break;
                    h2 = h;
                    // END get the two merge head `h1`, `h2`

                    // get next h
                    i = intv;
                    while (i != 0 && h != null) {
                        h = h.next;
                        i -= 1;
                    }

                    // BEGIN merge the `h1` and `h2`.
                    int c1 = intv, c2 = intv - i; // the `c2`: length of `h2` can be small than the `intv`.
                    while (c1 > 0 && c2 > 0) {
                        if (h1.val < h2.val) {
                            prev.next = h1;
                            h1 = h1.next;
                            c1 -= 1;
                        } else {
                            prev.next = h2;
                            h2 = h2.next;
                            c2 -= 1;
                        }
                        prev = prev.next;
                    }
                    prev.next = c1 > 0 ? h1 : h2;
                    // END merge the `h1` and `h2`

                    // let prev be the node before h
                    while (c1-- > 0 || c2-- > 0)
                        prev = prev.next;
                    prev.next = h;
                }
            }
            return res.next;
        }

        /**
         * 计算链表长度
         */
        private int listLength(ListNode head) {
            int length = 0;
            while (head != null) {
                length += 1;
                head = head.next;
            }
            return length;
        }
    }

    /**
     * 归并排序 自顶向下 递归版
     */
    class Solution_MergeSort_TopDown {
        public ListNode sortList(ListNode head) {
            if (head == null || head.next == null) {
                return head;
            }
            ListNode fast = head.next;
            ListNode slow = head;
            while (fast.next != null && fast.next.next != null) {
                slow = slow.next;
                fast = fast.next.next;
            }

            ListNode temp = slow.next;
            slow.next = null; // 要把链表从中间断开

            ListNode left = sortList(head);
            ListNode right = sortList(temp);

            return mergeTwoLists(left, right);

        }

        /**
         * 合并两个有序链表
         */
        private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
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

    /**
     * 插入排序
     */
    static class Solution_InsertionSort {
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

    /**
     * 快速排序，超时
     */
    static class Solution_QuickSort {
        public ListNode sortList(ListNode head) {
            ListNode dummy = new ListNode(Integer.MIN_VALUE, head);
            quicksort(dummy, null);
            return dummy.next;
        }

        private void quicksort(ListNode left, ListNode right) {
            if (left == null || left == right || left.next == right)
                return;
            ListNode pivot = partition(left, right);
            quicksort(left, pivot);
            while (pivot.next != null && pivot.next.val == pivot.val) {
                pivot = pivot.next;
            }
            quicksort(pivot, right);
        }

        private ListNode partition(ListNode left, ListNode right) {
            if (left == null || left.next == null || left == right) {
                return left;
            }
            ListNode pivot = left.next;
            int pivotVal = left.next.val;
            ListNode lt = left.next;
            for (ListNode i = left.next; i != null && i.next != right; i = i.next) {
                while (i.next != null && i.next.val < pivotVal) {
                    swap(i, lt);
                    lt = lt.next;
                    if (i.next == lt) {
                        break;
                    }
                }
            }
            swap(left, lt);
            return pivot;
        }

        // 把p的下一个结点成为q的下一个结点
        private void swap(ListNode p, ListNode q) {
            if (p != q && p.next != q) {
                ListNode temp = p.next;
                p.next = p.next.next;
                temp.next = q.next;
                q.next = temp;
            }
        }
    }

}