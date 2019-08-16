#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n, m;
vector<vector<int> > adj;

int main() {
    cin >> n >> m;

    adj.resize(n + 1, vector<int>(n + 1, (int)(1e9)));
    for(int i = 1; i <= n; ++i) adj[i][i] = 0;

    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = w;
    }

    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(adj[i][k] < (int)(1e9) && adj[k][j] < (int)(1e9)) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            cout << "Distance from " << i << " to " << j << " is " << adj[i][j] << endl;
        }
    }

    return 0;
}

/*
5 6
2 3 2
2 1 5
3 4 7
4 1 9
4 5 2
1 5 1
*/

