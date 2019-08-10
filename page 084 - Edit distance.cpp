/*
insert, remove, modify
*/
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    string a, b;
    int n, m;

    cin >> a >> b;
    n = (int)a.size();
    m = (int)b.size();

    vector<vector<int> > dp(n, vector<int>(m, INT_MAX));

    dp[0][0] = (a[0] == b[0] ? 0 : 1);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            if(j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            if(i && j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i] == b[j] ? 0 : 1));
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}
/*
LOVE MOVIE - 2
sunday saturday - 3
*/
