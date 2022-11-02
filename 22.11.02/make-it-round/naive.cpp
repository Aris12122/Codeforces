#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back

using ll = long long;

int zeros(long long x) {
    int res = 0;
    while (x > 0 && x % 10 == 0) {
        x /= 10;
        res++;
    }
    return res;
}

void solve() {
    ll n,m; cin >> n >> m;
    int mx = 0;
    ll ans = n * m;
    for (ll k = 1; k <= m; ++k) {
        if (zeros(k * n) >= mx) {
            mx = zeros(k * n);
            ans = n * k;
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}
