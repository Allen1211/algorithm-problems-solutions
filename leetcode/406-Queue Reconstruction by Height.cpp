/* 406. 根据身高重建队列
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]] */

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    static bool comp(const vector<int>& v1, const vector<int>& v2){
        if(v1[0] < v2[0]){
            return true;
        }else if(v1[0] > v2[0]){
            return false;
        }else {
            return v1[1] < v2[1];
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int size = people.size();
        if(size <= 0){
            return {};
        }
        vector<vector<int>> results(size);
        sort(people.begin(), people.end(), comp);

        vector<int> indexs(size);
        iota(indexs.begin(), indexs.end(), 0);

        int cnt = 0, n = 1;
        for (int i = 0; i < size; i++){
            vector<int> p = people[i];
            if(i != 0 && p[0] == people[i-1][0]){
                cnt = p[1] - n;
                n++;
            }else {
                n = 1;
                cnt = p[1];
            }
            results[indexs[cnt]] = p;
            indexs.erase(indexs.begin() + cnt);
        }

        return results;
    }
};

int main(){
    Solution s;

    // vector<vector<int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    // vector<vector<int>> people = {{7,0}};
    // vector<vector<int>> people = {{7,0},{6,1}};
    vector<vector<int>> people = {{0,0},{6,2},{5,5},{4,3},{5,2},{1,1},{6,0},{6,3},{7,0},{5,1}};

    s.reconstructQueue(people);
}