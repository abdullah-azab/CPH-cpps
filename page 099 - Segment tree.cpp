#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int nn;
vector<int> a;

struct SEGMENT_TREE { //0 base [0, n - 1]
    vector<int> tree, lazy;
    int n;

    void init(int _size) {
        n = _size;
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }

    void build() {
        _build(1, 0, n);
    }

    void _build(int node, int l, int r) {
        if(l + 1 == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1, F = node << 1, S = (node << 1) | 1;
        _build(F, l, mid);
        _build(S, mid, r);
        tree[node] = tree[F] + tree[S];
    }

    void push(int node, int l, int r) {
        if(lazy[node]) {
            tree[node] += (r - l) * lazy[node];
            if(l + 1 != r) {
                lazy[node << 1] += lazy[node];
                lazy[(node << 1) | 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int from, int to, int val) {
        _update(1, 0, n, from, to + 1, val);
    }

    void _update(int node, int l, int r, int from, int to, int val) {
        push(node, l, r);
        if(l >= to || r <= from) return;
        if(from <= l && r <= to) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) >> 1, F = node << 1, S = (node << 1) | 1;
        _update(F, l, mid, from, to, val);
        _update(S, mid, r, from, to, val);
        tree[node] = tree[F] + tree[S];
    }

    int query(int from, int to) {
        return _query(1, 0, n, from, to + 1);
    }

    int _query(int node, int l, int r, int from, int to) {
        push(node, l, r);
        if(l >= to || r <= from) return 0;
        if(from <= l && r <= to) {
            return tree[node];
        }
        int mid = (l + r) >> 1, F = node << 1, S = (node << 1) | 1;
        int ans1 = _query(F, l, mid, from, to);
        int ans2 = _query(S, mid, r, from, to);
        return ans1 + ans2;
    }
};

int main() {
    cin >> nn;
    a.resize(nn);
    for(int i = 0; i < nn; ++i) {
        cin >> a[i];
    }

    SEGMENT_TREE s;
    s.init(nn);
    s.build();

    int q;
    cin >> q;

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            s.update(l - 1, r - 1, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << s.query(l - 1, r - 1) << endl;
        }
    }

    return 0;
}

/*
6
1 2 3 4 5 6
9
2 1 6
2 1 5
2 1 1
2 6 6
1 1 3 2
2 1 6
2 1 5
2 1 1
2 6 6
*/
