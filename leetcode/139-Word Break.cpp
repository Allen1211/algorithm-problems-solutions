/* 139. 单词拆分
给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s
是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    unordered_map<char, pair<int, int>> idxMap;

   public:
    // int compare(string s1, string s2) {
    //     int len1 = s1.size();
    //     int len2 = s2.size();
    //     int lim = min(len1, len2);
    //     int i = 0;
    //     while (i < lim) {
    //         char c1 = s1[i];
    //         char c2 = s2[i];
    //         if (c1 != c2) {
    //             return c1 - c2;
    //         }
    //         i++;
    //     }
    //     return len1 - len2;
    // }

    // bool binarySearch(string s, vector<string>& wordDict, int begin, int end)
    // {
    //     int left = begin;
    //     int right = end;
    //     while (left < right) {
    //         int mid = (right - left) / 2;
    //         int comp = compare(s, wordDict[mid]);
    //         if (comp == 0) {
    //             return true;
    //         } else if (comp < 0) {
    //             right = mid - 1;
    //         } else {
    //             left = mid + 1;
    //         }
    //     }
    //     return compare(s, wordDict[left]) == 0;
    // }

    bool helper(string s, vector<string>& wordDict) {
        if(s.length() == 0){
            return true;
        }
        pair<int, int> pair = idxMap[s[0]];
        if (pair.second == 0) {
            return false;
        }
        for (int x = pair.first, y = 1; ;) {
            if (x >= pair.first + pair.second) {
                return false;
            }
            // 找到了一个匹配，根据递归结果决定是否要继续
            if (y >= wordDict[x].length()) {
                if (helper(s.substr(y), wordDict)) {
                    return true;
                } else {  // 后续没有匹配成功，继续
                    x += 1;
                    y = 1;
                    continue;
                }
            }

            if(y < s.size()){
                return false;
            }

            if (s[y] == wordDict[x][y]) {
                y++;
            } else if (s[y] > wordDict[x][y]) {
                x++;
                y = 1;
            } else {
                return false;
            }
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        char temp = wordDict[0][0];
        idxMap[temp].first = 0;
        for (int i = 0; i < wordDict.size(); i++) {
            char c = wordDict[i][0];
            if (c == temp) {
                idxMap[c].second++;
            } else {
                idxMap[c].first = i;
                idxMap[c].second++;
                temp = c;
            }
        }

        return helper(s, wordDict);
    }
};

int main(){
    // vector<string> dict = {"cats", "dog", "sand", "and", "cat"};
    // Solution s;
    // bool res = s.wordBreak("catsandog", dict);
    vector<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    Solution s;
    bool res = s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", dict);
    // vector<string> dict = {"aaaa", "aa"};
    // Solution s;
    // bool res = s.wordBreak("aaaaaaa", dict);
    return res;
}