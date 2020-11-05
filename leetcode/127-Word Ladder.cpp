/* 127. 单词接龙
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。 */

#include <queue>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int N = wordList.size();
        
        unordered_set<string> wordSet;
        for (int i = 0; i < N; i++) {
            wordSet.insert(wordList[i]);
        }
        if(wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        int level = 0;
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            int levelSize = q.size();
            while(levelSize-- > 0) {
                string currWord = q.front();q.pop();
                if(currWord == endWord) {
                    return level + 1;
                } 

                for(int i = 0; i < currWord.length(); i++){
                    char orginChar = currWord[i];
                    for(char c='a'; c <= 'z'; c++){
                        currWord[i] = c;
                        if(wordSet.find(currWord) != wordSet.end()) {
                            if(visited.find(currWord) == visited.end()) {
                                visited.insert(currWord);
                                q.push(currWord);
                            }
                        }
                    }
                    currWord[i] = orginChar;
                }
                
            }
            level++;
        }

        return 0;
    }
};

// class Solution {
//    public:
//     int ladderLength(string beginWord, string endWord,
//                      vector<string>& wordList) {
//         wordList.push_back(beginWord);
//         int N = wordList.size();
//         vector<vector<int> > g(N);
//         int start = N - 1, end = -1;
//         for (int i = 0; i < N; i++) {
//             if (wordList[i] == endWord) {
//                 end = i;
//             }
//             for (int j = i + 1; j < N; j++) {
//                 string s1 = wordList[i];
//                 string s2 = wordList[j];
//                 bool hasOneDiff = false;
//                 for (int k = 0; k < s1.length(); k++) {
//                     if (s1[k] != s2[k]) {
//                         if (hasOneDiff) {
//                             hasOneDiff = false;
//                             break;
//                         } else {
//                             hasOneDiff = true;
//                         }
//                     }
//                 }
//                 if (hasOneDiff) {
//                     g[i].push_back(j);
//                     g[j].push_back(i);
//                 }
//             }
//         }

//         if(end == -1) {
//             return 0;
//         }

//         int level = 0;
//         vector<bool> mark(N);
//         queue<int> q;
//         q.push(start);
//         mark[start] = true;
//         while (!q.empty()) {
//             int levelSize = q.size();
//             while(levelSize-- > 0) {
//                 int node = q.front();
//                 q.pop();
//                 if(node == end) {
//                     return level + 1;
//                 } 

//                 vector<int> ajvants = g[node];
//                 for(auto &a : ajvants) {
//                     if(!mark[a]) {
//                         q.push(a);
//                         mark[a] = true;
//                     }
//                 }
//             }
//             level++;
//         }

//         return 0;
//     }
// };


int main() {
    Solution s;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    s.ladderLength("hit", "cog", wordList);
    return 0;
}