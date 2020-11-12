#include <iostream>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int kthPrime(int k) {
    int cnt = 0;
    for (int i = 2;; i++) {
        if (isPrime(i)) {
            cnt++;
        }
        if (cnt == k) {
            return i;
        }
    }
    return -1;
}

int main() {
    cout << kthPrime(1) << endl;
    cout << kthPrime(50000) << endl;

    return 0;
}