#include <bits/stdc++.h>
using namespace std;

// i 番目の頂点を根とする部分木についてヒープ条件を満たすようにする
void heapify(vector<int> &A, int N, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < N && A[l] > A[largest]) largest = l;
    if (r < N && A[r] > A[largest]) largest = r;
    if (largest != i) {
        swap(A[i], A[largest]);
        heapify(A, N, largest);
    }
}

void heapSort(vector<int> &A, int N) {
    // A 全体をヒープに
    for (int i = N / 2 - 1; i >= 0; --i) heapify(A, N, i);

    // ヒープから1つずつ最大値をpop
    for (int i = N - 1; i > 0; --i) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    heapSort(A, N);
    for (int i = 0; i < N; i++) cout << A[i] << " ";
    cout << endl;
}
