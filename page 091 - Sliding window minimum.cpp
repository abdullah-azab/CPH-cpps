#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    deque<pair<int, int> > q;
    for(int i = 0; i < k; ++i) {
        while(!q.empty() && q.back().first > a[i]) {
            q.pop_back();
        }
        q.push_back({a[i], i});
    }
    cout << "First minimum is " << q.front().first << endl;

    for(int i = k; i < n; ++i) {
        while(!q.empty() && q.front().second <= i - k) {
            q.pop_front();
        }
        while(!q.empty() && q.back().first > a[i]) {
            q.pop_back();
        }
        q.push_back({a[i], i});
        cout << "Next minimum is " << q.front().first << endl;
    }

    return 0;
}

/*
8 4
2 1 4 5 3 4 1 0
*/
