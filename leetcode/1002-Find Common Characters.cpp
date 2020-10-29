/* 1002. 查找常用字符
给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。

 

示例 1：

输入：["bella","label","roller"]
输出：["e","l","l"]
示例 2：

输入：["cool","lock","cook"]
输出：["c","o"] */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> results;

        unordered_map<char, int> mapA;
        unordered_map<char, int> mapB;

        int size = A.size();
        for(auto c : A[0]){
            mapA[c]++;
        }

        for(int i = 1; i < A.size(); i++){
            for(auto c : A[i]){
                if(mapA[c] != 0){
                    mapB[c] = min(mapA[c], mapB[c] + 1);
                }
            }
            swap(mapA, mapB);
            mapB.clear();
        }

        for(unordered_map<char, int>::iterator iter = mapA.begin(); iter != mapA.end(); iter++){
            if(iter->second > 0){
                string s(1, iter->first);
                for(int i = 0; i < iter->second; i++){
                    results.push_back(s);
                }
            }
        }

        return results;
    }
};