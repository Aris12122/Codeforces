#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

using ll = long long;


bool is_valid(ll x) {
    while (x > 0) {
        if (x % 10 == 4) return false;
        x /= 10;
    }
    return true;
}

void solve() {
    ll k; cin >> k;
    for (ll i = 1; k > 0; ++i) {
        if (is_valid(i)) {
            if (--k == 0) {
                cout << i << endl;
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
