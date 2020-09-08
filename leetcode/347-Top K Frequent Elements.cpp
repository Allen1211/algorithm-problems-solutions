/*
347. 前 K 个高频元素
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。



示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]


提示：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。
*/

#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * 方法1：
 *  map存各元素的计数
 *  遍历map，把元素和元素计数的结构体存入大顶堆 复杂度 O(NlogN)
 *  从堆出队前k个元素即是答案
 */
// class Solution {
//    public:
//     struct Node {
//         int val;
//         int cnt;
//         Node(int val, int cnt) : val(val), cnt(cnt) {}

//         bool operator<(const Node& a) const {
//             return cnt < a.cnt;  //大顶堆
//         }
//     };
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         int size = nums.size();
//         if (size <= k) {
//             return nums;
//         }
//         vector<int> result;
//         priority_queue<Node> heap;
//         unordered_map<int, int> map;

//         for (int i = 0; i < size; i++) {
//             map[nums[i]]++;
//         }
//         for (auto it = map.begin(); it != map.end(); it++) {
//             Node node(it->first, it->second);
//             heap.push(node);
//         }
//         while (k--) {
//             result.push_back(heap.top().val);
//             heap.pop();
//         }
//         return result;
//     }
// };

/*
 * 方法1的优化： 时间复杂度O(Nlogk) 空间复杂度 O(N)
 * 由于题目是求前k大/小， 因此没有必要把所有元素都放进堆里，
 * 使用小顶堆可以使得堆内元素最多只有k个，使得时间复杂度下降到 O(Nlogk)
 * 建立小顶堆，在把Node插入到堆前，判断堆内元素是否小于k
 * 如果堆的元素个数小于 k，就可以直接插入堆中。
 * 如果堆的元素个数等于 k，则检查堆顶与当前出现次数的大小。
 *   如果堆顶更大，说明至少有 k
 * 个数字的出现次数比当前值大，故舍弃当前值；否则，就弹出堆顶，并将当前值插入堆中。
 * 最终堆中的元素就代表了中前 k 大的值。
 */
// class Solution {
//    public:
//     struct Node {
//         int val;
//         int cnt;
//         Node(int val, int cnt) : val(val), cnt(cnt) {}

//         bool operator<(const Node& a) const {
//             return cnt > a.cnt;  //小顶堆
//         }
//     };
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         int size = nums.size();
//         if (size <= k) {
//             return nums;
//         }
//         vector<int> result;
//         priority_queue<Node> heap;
//         unordered_map<int, int> map;

//         for (int i = 0; i < size; i++) {
//             map[nums[i]]++;
//         }
//         for (auto it = map.begin(); it != map.end(); it++) {
//             if(heap.size() < k){
//                 heap.push(*(new Node(it->first, it->second)));
//             }else if(heap.top().cnt < it->second){
//                 heap.pop();
//                 heap.push(*(new Node(it->first, it->second)));
//             }
//         }
//         while (!heap.empty()) {
//             result.push_back(heap.top().val);
//             heap.pop();
//         }
//         return result;
//     }
// };

/*
* 方法2： 
* 桶排序法   时间复杂度 O(N) 空间复杂度 O(N)
* 与方法1相同，先使用map记录出现次数
* 创建桶数组，用元素的计数作为桶的下标(最多出现size次，因此桶数组大小是size+1) ，元素的值作为桶元素的值
* 遍历计数Map，填入桶数组
* 最后从后往前遍历桶数组，将前k个元素输出即可
* 注意可能有多个元素的出现次数相同，因此桶数组要定义成 vector<vector<int> >
*/
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        if (size <= k) {
            return nums;
        }
        vector<int> result;
        unordered_map<int, int> map;
        vector<vector<int> > bucket(size + 1);

        for (int i = 0; i < size; i++) {
            map[nums[i]]++;
        }
        for (auto it = map.begin(); it != map.end(); it++) {
            bucket[it->second].push_back(it->first);
        }
        for (int i = size; i >= 1 && k; i--) {
            vector<int> elements = bucket[i];
            if (!elements.empty()) {
                for (auto element : elements) {
                    result.push_back(element);
                    k--;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    s.topKFrequent(nums, 3);
}