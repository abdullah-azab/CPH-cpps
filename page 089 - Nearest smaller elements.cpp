#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    stack<int> s;
    s.push(a[0]);
    for(int i = 1; i < n; ++i) {
        while(!s.empty() && s.top() >= a[i]) {
            s.pop();
        }
        if(s.empty()) {
            cout << a[i] << " doesn't have smaller element to the left" << endl;
        } else {
            cout << a[i] << " -> " << s.top() << endl;
        }
        s.push(a[i]);
    }

    return 0;
}
/*
8
1 3 4 2 5 3 4 2
*/
