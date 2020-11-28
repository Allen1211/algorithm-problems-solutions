
public class _5606 {
    class Solution {
        public String getSmallestString(int n, int k) {
            int curr = 0;
            StringBuilder res = new StringBuilder(n);
            for (int i = n - 1; i >= 0; i--) {
                if (k - 26 >= i) {
                    curr = 26;
                    k -= 26;
                }else {
                    int x = k - i;
                    curr = x;
                    k -= x;
                }
                res.append((char) (curr + 'a' - 1));
            }
    
            return res.reverse().toString();
        }
    }
}