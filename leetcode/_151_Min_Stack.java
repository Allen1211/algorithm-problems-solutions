/*
 * @lc app=leetcode.cn id=155 lang=java
 *
 * [155] 最小栈
 */

// @lc code=start

class _151_Min_Stack {

    class MinStack {

        class Node {
            int val;
            int minVal;
            Node next;

            public Node(int val, int minVal) {
                this.val = val;
                this.minVal = minVal;
                this.next = null;
            }
        }

        private Node head = null;

        /** initialize your data structure here. */
        public MinStack() {

        }

        public void push(int x) {
            int minVal = head == null ? x : Math.min(head.minVal, x);
            Node node = new Node(x, minVal);
            if (head != null) {
                node.next = head;
            }
            head = node;
        }

        public void pop() {
            head = head.next;
        }

        public int top() {
            return head.val;
        }

        public int getMin() {
            return head.minVal;
        }
    }
}

/**
 * Your MinStack object will be instantiated and called as such: MinStack obj =
 * new MinStack(); obj.push(x); obj.pop(); int param_3 = obj.top(); int param_4
 * = obj.getMin();
 */
// @lc code=end
