#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    int n, sum;
    cin >> n >> sum;

    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int l = 0, r = 0, current_sum = v[0];
    while(r < n) {
        if(current_sum == sum) {
            cout << "From index " << l << " to index " << r << endl;
            return 0;
        } else if(current_sum < sum) {
            current_sum += v[++r];
        } else {
            current_sum -= v[l++];
            if(l > r) {
                r++;
                if(l < n) current_sum += v[l];
            }
        }
    }

    cout << "No such sum" << endl;

    return 0;
}
/*
8 8
1 3 2 5 1 1 2 3
*/
