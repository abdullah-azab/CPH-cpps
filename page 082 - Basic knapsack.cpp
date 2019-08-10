#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> w(n + 1);
    int max_sum = 0;

    for(int i = 1; i <= n; ++i) {
        cin >> w[i];
        max_sum += w[i];
    }

    vector<vector<bool> > dp(max_sum + 1, vector<bool>(n + 1));

    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= max_sum; ++j) {
            dp[j][i] = dp[j][i - 1];
            if(j - w[i] >= 0 && dp[j - w[i]][i - 1]) {
                dp[j][i] = 1;
            }
        }
    }

    for(int i = 0; i <= max_sum; ++i) {
        cout << "sum " << i << " is " << (dp[i][n] ? "possible" : "not possible") << endl;
    }

    return 0;
}
/*
4
1 3 3 5
*/
