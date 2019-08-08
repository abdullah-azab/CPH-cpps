#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n;
vector<int> v;

inline void naive() {
    //O(n ^ 3)
    int best_ans = INT_MIN;
    for(int from = 0; from < n; ++from) {
        for(int to = from; to < n; ++to) {
            int curr_sum = 0;
            for(int i = from; i <= to; ++i) {
                curr_sum += v[i];
            }
            best_ans = max(best_ans, curr_sum);
        }
    }
    cout << "Naive answer: " << best_ans << endl;
}

inline void improved_naive() {
    //O(n ^ 2)
    vector<int> prefix(n, 0);
    for(int i = 0; i < n; ++i) {
        prefix[i] = v[i];
        if(i) prefix[i] += prefix[i - 1];
    }
    int best_ans = INT_MIN;
    for(int from = 0; from < n; ++from) {
        for(int to = from; to < n; ++to) {
            int curr_sum = prefix[to];
            if(from) curr_sum -= prefix[from - 1];
            best_ans = max(best_ans, curr_sum);
        }
    }
    cout << "Improved naive answer: " << best_ans << endl;
}

inline void fast() {
    //O(n)
    int best_ans = INT_MIN, curr_sum = 0;
    for(int i : v) {
        curr_sum = max(i, curr_sum + i);
        best_ans = max(best_ans, curr_sum);
    }
    cout << "Fast solution answer: " << best_ans << endl;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    naive();
    improved_naive();
    fast();
	return 0;
}
/*
8
-1 2 4 -3 5 2 -5 2
*/
