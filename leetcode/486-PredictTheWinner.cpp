/*
486. 预测赢家
给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。

给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。

 

示例 1：

输入：[1, 5, 2]
输出：False
解释：一开始，玩家1可以从1和2中进行选择。
如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2 ）可选。
所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。
因此，玩家 1 永远不会成为赢家，返回 False 。
示例 2：

输入：[1, 5, 233, 7]
输出：True
解释：玩家 1 一开始选择 1 。然后玩家 2 必须从 5 和 7 中进行选择。无论玩家 2 选择了哪个，玩家 1 都可以选择 233 。
     最终，玩家 1（234 分）比玩家 2（12 分）获得更多的分数，所以返回 True，表示玩家 1 可以成为赢家。
 

提示：

1 <= 给定的数组长度 <= 20.
数组里所有分数都为非负数且不会大于 10000000 。
如果最终两个玩家的分数相等，那么玩家 1 仍为赢家。
*/


#include <iostream>
#include <vector>

using namespace std;


/**
 * 实现1：递归
 * 每一轮递归返回当前轮次玩家赢过队手的分数
 * 由于两名玩家交替选择，则对于某一轮递归，轮次玩家得分x，对方得分0。这一轮的子递归返回的一定是队手在子问题中赢过他的分数
 * 若该轮选左，则返回的是选左后的子问题队手赢过他的分数；若该轮选右，则返回的是选右后的子问题队手赢过他的分数
 * 算上本轮该轮次玩家赢过对方x分，减去子问题队手赢的分数，是本轮的返回值
 * 
 * 最终返回的是正值，则表明玩家1在整个问题中赢过了玩家2
 */
// int doPlay(vector<int>& nums, int i, int j){
//     if(i == j){     // 只剩下一个，不用选
//         return nums[i];
//     }
//     int left = doPlay(nums, i+1, j);
//     int right = doPlay(nums, i, j-1);
//     return max(nums[i] - left, nums[j] - right);

// }
// bool PredictTheWinner(vector<int>& nums) {
//     int size = nums.size();
//     if(size == 1  || size % 2 == 0){
//         return true;
//     }
//     return doPlay(nums, 0, size -1) >= 0;
// }



/**
 * 实现2：记忆性递归
 * 对于数组 [1,5,233,7]
 * 情况1: 玩家1第一轮选左1，玩家2第一轮选右7；
 * 情况2: 玩家1第一轮选右7，玩家2第一轮选右1；
 * 两种情况的子问题都是[5,233] 导致子问题[5,233]被重复计算了
 * 所以本题可以采用记忆性递归，防止重复计算
 */
// int doPlay(vector<int>& nums, int i, int j, int **memo ){
//     if(memo[i][j] != -1){
//         return memo[i][j];
//     }
//     if(i == j){     // 只剩下一个，不用选
//         memo[i][j] = nums[i];
//         return nums[i];
//     }
//     int left = doPlay(nums, i + 1, j, memo);
//     int right = doPlay(nums, i, j-1, memo);
//     memo[i][j] = max(nums[i] - left, nums[j] - right);
//     return memo[i][j];
// }

// bool PredictTheWinner(vector<int>& nums) {
//     int size = nums.size();
//     int **memo = new int*[size];
//     for (int i = 0; i < size; i++){
//         memo[i] = new int[size]{-1};
//         for(int j=0;j<size;j++){
//             memo[i][j] = -1;
//         }
//     }
//     if(size == 1  || size % 2 == 0){
//         return true;
//     }
//     return doPlay(nums, 0, size -1, memo) >= 0;
// }


/**
 * 实现3：动态规划
 * https://leetcode-cn.com/problems/predict-the-winner/solution/shou-hua-tu-jie-san-chong-xie-fa-di-gui-ji-yi-hua-/
 */
bool PredictTheWinner(vector<int>& nums) {
    int size = nums.size();
    if(size == 1  || size % 2 == 0){
        return true;
    }
    
    int **dp = new int*[size];
    for (int i = 0; i < size; i++){
        dp[i] = new int[size];
    }
    for (int i = 0; i < size; i++){
        dp[i][i] = nums[i];
    }
    for (int i = size-2; i >= 0; i--){
        for (int j = i+1; j < size; j++){
            dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
        }
    }
    
    return dp[0][size-1] >= 0;
}

int main(){
    vector<int> nums1 = {1,3,5,7};
    vector<int> nums2 = {10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000,10000000};
    vector<int> nums3 = {1, 1, 1};
    vector<int> nums4 = {1, 5, 233, 7};
    vector<int> nums5 = {1, 5, 2};    
    cout << PredictTheWinner(nums1) << endl;
    cout << PredictTheWinner(nums2) << endl;
    cout << PredictTheWinner(nums3) << endl;
    cout << PredictTheWinner(nums4) << endl;
    cout << PredictTheWinner(nums5) << endl;
}