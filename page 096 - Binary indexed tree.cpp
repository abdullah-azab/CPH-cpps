#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct BIT { //base 1
    vector<int> tree;

    void init(int _size) {
        tree.resize(_size + 1);
    }

    void add(int index, int val) {
        for(int i = index; i < (int)tree.size(); i += i & (-i)) {
            tree[i] += val;
        }
    }

    int query(int to) {
        int sum = 0;

        for(int i = to; i >= 1; i -= i & (-i)) {
            sum += tree[i];
        }

        return sum;
    }

    int query_range(int from, int to) {
        return query(to) - query(from - 1);
    }
};

int main() {
    int n;
    cin >> n;

    BIT t;
    t.init(n);

    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        t.add(i, x);
    }

    int q;
    cin >> q;

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int index, val;
            cin >> index >> val;
            t.add(index, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << t.query_range(l, r) << endl;
        }
    }

    return 0;
}

/*
5
1 2 3 4 5
8
2 1 5
2 1 1
2 5 5
2 4 4
1 1 4
2 1 5
2 1 1
2 5 5
*/
