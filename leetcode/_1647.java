public class _1647 {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.minDeletions("aaabbcc"));
        System.out.println(s.minDeletions("aabbbcccddd"));
        System.out.println(s.minDeletions("aaaabbbbcccc"));
        System.out.println(s.minDeletions("aab"));
        System.out.println(s.minDeletions("aaabbbcc"));
        System.out.println(s.minDeletions("ceabaacb"));
        System.out.println(s.minDeletions(""));
        System.out.println(s.minDeletions("a"));
        System.out.println(s.minDeletions("abcabc"));

    }

    static class Solution {
        public int minDeletions(String s) {
            int result = 0;
            int[] bucket = new int[26];

            char[] carr = s.toCharArray();
            for (char c : carr) {
                bucket[c - 'a']++;
            }

            int[] cnt = new int[s.length() + 1];
            
            for(int i = 0; i < 26; i++) {
                cnt[bucket[i]]++;
            }

            for(int i = 1; i < cnt.length; i++) {
                while(cnt[i] > 1) {
                    int k = i;
                    while(k > 0 && cnt[k] > 1) {
                        result++;
                        cnt[k]--;
                        k--;
                        cnt[k]++;
                    }
                }
            }

            return result;
        }
    }
}