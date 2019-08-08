/*
n - size of array
complexity: O(nlogn)
*/
#include <bits/stdc++.h>

#define endl '\n'
#define merge abcd

using namespace std;

int n;
vector<int> v, a, b;

void merge(int from, int mid, int to) {
    int sizea = mid - from + 1, sizeb = to - mid;
    for(int i = from; i <= mid; ++i) {
        a[i - from] = v[i];
    }
    for(int i = mid + 1; i <= to; ++i) {
        b[i - mid - 1] = v[i];
    }
    int idxa = 0, idxb = 0, idxv = from;
    while(idxa < sizea && idxb < sizeb) {
        if(a[idxa] < b[idxb]) {
            v[idxv++] = a[idxa++];
        } else {
            v[idxv++] = b[idxb++];
        }
    }
    while(idxa < sizea) {
        v[idxv++] = a[idxa++];
    }
    while(idxb < sizeb) {
        v[idxv++] = b[idxb++];
    }
}

void merge_sort(int from, int to) {
    if(from == to) return;
    int mid = (from + to) >> 1;
    merge_sort(from, mid);
    merge_sort(mid + 1, to);
    merge(from, mid, to);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    a.resize(n);
    b.resize(n);
    merge_sort(0, n - 1);
    for(int i : v) {
        cout << i << ' ';
    }
    cout << endl;
	return 0;
}
/*
8
1 3 6 2 8 2 5 9
*/
