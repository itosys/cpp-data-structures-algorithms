#include <bits/stdc++.h>
using namespace std;

// 間隔g を指定した挿入ソート
void insertionSort(vector<int> &A, int N, int g) {
    for (int i = g; i < N; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j -= g;
        }
        A[j + g] = v;
    }
}

void shellSort(vector<int> &A, int N) {
    vector<int> G;
    for (int h = 1;;) {
        if (h > N) break;
        G.push_back(h);
        h = 3 * h + 1;
    }
    for (int i = G.size() - 1; i >= 0; --i) insertionSort(A, N, G[i]);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    shellSort(A, N);
    for (int i = 0; i < N; ++i) cout << A[i] << " ";
    cout << endl;
}
