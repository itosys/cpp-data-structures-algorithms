// 配列が N, N-1, ... 1 と降順なとき、各要素を左へ動かす回数はそれぞれ
// 0, 1, ..., N-1回なので総和は 1/2N(N-1) => O(N^2) time

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &A, int N) {
    for (int i = 1; i < N; ++i) {
        int v = A[i];
        int j = i;  // vを挿入する場所j
        for (; j > 0; --j) {
            if (A[j - 1] > v)
                A[j] = A[j - 1];
            else
                break;
        }
        A[j] = v;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    insertionSort(A, N);
    for (int i = 0; i < N; ++i) cout << A[i] << " ";
    cout << endl;
}
