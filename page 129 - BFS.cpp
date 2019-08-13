#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<bool> used;
queue<int> q;

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

    q.push(1);
    used[1] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << ' ';

        for(const int& v : adj[u]) {
            if(!used[v]) {
                used[v] = 1;
                q.push(v);
            }
        }
    }

    cout << endl;

    return 0;
}

/*
6 6
4 1
1 2
2 5
2 3
5 6
6 3
*/

