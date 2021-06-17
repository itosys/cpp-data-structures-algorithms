#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)

void quickSort(vector<int> &a, int left, int right) {
    if (right - left <= 1) return;
    int pivot_index = rand() % a.size();
    int pivot = a[pivot_index];
    swap(a[pivot_index], a[right - 1]);
    int i = left;
    rep(j, left, right - 1) if (a[j] < pivot) swap(a[i++], a[j]);
    swap(a[i], a[right - 1]);
    quickSort(a, left, i);
    quickSort(a, i + 1, right);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    quickSort(A, 0, N);
    for (int a : A) cout << a << " ";
    cout << endl;
}
