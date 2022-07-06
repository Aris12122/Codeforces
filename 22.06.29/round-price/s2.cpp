#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back


void solve() {
    int m; cin >> m;
    int k = 1e9;
    while (m < k) {
        k /= 10;
    }
    cout << m - k << endl;    
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
