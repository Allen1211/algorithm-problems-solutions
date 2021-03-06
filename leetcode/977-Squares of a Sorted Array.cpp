/* 977. 有序数组的平方
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

 

示例 1：

输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
示例 2：

输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]
 

提示：

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A 已按非递减顺序排序。
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int mid = 0, n = A.size();
        vector<int> result(n);
        while(mid < n && A[mid] < 0) mid++;
        int i = mid - 1, j = mid, k = 0;
        while(i >= 0 && j < n){
            if(abs(A[i]) < A[j]){
                result[k++] = pow(A[i--],2);
            }else {
                result[k++] = pow(A[j++],2);
            }
        }
        while(i >= 0) {
            result[k++] = pow(A[i--],2);
        }
        while(j < n) {
            result[k++] = pow(A[j++],2);
        }
        
        return result;
    }
};