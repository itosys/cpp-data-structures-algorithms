#include <bits/stdc++.h>
using namespace std;

// i: 未ソート部分の先頭を指すループ変数
// j: 未ソート部分の隣り合う要素を比較するためのループ変数
void bubbleSort(vector<int> &A, int N) {
    bool flag = true;
    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = N - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = true;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    bubbleSort(A, N);
    for (int i = 0; i < N; i++) cout << A[i] << " ";
    cout << endl;
}
