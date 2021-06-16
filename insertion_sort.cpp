// 配列が N, N-1, ... 1 と降順なとき、各要素を左へ動かす回数はそれぞれ
// 0, 1, ..., N-1回なので総和は 1/2N(N-1) => O(N^2) time

#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &a) {
    int N = a.size();
    for (int i = 1; i < N; ++i) {
        int v = a[i];
        int j = i;  // vを挿入する場所j
        for (; j > 0; --j) {
            if (a[j - 1] > v) {
                a[j] = a[j - 1];
            } else break;
        }
        a[j] = v;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    InsertionSort(a);
    for (int i = 0; i < N; ++i) cout << a[i] << " ";
    cout << endl;
}
