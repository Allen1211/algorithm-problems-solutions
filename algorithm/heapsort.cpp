#include <iostream>
#include <vector>

using namespace std;

// 这里的比较是优先度的比较，当v1的优先度低于v2时，返回true
// 若为大根堆，则大的元素优先度高，即return v1 <= v2；反之同理
bool lessThen(int v1, int v2) { return v1 <= v2; }

// 上浮
void swim(vector<int>& heap, int k) {
    while (k > 0 && heap[k] > heap[(k - 1) / 2]) {
        swap(heap[k], heap[(k - 1) / 2]);
        k = (k - 1) / 2;
    }
}

// 下沉reheapify算法
void sink(vector<int>& heap, int k, int N) {
    while (2 * k + 1 < N) {
        int j = 2 * k + 1;
        if (j + 1 <= N && lessThen(heap[j], heap[j + 1])) {
            j++;
        }
        if (!lessThen(heap[k], heap[j])) {
            break;
        }
        swap(heap[k], heap[j]);
        k = j;
    }
}

// 堆排序
void heapsort(vector<int>& arr) {
    int N = arr.size();
    // 自底向上地构造堆
    for (int k = N / 2; k >= 0; k--) {
        sink(arr, k, N);
    }
    // 相当于进行N次removeMax操作
    while (--N > 0) {
        swap(arr[0], arr[N]);
        sink(arr, 0, N);
    }
}

void print(vector<int>& arr){
    for(auto &n : arr){
        cout << n << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {2,7,26,25,19,17,1,90,3,36};

    heapsort(arr);

    print(arr);

    return 0;
}