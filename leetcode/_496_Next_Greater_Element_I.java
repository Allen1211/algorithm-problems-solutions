import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

public class _496_Next_Greater_Element_I {
    class Solution {
        public int[] nextGreaterElement(int[] nums1, int[] nums2) {
            Deque<Integer> stack = new LinkedList<>();
            Map<Integer, Integer> map = new HashMap<>();
            for (int i = 0; i < nums2.length; i++) {
                while (!stack.isEmpty() && stack.peekLast() < nums2[i]) {
                    map.put(stack.pollLast(), nums2[i]);
                }
                stack.addLast(nums2[i]);
            }
            while (!stack.isEmpty()) {
                map.put(stack.pollLast(), -1);
            }

            int[] res = new int[nums1.length];
            for (int i = 0; i < nums1.length; i++) {
                res[i] = map.get(nums1[i]);
            }

            return res;
        }
    }
}