import java.util.ArrayList;
import java.util.List;

public class _22_Generate_Parentheses {
    class Solution {
        public List<String> generateParenthesis(int n) {
            List<String> results = new ArrayList<>();
            dfs(results, new ArrayList<>(), 0, 0, n);
            return results;
        }

        private void dfs(List<String> results, List<String> result, int left, int right, int n) {
            if (left + right == n * 2) {
                results.add(String.join("", result));
                return;
            }
            if (left < n) {
                result.add("(");
                dfs(results, result, left + 1, right, n);
                result.remove(result.size() - 1);
            }
            if (left > right) {
                result.add(")");
                dfs(results, result, left, right + 1, n);
                result.remove(result.size() - 1);
            }
        }
    }
}