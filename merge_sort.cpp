#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)

void mergeSort(vector<int> &a, int left, int right) {
    if (right - left == 1) return;
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);

    vector<int> buf;
    rep(i, left, mid) buf.push_back(a[i]);
    rrep(i, right - 1, mid) buf.push_back(a[i]);
    int left_index = 0, right_index = buf.size() - 1;
    rep(i, left, right) {
        if (buf[left_index] <= buf[right_index]) {
            a[i] = buf[left_index++];
        } else {
            a[i] = buf[right_index--];
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    mergeSort(A, 0, N);
    for (int a : A) cout << a << " ";
    cout << endl;
}
