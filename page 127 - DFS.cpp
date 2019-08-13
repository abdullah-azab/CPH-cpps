#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<bool> used;

void dfs(int u) {
    cout << u << ' ';
    used[u] = 1;
    for(const int& v : adj[u]) {
        if(!used[v]) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    used.resize(n + 1);

    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    cout << endl;

    return 0;
}
/*
5 5
4 1
1 2
2 3
2 5
5 3
*/
