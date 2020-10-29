/* 1024. 视频拼接
你将会获得一系列视频片段，这些片段来自于一项持续时长为 T
秒的体育赛事。这些片段可能有所重叠，也可能长度不一。

视频片段 clips[i] 都用区间进行表示：开始于 clips[i][0] 并于 clips[i][1]
结束。我们甚至可以对这些片段自由地再剪辑，例如片段 [0, 7] 可以剪切成 [0, 1] +
[1, 3] + [3, 7] 三部分。

我们需要将这些片段进行再剪辑，并将剪辑后的内容拼接成覆盖整个运动过程的片段（[0,
T]）。返回所需片段的最小数目，如果无法完成该任务，则返回 -1 。



示例 1：

输入：clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
输出：3
解释：
我们选中 [0,2], [8,10], [1,9] 这三个片段。
然后，按下面的方案重制比赛片段：
将 [1,9] 再剪辑为 [1,2] + [2,8] + [8,9] 。
现在我们手上有 [0,2] + [2,8] + [8,10]，而这些涵盖了整场比赛 [0, 10]。
示例 2：

输入：clips = [[0,1],[1,2]], T = 5
输出：-1
解释：
我们无法只用 [0,1] 和 [1,2] 覆盖 [0,5] 的整个过程。
示例 3：

输入：clips =
[[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],[2,6],[3,4],[4,5],[5,7],[6,9]],
T = 9 输出：3 解释： 我们选取片段 [0,4], [4,7] 和 [6,9] 。 示例 4：

输入：clips = [[0,4],[2,8]], T = 5
输出：2
解释：
注意，你可能录制超过比赛结束时间的视频。


提示：

1 <= clips.length <= 100
0 <= clips[i][0] <= clips[i][1] <= 100
0 <= T <= 100
*/

#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
   public:

    int videoStitching(vector<vector<int>> &clips, int T) {
        int result = 0;
        vector<int> map(T);
        for(vector<int> &c : clips){
            if(c[0] < T){
                map[c[0]] = max(map[c[0]], c[1]);
            }
        }
        int left = 0, right = 0;
        for(int i = 0; i < T; i++){
            right = max(right, map[i]);
            if(right == i){
                return -1;
            }
            if(i == left) {
                result++;
                left = right;
            }
        }
        return result;
    }
};

class Solution {
   public:
    static bool cmp(const vector<int> &v1, const vector<int> &v2) {
        if (v1[0] == v2[0]) {
            return v1[1] <= v2[1];
        } else {
            return v1[0] <= v2[0];
        }
    }

    int videoStitching(vector<vector<int>> &clips, int T) {
        sort(clips.begin(), clips.end(), cmp);
        int result = 0;
        int right = 0, maxright = 0;
        for (int i = 0; i < clips.size();) {
            if(clips[i][0] > right){
                break;
            }
            while (i < clips.size() && clips[i][0] <= right) {
                if (clips[i][1] > maxright) {
                    maxright = clips[i][1];
                }
                i++;
            }
            if (maxright >= T) {
                return result + 1;
            } else {
                right = maxright;
                result++;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> clips = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    vector<vector<int>> clips1 = {{0,2},{4,8}};
    s.videoStitching(clips1, 5);

    return 0;
}