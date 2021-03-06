/* 685. 冗余连接 II
在本问题中，有根树指满足以下条件的有向图。该树只有一个根节点，所有其他节点都是该根节点的后继。每一个节点只有一个父节点，除了根节点没有父节点。

输入一个有向图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N)
的树及一条附加的边构成。附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。 每一个边 的元素是一对 [u,
v]，用以表示有向图中连接顶点 u 和顶点 v 的边，其中 u 是 v 的一个父节点。

返回一条能删除的边，使得剩下的图是有N个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。

示例 1:

输入: [[1,2], [1,3], [2,3]]
输出: [2,3]
解释: 给定的有向图如下:
  1
 / \
v   v
2-->3
示例 2:

输入: [[1,2], [2,3], [3,4], [4,1], [1,5]]
输出: [4,1]
解释: 给定的有向图如下:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
注意:

二维数组大小的在3到1000范围内。
二维数组中的每个整数在1到N之间，其中 N 是二维数组的大小。
 */

#include <cstring>
#include <vector>

using namespace std;

class Solution {
   public:
    int* fa;

    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int size = edges.size();

        fa = new int[size + 1];
        for (int i = 0; i <= size; i++) {
            fa[i] = i;
        }

        vector<int> result;

        for (int i = 0; i < size; i++) {
            vector<int> edge = edges[i];
            int x = find(edge[0]);
            int y = find(edge[1]);
            if(x == y){
                result = edge;
            }else {
                fa[x] = y;
            }
        }

        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};

    s.findRedundantDirectedConnection(edges);
}