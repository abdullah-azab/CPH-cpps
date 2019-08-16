#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n, max_dist, nxt, last;
vector<vector<int> > adj;
vector<int> dist;

void dfs(int u, int v) {
    dist[u] = dist[v] + 1;

    for(const int& i : adj[u]) {
        if(i != v) {
            dfs(i, u);
        }
    }
}

int main() {
    cin >> n;

    adj.resize(n + 1);
    dist.resize(n + 1);

    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dist[0] = -1;
    dfs(1, 0);
    for(int i = 1; i <= n; ++i) {
        if(dist[i] > max_dist) {
            max_dist = dist[i];
            nxt = i;
        }
    }

    dist[0] = -1;
    dfs(nxt, 0);
    max_dist = 0;
    for(int i = 1; i <= n; ++i) {
        if(dist[i] > max_dist) {
            max_dist = dist[i];
            last = i;
        }
    }

    cout << "Diameter is " << max_dist << " from " << nxt << " to " << last << endl;

    return 0;
}

/*
7
6 2
5 2
1 2
1 3
1 4
4 7
*/

