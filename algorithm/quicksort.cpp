/*
 * 快速排序的实现
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
        }else {
            i++;
        }
    }
    swap(arr[j], arr[pivot]);
    return j;
}

void quicksort(int arr[], int left, int right) {
    if (left > right) return;
    int pivot = partition(arr, left, right);
    quicksort(arr, left, pivot - 1);
    quicksort(arr, pivot + 1, right);
}

void quicksort(int arr[], int n) { quicksort(arr, 0, n); }


int main(){
    int arr[] = {4,1,5,7,3,4,6,5,9,0};

    quicksort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}