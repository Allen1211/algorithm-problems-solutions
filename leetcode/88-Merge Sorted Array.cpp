/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start

#include <vector>

using namespace std;

// class Solution {
//    public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = 0, j = 0;
//         while (j < n) {
//             while (i < m && nums1[i] <= nums2[j]) {
//                 i++;
//             }
//             if (i < m) {
//                 for (int k = m; k > i; k--) {
//                     nums1[k] = nums1[k - 1];
//                 }
//                 nums1[i++] = nums2[j++];
//                 m++;
//             } else {
//                 while (j < n) {
//                     nums1[m++] = nums2[j++];
//                 }
//                 break;
//             }
//         }
//     }
// };

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p = m + n - 1;
        while (p1 >= 0 && p2 >= 0) {
            nums1[p--] = nums1[p1] >= nums2[p2] ? nums1[p1--] : nums2[p2--];
        }
        while (p2 >= 0) {
            nums1[p2] = nums2[p2];
            p2--;
        }
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    s.merge(nums1, 3, nums2, 3);
}