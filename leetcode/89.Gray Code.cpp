/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start

#include <math.h>

#include <vector>

using namespace std;

// class Solution {
//    public:
//     vector<int> grayCode(int n) {
//         vector<int> result;
//         result.push_back(0);
//         for(int i = 0; i < n; i++){
//             int add = 1 << i;
//             for(int j = result.size() - 1; j >= 0; j--){
//                 result.push_back(result[j] + add);
//             }
//         }
//         return result;
//     }
// };
class Solution {
   public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for(int i = 0; i < 1 << n; i++){
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};
// @lc code=end
