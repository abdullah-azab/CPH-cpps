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

    sort(v.begin(), v.end());

    int l = 0, r = n - 1, current_sum = v[0] + v[n - 1];

    while(l <= r) {
        if(current_sum == sum) {
            cout << "numbers: " << v[l] << " and " << v[r] << endl;
            return 0;
        } else if(current_sum < sum) {
            current_sum -= v[l++];
            current_sum += v[l];
        } else {
            current_sum -= v[r--];
            current_sum += v[r];
        }
    }

    cout << "No such sum" << endl;

    return 0;
}
/*
8 12
1 4 5 6 7 9 9 10
*/
