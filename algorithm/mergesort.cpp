#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, vector<int>& subA, vector<int>& subB);

void mergesort(vector<int>& arr) {
    if (arr.size() > 1) {
        int mid = arr.size() / 2;
        vector<int> subA(arr.begin(), arr.begin() + mid);
        vector<int> subB(arr.begin() + mid, arr.end());
        mergesort(subA);
        mergesort(subB);
        merge(arr, subA, subB);
    }
}

void merge(vector<int>& arr, vector<int>& subA, vector<int>& subB) {
    int i = 0, j = 0, k = 0;
    while (i < subA.size() && j < subB.size()) {
        if (subA[i] < subB[j]) {
            arr[k++] = subA[i++];
        } else {
            arr[k++] = subB[j++];
        }
    }
    while (i < subA.size()) arr[k++] = subA[i++];
    while (j < subB.size()) arr[k++] = subB[j++];
}

void mergesort_iter(vector<int>& arr) {
    vector<int> temp(arr.size());
    int n = arr.size();
    for (int seg = 1; seg < n; seg += seg) {
        for (int begin = 0; begin < n; begin += 2 * seg) {
            int k = begin;
            int i = begin, j = min(i + seg, n);
            int iend = min(i + seg, n), jend = min(j + seg, n);
            while (i < iend && j < jend) {
                if (arr[i] < arr[j]) {
                    temp[k++] = arr[i++];
                } else {
                    temp[k++] = arr[j++];
                }
            }
            while (i < iend) temp[k++] = arr[i++];
            while (j < jend) temp[k++] = arr[j++];
        }
        swap(arr, temp);
    }
}

void print(vector<int> v) {
    for (auto i : v) {
        cout << i << ",";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> arrs;

    // arrs.push_back({});
    arrs.push_back({2, 4, 8, 5, 1, 9, 3});
    arrs.push_back({2, 6, 8, 5, 1, 9, 3, 0});
    arrs.push_back({2});
    arrs.push_back({2, 4});
    arrs.push_back({5, 2, 3});
    arrs.push_back({1, 2, 3, 4, 5, 6, 7, 8});
    arrs.push_back({1, 1, 1, 1, 1, 1});

    for (auto arr : arrs) {
         mergesort_iter(arr);
        print(arr);
    }

    return 0;
}