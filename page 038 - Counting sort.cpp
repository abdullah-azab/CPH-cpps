/*
n - max element in the array
elements - 0 ... n
complexity: O(n)
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n;
vector<int> v, a, sorted_v;

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int max_el = *max_element(v.begin(), v.end());
    a.resize(max_el + 1);
    for(int i = 0; i < n; ++i) {
        a[v[i]]++;
    }
    for(int i = 1; i <= max_el; ++i) {
        a[i] += a[i - 1];
    }
    sorted_v.resize(n);
    for(int i : v) {
        sorted_v[--a[i]] = i;
    }
    for(int i : sorted_v) {
        cout << i << ' ';
    }
    cout << endl;
	return 0;
}
/*
8
1 3 6 2 8 2 5 9
*/
