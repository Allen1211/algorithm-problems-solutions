/*
 * 基于快速排序实现的快速选择算法，选出数组第k大/小的元素
 *
 */
#include <algorithm>
#include <iostream>

using namespace std;

/*
 * 划分，采用子序列第一个元素作为基点
 */
int partition(int arr[], int left, int right) {
    int pivot = left;
    int i = left + 1, j = right;

    while (i <= j) {
        while (arr[i] < arr[pivot]) i++;
        while (arr[j] > arr[pivot]) j--;

        if (i < j) {
            swap(arr[i], arr[j]);
        } else {
            i++;
        }
    }
    swap(arr[j], arr[pivot]);
    return j;
}

int quickselect(int arr[], int k, int left, int right) {
    // 基准数位置
    int pivot = partition(arr, left, right);

    // 如果基准数就是处于第k个的位置，那么该数就是第k小的数
    if (pivot == k - 1) {
        return arr[pivot];
    }

    // 如果基准数位置比k小，递归右子序列，否则递归左子序列
    return pivot < k ? quickselect(arr, k, pivot + 1, right)
                     : quickselect(arr, k, left, pivot - 1);
}

int quickselect(int arr[], int k, int n) { return quickselect(arr, k, 0, n); }

int main() {
    int arr[] = {4, 1, 5, 7, 3, 4, 6, 5, 9, 0};

    cout << quickselect(arr, 8, 10);

    return 0;
}