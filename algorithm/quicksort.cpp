/*
 * 快速排序的实现
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 基本快排：把等于切分元素的所有元素分到了数组的同一侧，可能会造成递归树倾斜；
 */
int partition_base(vector<int>& arr, int left, int right) {
    int pivot = left;

    /*
     * 循环不变量
     * all in [left + 1, lt] < arr[pivot]
     * all in [lt + 1, i) >= arr[pivot]
     */
    int lt = left;
    for (int i = left + 1; i <= right; i++) {
        if (arr[i] < arr[pivot]) {
            lt++;
            swap(arr[i], arr[lt]);
        }
    }
    swap(arr[pivot], arr[lt]);
    return lt;
}
void quicksort_base(vector<int>& arr, int left, int right) {
    if (left > right) return;
    int pivot = partition_base(arr, left, right);
    quicksort_base(arr, left, pivot - 1);
    quicksort_base(arr, pivot + 1, right);
}

/*
 * 基础快排存在问题：单纯地把小于基点的元素放在基点左边，大于等于基点的元素放在基点右边，
 *                  如果数组中含有比较多的重复元素，一次划分成的左右子序列长度严重失衡
 *                  例子：[4, 3, 5, 7, 4, 8, 4, 5, 3, 4, 2]
 *                  一次划分后： [2, 3, 3 , |4 |, 4,8,4,5,5,4,7]
 *
 * 二路快排：通过使重复的元素均匀地分布在基点两边，使得每次划分的两个子序列尽可能平衡
 *          本质上是避免递归树失衡而导致的递归层次过深
 *
 * 同样的例子，一次划分后：[4,3,2,4,3, | 4 | ,8,5,4,7,5]
 */
int partition_two(vector<int>& arr, int left, int right) {
    int pivot = left;
    int lt = left + 1, gt = right;

    /*
     * 循环不变量
     * all in [left + 1, lt) <= arr[pivot]
     * all in (gt, right] >= arr[pivot]
     */
    while (true) {
        while (lt <= right && arr[lt] < arr[pivot]) {
            lt++;
        }
        while (gt >= left && arr[gt] > arr[pivot]) {
            gt--;
        }

        if (lt >= gt) {
            break;
        }

        swap(arr[lt], arr[gt]);
        lt++;
        gt--;
    }
    swap(arr[gt], arr[pivot]);
    return gt;
}
void quicksort_two(vector<int>& arr, int left, int right) {
    if (left > right) return;
    int pivot = partition_two(arr, left, right);
    quicksort_base(arr, left, pivot - 1);
    quicksort_base(arr, pivot + 1, right);
}

/*
 * 二路快排存在问题：在有重复元素的数组中，一次划分后与基点相等的元素并一定全部分布在中间，也就是不在正确的位置上
 *                  例子：[4, 3, 5, 7, 4, 8, 4, 5, 3, 4, 2]
 *                  一次划分后： [4,2,4,4,4,8, | 4 | ,5,7,5,4]
 *                  这次划分以4为基点，但是数组中仅有一个元素4在划分结束后处于正确的位置上，而我们的目标是所有元素4都在正确的位置上
 *                  这样可以尽最大可能减少两个子数组的区间长度，进而减小递归深度。
 *
 * 三路快排：将数组严格划分为三个区域，区域1：小于pivot; 区域2: 等于pivot，
 * 区域3： 大于pivot
 *
 * 同样的例子，一次划分后：[3,3,2, | 4,4,4,4, | 5,8,7,5]
 */
void quicksort_three(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = left;
    /*
     * 循环不变量
     * all in [left + 1, lt] < arr[pivot]
     * all in [lt + 1,  i) == arr[pivot]
     * all in [gt, right] > arr[pivot]
     */
    int lt = left;
    int i = left + 1;
    int gt = right + 1;
    while (i < gt) {
        if (arr[i] < arr[pivot]) {
            lt++;
            swap(arr[lt], arr[i]);
            i++;
        } else if (arr[i] == arr[pivot]) {
            i++;
        } else {
            gt--;
            swap(arr[gt], arr[i]);
        }
    }
    swap(arr[lt], arr[pivot]);

    /*
     * 根据循环不变量得知
     * [lt,gt]之间的元素都等于基点，也就是区间内元素都已经在正确的位置上了，不再需要排序
     * 这很好地减小了两个子数组的区间长度
     */
    quicksort_three(arr, left, lt - 1);
    quicksort_three(arr, gt, right);
}

void quicksort(vector<int>& arr) {
    quicksort_base(arr, 0, arr.size() - 1);
    // quicksort_two(arr, 0, arr.size() - 1);
    // quicksort_three(arr, 0, arr.size() - 1);
}

int main() {
    // int arr[] = {4,1,5,7,3,4,6,5,9,0};
    // vector<int> arr = {4,1,5,7,3,4,6,5,9,0};
    // vector<int> arr = {4, 3, 5, 7, 4, 8, 4, 5, 3, 4, 2};
    vector<int> arr = {4,4,5,7,4,8,4,5,4,4,2};
    // vector<int> arr = {0,1,2,3};
    // int arr[] = {4};

    quicksort(arr);

    for (auto n : arr) {
        cout << n << " ";
    }

    return 0;
}