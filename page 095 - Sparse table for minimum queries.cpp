#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int> > dp(n, vector<int>(log2(n) + 1));
    for(int i = 0; i < n; ++i) {
        dp[i][0] = a[i];
    }
    for(int j = 1; j <= log2(n); ++j) {
        for(int i = 0; i + (1 << j) - 1 < n; ++i) {
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int LOG = log2(r - l + 1);
        cout << "Minimum in interval from " << l + 1 << " to " << r + 1 << " is " << min(dp[l][LOG], dp[r - (1 << LOG) + 1][LOG]) << endl;
    }

    return 0;
}
/*
6
2 3 5 4 6 8
3
1 3
4 6
3 4

8
1 3 4 8 6 1 4 2
1
1 6
*/
