#include <bits/stdc++.h>
using namespace std;

// i   : 未ソート部分の先頭を指すループ変数
// minj: 各ループ処理でi番目からN-1番目までの要素で最小のものの位置
// j   : 未ソート部分から最小値の位置(minj)を探すためのループ変数
void selectionSort(vector<int> &A, int N) {
    for (int i = 0; i < N - 1; i++) {
        int minj = i;
        for (int j = i; j < N; j++)
            if (A[j] < A[minj]) minj = j;
        swap(A[i], A[minj]);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    selectionSort(A, N);
    for (int i = 0; i < N; ++i) cout << A[i] << " ";
    cout << endl;
}
