/*
*55. 跳跃游戏
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3
步到达最后一个位置。 示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ，
所以你永远不可能到达最后一个位置。
*/

#include <iostream>
#include <vector>

using namespace std;

// class Solution {
//    public:
//     bool dfs(bool **graph, bool *marked, int i, int n) {
//         if (graph[i][n - 1] || i == n - 1) {
//             return true;
//         }
//         for (int j = i + 1; j < n; j++) {
//             if (!marked[j] && graph[i][j]) {
//                 marked[j] = true;
//                 if (dfs(graph, marked, j, n)) {
//                     return true;
//                 }
//                 // marked[j] = false;
//             }
//         }
//         // marked[i] = true;
//         return false;
//     }

//     bool canJump(vector<int> &nums) {
//         int size = nums.size();
//         if (size <= 1) {
//             return true;
//         }
//         bool **graph = new bool *[size];
//         bool marked[size];
//         for (int i = 0; i < size; i++) {
//             graph[i] = new bool[size];
//         }
//         for (int i = 0; i < size; i++) {
//             marked[i] = false;
//             for (int j = 0; j < size; j++) {
//                 graph[i][j] = false;
//             }
//         }

//         for (int i = 0; i < size; i++) {
//             int steps = nums[i];
//             for (int j = 0; j < steps; j++) {
//                 int k = (i + j + 1) < (size - 1) ? (i + j + 1) : size - 1;
//                 graph[i][k] = true;
//             }
//         }

//         return dfs(graph, marked, 0, size);
//     }
// };

class Solution {
   public:
    bool canJump(vector<int> &nums) {
        int size = nums.size();
        if(size <= 1) return true;
        int steps = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (--steps < 0) {
                return false;
            }
            if(i + nums[i] == size - 1){
                return true;
            }
            if (nums[i] > steps) {
                steps = nums[i];
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};
    vector<int> nums3 = {2, 0};
    cout << s.canJump(nums1) << endl;
    cout << s.canJump(nums2) << endl;
    cout << s.canJump(nums3) << endl;
}
