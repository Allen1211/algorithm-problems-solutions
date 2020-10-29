
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    void print(vector<int> v) {
        for (auto &&i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    int minimumOperations(string leaves) {
        int len = leaves.length();
        int total = 0;
        if (leaves[0] == 'y') {
            total++;
        }
        if (leaves[len - 1] == 'y') {
            total++;
        }

        int begin = 1, end = len - 2;

        while (leaves[begin] == 'r') begin++;
        while (leaves[end] == 'r') end--;

        vector<int> red;
        vector<int> yellow;

        for (int i = begin; i < end;) {
            if (leaves[i] == 'r') {
                int cnt = 0;
                while (i < len - 1 && leaves[i] == 'r') {
                    cnt++;
                    i++;
                }
                red.push_back(cnt);
            } else if (leaves[i] == 'y') {
                int cnt = 0;
                while (i < len - 1 && leaves[i] == 'y') {
                    cnt++;
                    i++;
                }
                yellow.push_back(cnt);
            } else {
                i++;
            }
        }

        // print(red);
        // print(yellow);

        int redTotal = 0;
        for (auto &&num : red) {
            redTotal += num;
        }

        int yellowTotal = 0;
        int max = 0;
        for (auto &&num : yellow) {
            if (num > max) max = num;
            yellowTotal += num;
        }
        yellowTotal -= max;

        total += min(redTotal, yellowTotal);

        return total;
    }
};

int main() {
    Solution s;
    cout << s.minimumOperations("rrryyyrryyyrr") << endl;
    cout << s.minimumOperations("rrryyrrryyryyyyrrr") << endl;
    cout << s.minimumOperations("rrryyyyrryryyyyrrr") << endl;
    cout << s.minimumOperations("yyyrryyy") << endl;
    cout << s.minimumOperations("yyryyyyr") << endl;
}