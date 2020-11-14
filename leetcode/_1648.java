import java.math.BigInteger;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class _1648 {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.maxProfit(new int[] { 773160767 }, 252264991));
    }

    static class Solution {
        final long limit = Long.valueOf(1000000007L);

        public int maxProfit(int[] inventory, int orders) {
            PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int i = 0; i < inventory.length; i++) {
                int c = cnt.getOrDefault(inventory[i], 0);
                if (c == 0) {
                    pq.add(inventory[i]);
                }
                cnt.put(inventory[i], c + 1);
            }

            long result = 0;

            pq.add(0);
            while (orders > 0) {
                int first = pq.poll();
                int second = pq.element();

                int firstCnt = cnt.get(first);
                int secondCnt = cnt.getOrDefault(second, 0);

                long sum;
                
                long num = (first - second) * firstCnt;
                if (num <= orders) {
                    sum = (second + 1 + first) * num / 2;
                } else {
                    long x = orders / firstCnt, y = orders % firstCnt;

                    sum = (first + (first - x) + 1) * firstCnt * x / 2;
                    sum %= limit;
                    sum += (first - x) * y;
                    sum %= limit;
                }
                result = (result + sum) % limit;

                cnt.put(second, firstCnt + secondCnt);
                orders -= num;
            }

            return (int) (result % limit);
        }
    }
}