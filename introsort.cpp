#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &A, int N) {
    for (int i = 1; i < N; ++i) {
        int v = A[i];
        int j = i;
        for (; j > 0; --j) {
            if (A[j - 1] > v)
                A[j] = A[j - 1];
            else
                break;
        }
        A[j] = v;
    }
}

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

void heapsort(vector<int> &A, int N) {
    for (int i = N / 2 - 1; i >= 0; --i) heapify(A, N, i);

    for (int i = N - 1; i > 0; --i) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int findPivot(vector<int> &A, int begin, int middle, int end) {
    int a = A[begin];
    int b = A[middle];
    int c = A[end];

    if (a <= b && b <= c) {
        return b;
    }
    if (c <= b && b <= a) {
        return b;
    }
    if (b <= a && a <= c) {
        return a;
    }
    if (c <= a && a <= b) {
        return a;
    }
    if (b <= c && c <= a) {
        return c;
    }
    if (a <= c && c <= b) {
        return c;
    }
    return 0;
}

int partition(vector<int> &A, int begin, int end) {
    int x = A[end];
    int i = begin - 1;
    for (int j = begin; j <= end - 1; j++) {
        if (A[j] < x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[end]);
    return i + 1;
}

void _introsort(vector<int> &A, int begin, int end, int depth_limit) {
    int n = end - begin;
    if (n < 16) {
        insertionSort(A, A.size());
        return;
    } else {
        if (depth_limit == 0) {
            heapsort(A, A.size());
            return;
        }
        int pivot = findPivot(A, begin, ((end - begin) / 2) - 1, end);
        swap(A[pivot], A[end]);
        int p = partition(A, begin, end);
        _introsort(A, begin, p - 1, depth_limit - 1);
        _introsort(A, p + 1, end, depth_limit - 1);
    }
}

void introsort(vector<int> &A, int N) {
    int depth_limit = 2 * int(log(double(N)));
    _introsort(A, 0, N - 1, depth_limit);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    introsort(A, N);
    for (int i = 0; i < N; i++) cout << A[i] << " ";
    cout << endl;
}
