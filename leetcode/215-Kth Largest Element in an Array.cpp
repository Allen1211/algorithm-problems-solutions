/* 215. 数组中的第K个最大元素
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k
个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。 */

#include <time.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * STL小顶堆 时间复杂度 O(nlogk) 空间复杂度 O(k)
 */
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int> > heap;

//         int cnt = 0;
//         for (auto &&num : nums){
//             if(cnt == k && num > heap.top()){
//                 heap.pop();
//                 heap.push(num);
//             }else {
//                 heap.push(num);
//             }
//         }
//         return heap.top();
//     }
// };

/*
 * 基于快速排序的选择算法 时间复杂度(平均) O(n) 空间复杂度 O(logn)
 * (递归调用栈使用的空间)
 */
// class Solution {
//    public:
//     int partition(vector<int>& arr, int left, int right) {
//         // 随机选取基准数，然后把基准数暂时存到left的位置上。
//         int pivot = rand() % (right - left + 1) + left;
//         swap(arr[left], arr[pivot]);
//         pivot = left;
//         int i = left + 1, j = right;

//         while (i <= j) {
//             while (i < right && arr[i] < arr[pivot]) i++;
//             while (j > left && arr[j] > arr[pivot]) j--;
//             if (i < j) swap(arr[i], arr[j]);
//             i++;  // 防止死循环
//         }
//         swap(arr[j], arr[pivot]);
//         return j;
//     }

//     int quickselect(vector<int>& arr, int k, int left, int right) {
//         // 基准数位置
//         int pivot = partition(arr, left, right);
//         // 如果基准数就是处于第k个的位置，那么该数就是第k小的数
//         if (pivot == k) {
//             return arr[pivot];
//         }
//         // 如果基准数位置比k小，递归右子序列，否则递归左子序列
//         return pivot < k ? quickselect(arr, k, pivot + 1, right)
//                          : quickselect(arr, k, left, pivot - 1);
//     }

//     int findKthLargest(vector<int>& nums, int k) {
//         srand(time(0));
//         return quickselect(nums, nums.size() - k, 0, nums.size() - 1);
//     }
// };

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        // 对前k个元素建成小根堆
        for (int i = 0; i < k; i++) {
            swim(nums, i);
        }
        // 剩下的元素与堆顶比较，若大于堆顶则去掉堆顶，再将其插入
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > nums[0]) {
                swap(nums[0], nums[i]);
                sink(nums, 0, k - 1);
            }
        }
        // 结束后第k个大的数就是小根堆的堆顶
        return nums[0];
    }

   private:
    // 若v1比v2优先度高，返回true
    bool priorityThan(int v1, int v2) { return v1 < v2; }

    // 上浮 从下到上调整堆
    void swim(vector<int>& heap, int i) {
        while (i > 0 && priorityThan(heap[i], heap[(i - 1) / 2])) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // 下沉 从下到上调整堆
    void sink(vector<int>& heap, int i, int N) {
        while (2 * i + 1 <= N) {
            int j = 2 * i + 1;
            if (j + 1 <= N && priorityThan(heap[j + 1], heap[j])) {
                j++;
            }
            if (priorityThan(heap[i], heap[j])) {
                break;
            }
            swap(heap[i], heap[j]);
            i = j;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    s.findKthLargest(nums, 2);

    return 0;
}