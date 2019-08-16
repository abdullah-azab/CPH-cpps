#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n, m;
vector<vector<pair<int, int> > > adj;

vector<int> dist;
vector<bool> used;
priority_queue<pair<int, int> > q;

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dist.resize(n + 1, (int)(1e9));
    used.resize(n + 1);
    dist[1] = 0;
    q.push({0, 1});

    while(!q.empty()) {
        int v = q.top().second;
        q.pop();

        if(used[v]) continue;
        used[v] = 1;

        for(const pair<int, int>& i : adj[v]) {
            int u = i.first, w = i.second;

            if(dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                q.push({-dist[u], u});
            }
        }
    }

    for(int i = 2; i <= n; ++i) {
        cout << "Distance from 1 to " << i << " is " << dist[i] << endl;
    }

    return 0;
}

/*
5 6
2 3 2
2 1 5
3 4 6
4 1 9
4 5 2
5 1 1
*/

