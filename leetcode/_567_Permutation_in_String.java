
public class _567_Permutation_in_String {

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.checkInclusion("ab", "eidbaooo"));
        System.out.println(s.checkInclusion("ab", "eidboaoo"));
    }

    static class Solution {
        public boolean checkInclusion(String s1, String s2) {
            int[] need = new int[26];
            int cnt = 0, N = 0;
            for (char c : s1.toCharArray()) {
                if (++need[c - 'a'] == 1){
                    ++N;
                }
            }
            for (int i = 0, j = 0; i < s2.length(); i++) {
                if (--need[s2.charAt(i) - 'a'] == 0) {
                    ++cnt;
                }
                while (j <= i && need[s2.charAt(i) - 'a'] == -1) {
                    if (++need[s2.charAt(j) - 'a'] == 1) {
                        --cnt;
                    }
                    ++j;
                }
                if (cnt == N) return true;
            }
    
            return false;
        }
    }
}