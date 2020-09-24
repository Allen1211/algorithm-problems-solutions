/* 95. 不同的二叉搜索树 II
给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。



示例：

输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


提示：

0 <= n <= 8 */

#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

/*
 * 动规解法
比如求 n= 4，也就是把1,2,3,4组合成树，也就是求 dp[1,4]

初始条件：只有一个结点的情况，dp[x,x] = {new TreeNode(x)};

状态转移推导 (举个例子，一般的不好写）

求1,2,3,4 组合成的树：

当1为根时，其右子树为 [2,3,4]的所有组合；
当2为根时，其左子树为[1]的所有组合，右子树为 [3,4]的所有组合
当3为根时， 其左子树为[1,2]的所有组合，右子树为[4]的所有组合
当4为根时，其右子树为[1,2,3]的所有组合
按照这样的思路，可以用递归回溯去解决，但是动规的话，需要倒过来：

先根据基本条件，求出 dp[1][2]、dp[2][3]、dp[3][4]

再根据现有结果 算出 dp[1][3]、dp[2][4]

最后根据现有结果算出 dp[1][4]
 */
class Solution {
   public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return {};
        vector<TreeNode *> dp[n + 1][n + 1];
        // 初始化
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = {};
            }
        }
        // 初始条件
        for (int i = 1; i <= n; i++) {
            dp[i][i] = {new TreeNode(i)};
        }
        for (int step = 1; step < n; step++) {
            for (int left = 1, right = left + step; right <= n; left++, right++) {
                vector<TreeNode *> results;
                for (int i = left; i <= right; i++) {
                    // 左、右子树所有可能
                    vector<TreeNode *> leftSubTrees = dp[left][i - 1];
                    vector<TreeNode *> rightSubTrees = dp[i + 1][right];
                    if (leftSubTrees.empty()) {
                        for (TreeNode *rst : rightSubTrees) {
                            results.push_back(new TreeNode(i, nullptr, rst));
                        }
                    }else if (rightSubTrees.empty()) {
                        for (TreeNode *lst : leftSubTrees) {
                            results.push_back(new TreeNode(i, lst, nullptr));
                        }
                    }else {
                        for (TreeNode *lst : leftSubTrees) {
                            for (TreeNode *rst : rightSubTrees) {
                                results.push_back(new TreeNode(i, lst, rst));
                            }
                        }
                    }
                }
                dp[left][right] = results;
            }
        }
        return dp[1][n];
    }
};

/*
 * 记忆化递归
 */ 
class Solution {
   public:
    struct hashfunc
    {
        template<typename T, typename U>
        size_t operator() (const pair<T, U> &i) const
        {
            return hash<T>()(i.first) ^ hash<U>()(i.second);
        }
    };
    unordered_map<pair<int, int>, vector<TreeNode *>, hashfunc > cache;

    vector<TreeNode *> fromCache(int x, int y) {
        pair<int, int> pair(x, y);
        if (cache.find(pair) == cache.end()) {
            cache[pair] = doGenerate(x, y);
        }
        return cache[pair];
    }

    vector<TreeNode *> doGenerate(int x, int y) {
        if (x == y) {
            return {new TreeNode(x)};
        }
        vector<TreeNode *> results;
        for (int i = x; i <= y; i++) {
            if (i == x) {
                vector<TreeNode *> rightSubTrees = fromCache(x + 1, y);
                for (TreeNode *rst : rightSubTrees) {
                    results.push_back(new TreeNode(i, nullptr, rst));
                }
            } else if (i == y) {
                vector<TreeNode *> leftSubTrees = fromCache(x, y - 1);
                for (TreeNode *lst : leftSubTrees) {
                    results.push_back(new TreeNode(i, lst, nullptr));
                }
            } else {
                vector<TreeNode *> leftSubTrees = fromCache(x, i - 1);
                vector<TreeNode *> rightSubTrees = fromCache(i + 1, y);
                for (TreeNode *lst : leftSubTrees) {
                    for (TreeNode *rst : rightSubTrees) {
                        results.push_back(new TreeNode(i, lst, rst));
                    }
                }
            }
        }
        return results;
    }

    vector<TreeNode *> generateTrees(int n) { return doGenerate(1, n); }
};