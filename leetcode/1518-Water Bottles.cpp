/* 1518. 换酒问题
小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。你购入了 numBottles 瓶酒。

如果喝掉了酒瓶中的酒，那么酒瓶就会变成空的。

请你计算 最多 能喝到多少瓶酒。

示例 1：

输入：numBottles = 9, numExchange = 3
输出：13
解释：你可以用 3 个空酒瓶兑换 1 瓶酒。
所以最多能喝到 9 + 3 + 1 = 13 瓶酒。

示例 2：

输入：numBottles = 15, numExchange = 4
输出：19
解释：你可以用 4 个空酒瓶兑换 1 瓶酒。
所以最多能喝到 15 + 3 + 1 = 19 瓶酒。

示例 3：

输入：numBottles = 5, numExchange = 5
输出：6
示例 4：

输入：numBottles = 2, numExchange = 3
输出：2
 
提示：

1 <= numBottles <= 100
2 <= numExchange <= 100 */


/*
* 模拟法 O(b/e)
*/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n = 0, empty = 0;
        while((numBottles + empty) >= numExchange){
            // 喝光，多出来numBottles个空瓶
            n += numBottles;
            empty += numBottles;
            // 把空瓶换成酒
            numBottles = empty / numExchange;
            // 多出来的空瓶
            empty = empty % numExchange;
        }
        return n + numBottles;
    }
};


/*
* https://leetcode-cn.com/problems/water-bottles/solution/huan-jiu-wen-ti-by-leetcode-solution/
* 数学法 O(1)
* 设初始有b瓶酒，可用e个空瓶交换一瓶酒，n为兑换次数。那么最终答案应该是 b + n
* 第一步：把b瓶酒喝完，获得b个空瓶
* 第二步：每次用e个空瓶换一瓶酒，这瓶酒喝完后变成一个空瓶，也就是：每次兑换后，手上都消耗了e-1个空瓶，n次兑换后，剩下 b - n*(e-1)个空瓶
*        反复兑换，直到： b - n*(e-1) < e 成立时，停止兑换。要求得最小的n，即求 ((b-e) / (e-1)) + 1
*/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles >= numExchange ? (numBottles - numExchange) / (numExchange - 1) + 1 + numBottles : numBottles;
    }
};