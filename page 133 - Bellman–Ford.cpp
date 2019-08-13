#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n, m;
vector<tuple<int, int, int> > edges;
vector<int> dist;

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back(make_tuple(u, v, w));
    }

    dist.resize(n + 1, (int)(1e9));
    dist[1] = 0;

    for(int i = 0; i < n - 1; ++i) {
        for(const tuple<int, int, int>& edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;

            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    for(const tuple<int, int, int>& edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;

        if(dist[v] > dist[u] + w) {
            cout << "Cycle detected!" << endl;
            return 0;
        }
    }

    for(int i = 2; i <= n; ++i) {
        cout << "Distance from 1 to " << i << " is " << dist[i] << endl;
    }

    return 0;
}

/*
5 7
1 2 5
1 3 3
3 4 1
1 4 7
2 4 3
2 5 2
4 5 2

4 5
1 3 5
1 2 3
4 2 1
3 4 -7
2 3 2
*/
