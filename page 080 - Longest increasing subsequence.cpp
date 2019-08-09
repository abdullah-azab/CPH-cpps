#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n;
vector<int> a, dp;

int solve1() {
    //O(n ^ 2)
    dp.resize(n, 1);
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int solve2() {
    //O(nlogn)
    set<int> s;
    set<int>::iterator it;
    for(int i = 0; i < n; ++i) {
        it = s.lower_bound(a[i]);
        if(it != s.end()) s.erase(it);
        s.insert(a[i]);
    }
    return (int)s.size();
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout << solve1() << endl;
    cout << solve2() << endl;
    return 0;
}
/*
8
6 2 5 1 7 4 8 3
ans: 4 (2 5 7 8)
*/
