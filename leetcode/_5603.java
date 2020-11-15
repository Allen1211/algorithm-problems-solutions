public class _5603 {

    public static void main(String[] args) {
        Solution s = new Solution();
        s.closeStrings("abc", "bca");
    }

    static class Solution {
        public boolean closeStrings(String word1, String word2) {
            if(word1.length() != word2.length()) {
                return false;
            }
            int len = word1.length();
    
            char[] carr1 = word1.toCharArray();
            char[] carr2 = word2.toCharArray();
    
            // 字母计数
            int[] alphaCnt1 = new int[26];
            int[] alphaCnt2 = new int[26];
            for (int i = 0; i < len; i++) {
                alphaCnt1[carr1[i] - 'a']++;
                alphaCnt2[carr2[i] - 'a']++;
            }
    
            // 检查是否出现另一个没有的字母
            for (int i = 0; i < 26; i++) {
                if((alphaCnt1[i] == 0 && alphaCnt2[i] != 0)
                || (alphaCnt1[i] != 0 && alphaCnt2[i] == 0)) {
                    return false;
                }
            }
    
            // 检查出现次数的计数是否一致
            int[] numCnt1 = new int[len + 1];
            int[] numCnt2 = new int[len + 1];
    
            for (int i = 0; i < 26; i++) {
                numCnt1[alphaCnt1[i]]++;
                numCnt2[alphaCnt2[i]]++;
            }
    
            for (int i = 0; i <= len; i++) {
                if(numCnt1[i] != numCnt2[i]) {
                    return false;
                }
            }
    
            return true;
        }
    }
}