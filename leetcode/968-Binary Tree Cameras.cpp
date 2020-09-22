/* 968. 监控二叉树
给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。



示例 1：



输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。
示例 2：



输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。
上图显示了摄像头放置的有效位置之一。

提示：

给定树的节点数的范围是 [1, 1000]。
每个节点的值都是 0。 */

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    static const int NO_NEED = 1;   // 表示不需要父结点的监控
    static const int NEED = 2;      // 表示必须要父结点的监控
    static const int CAMERA = 3;    // 表示该子结点装了监控

    int dfs(TreeNode *root, TreeNode *curr, int &cameraNum) {
        // 空结点不需要监控
        if (!curr) {
            return NO_NEED;
        }
        // 叶子结点，他的父结点必须要装监控
        if (!curr->left && !curr->right) {
            return NEED;
        }

        int left = dfs(root, curr->left, cameraNum);
        int right = dfs(root, curr->right, cameraNum);

        // 若有一个子结点表示父结点必须要监控，则装上监控
        if (left == NEED || right == NEED) {
            ++cameraNum;
            return CAMERA;
        }  else {
            // 若有一个子结点装上了监控，该结点不需要父结点的监控
            if (left == CAMERA || right == CAMERA) {
                return NO_NEED;
            }else if(curr != root){ // 否则，如该节点不是根节点(还有父结点)，该结点需要父结点的监控
                return NEED;
            } else {            // 否则，需要父结点的监控
                ++cameraNum;
                return CAMERA;
            }
        }
    }

    int minCameraCover(TreeNode *root) {
        int cameraNum = 0;
        if (dfs(root, root, cameraNum) == NEED) {   // 处理根结点就是唯一结点的特殊情况
            cameraNum++;
        }
        return cameraNum;
    }
};
