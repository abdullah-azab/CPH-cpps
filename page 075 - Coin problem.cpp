#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int max_n = 1024;

int n, k;
vector<int> c;

bool used[max_n];
int ans[max_n];

int solve_recurse(int N) {
    if(N == 0) return 0;
    if(used[N]) return ans[N];

    int best_ans = INT_MAX;
    for(int i : c) {
        if(N >= i) {
            best_ans = min(best_ans, solve_recurse(N - i) + 1);
        }
    }

    used[N] = 1;
    return ans[N] = best_ans;
}

int solve_iteratively(int N) {
    ans[0] = 0;
    for(int i = 1; i <= N; ++i) {
        ans[i] = INT_MAX;
        for(int j : c) {
            if(i >= j) {
                ans[i] = min(ans[i], ans[i - j] + 1);
            }
        }
    }
    return ans[N];
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        c.push_back(x);
    }
    cout << solve_recurse(n) << endl;
    cout << solve_iteratively(n) << endl;
    return 0;
}
/*
10 3
1 3 4
*/
