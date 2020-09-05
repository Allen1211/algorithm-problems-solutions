/*
49. 字母异位词分组
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
*/

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 字母相同的字符串排序后必然相等
 * 所以可以升序排序后的字符串作为key
 */
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> results;
//         unordered_map<string, vector<string>> map;
//         for(string str : strs){
//             string temp = str;
//             sort(temp.begin(), temp.end());
//             map[temp].push_back(str);
//         }
//         for(auto& p : map){
//             results.push_back(p.second);
//         }
//         return results;
//     }
// };

/*
因为不同的质数的积必定为不同的数字结果
用一个数组存储质数 prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47,
53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103}。
对26个字母分别赋予对应的质数值
然后每个字符串的字符减去 ' a ' ，然后取到 prime 中对应的质数。把它们累乘。
https://leetcode-cn.com/problems/group-anagrams/solution/c-map-stringvectorstring-z-by-zrita/
*/
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<double, vector<string>> map;
        double prime[26] = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                            29, 31, 37, 41, 43, 47, 53, 59, 61,
                            67, 71, 73, 79, 83, 89, 97, 101};
        for (string& str : strs) {
            double key = 1;
            for (char c : str) key *= prime[c - 'a'];

            map[key].push_back(
                str);  // t为单词对应的质数乘积，m[t]则为该单词的异位词构成的vector
        }
        for (auto& n : map)  // n为键和值组成的pair
            res.push_back(n.second);
        return res;
    }
};
